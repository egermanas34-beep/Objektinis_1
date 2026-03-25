#include "bibliotekos.h"
#include "studentas.h"
#include "papildomos.h"
#include "Iv_Isv.h"

StudentuGrupe bufer_nusk(string &read_vardas,int &pasirinkimas, int &m)
{
    StudentuGrupe grupe;// Sukuriame tuščią studentų grupės vektorių
   while(true)
    {
    try
    { m=0;
        
        std::ifstream open_f(read_vardas);// Atidarome failą skaitymui
        if (!open_f.is_open())
        {
            throw std::runtime_error("Nepavyko atidaryti failo " + read_vardas);//jeigu failas nebuvo atidarytas, ismeta klaida
        
        }
       // auto start = std::chrono::high_resolution_clock::now();// Pradedame matuoti laiką
        /* std::chrono::high_resolution_clock::now() funkcija grąžina dabartinį laiką, 
        kuris bus naudojamas vėliau apskaičiuoti, kiek laiko užtruko failo nuskaitymas ir apdorojimas*/
        string eil;// Sukuriame eilutės kintamąjį, kuris bus naudojamas skaityti kiekvieną eilutę iš failo
        std::getline(open_f, eil);// Skaitome pirmąją eilutę, kuri yra antraštė, ir ją ignoruojame

        while (std::getline(open_f, eil)) // Skaitome kiekvieną likusią eilutę iš failo, kol pasiekiame failo pabaigą
        {
            if (eil.empty()) // Tikriname, ar eilutė yra tuščia, ir jei taip, praleidžiame ją
            {
                continue;
            }

            std::stringstream ss(eil);// Sukuriame stringstream objektą, kuris leis mums lengvai išskaidyti eilutę į atskirus žodžius ir skaičius
            Studentas A;
            ss >> A.Vardas >> A.Pavarde;// Skaitome pirmus du žodžius kaip studento vardą ir pavardę
            if (A.Vardas.empty() || A.Pavarde.empty()) 
            {
                continue;
            }

            vector<int> visi_pazymiai;// Sukuriame vektorių, kuris saugos visus pažymius, įskaitant egzaminą
            int pazymys;
            while (ss >> pazymys) 
            {
                visi_pazymiai.push_back(pazymys);// Skaitome visus likusius skaičius kaip pažymius ir pridedame juos į vektorių
            }

            if (visi_pazymiai.size() < 2) // Tikriname, ar yra pakankamai pažymių (bent vienas pažymys ir egzaminas), ir jei ne, praleidžiame šį įrašą
            {
                continue;
            }

            A.egz = visi_pazymiai.back(); // Paskutinis pažymys yra egzaminas, todėl jį išskiriame ir priskiriame studento egzaminui
            visi_pazymiai.pop_back(); // Pašaliname egzaminą iš pažymių vektoriaus, kad liktų tik semestro pažymiai
            A.paz = visi_pazymiai; // Priskiriame likusius pažymius studento pažymių vektoriui

            int suma = 0;
            for (int x : A.paz) //x yra kiekvienas pažymys studento pažymių vektoriuje, ir mes juos sumuojame, kad galėtume apskaičiuoti vidurkį
            {
                suma += x;
            }
        
            if(pasirinkimas == 1) 
            A.rez = suma * 1.0 / (A.paz.size() * 1.0) * 0.4 + A.egz * 0.6; // Apskaičiuojame galutinį rezultatą pagal vidurkį
            else
            {
                sort(A.paz.begin(), A.paz.end()); // Rikiuojame pažymius, kad galėtume rasti medianą
                if (A.paz.size() % 2 == 1) 
                {
                    A.rez = A.paz[A.paz.size() / 2] * 0.4 + A.egz * 0.6; // Jei pažymių skaičius yra nelyginis, mediana yra vidurinis elementas
                } 
                else 
                {
                    A.rez = ((A.paz[A.paz.size() / 2 - 1] + A.paz[A.paz.size() / 2]) / 2.0) * 0.4 + A.egz * 0.6; // Jei pažymių skaičius yra lyginis, mediana yra dviejų vidurinių elementų vidurkis
                }
            }
        
            A.paz.clear(); // Išvalome pažymių vektorių, kad jis būtų tuščias prieš kitą studento įvedimą
            grupe.push_back(A);
             m++;
        }

        //std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;// Apskaičiuojame, kiek laiko praėjo nuo pradžios iki dabar, ir išsaugome šį laiką diff kintamajame
        //std::chrono::duration<double> yra tipas, kuris saugo laiką sekundėmis kaip double reikšmę, o diff.count() grąžina šią reikšmę, kurią mes išvedame į ekraną
        //cout << "Failo nuskaitymas ir apdorojimas uztruko: " << diff.count() << " sekundziu." << endl;
        open_f.close();
        return grupe;
    }   
    catch(const std::runtime_error& e)
    {
        cout<<"Klaida: "<<e.what()<<". Patikrinkite ar failas egzistuoja ir bandykite dar kartą. \n";
       
    }
}
}
void inputas(Studentas &A, StudentuGrupe &grupe, int &pasirinkimas)
{
    int m = 1; // Pradinis studentų kiekis, nustatomas į 1, kad įvesties ciklas prasidėtų
    int k = 1; // Pradinis pažymių kiekis, nustatomas į 1, kad įvesties ciklas prasidėtų
    while (m!=0)
    {
        A.Vardas = vardo_skaitymas("Įveskite studento vardą: ");
        A.Pavarde = vardo_skaitymas("Įveskite studento pavardę: ");
        cout<<"Iš viso gali būti įvesta "<<Maxpazymiu<<" pažymių."<<endl;
        cout<<"Įveskite semestro pažymius : \n";
        int n = 1;
        int temp, sum=0;
        while (k!=0 && n<=Maxpazymiu)
        {
            
            temp = skaiciu_mastelis("Įveskite " + std::to_string(n) + " pažymį : ", 1, 10);
            A.paz.push_back(temp);
            sum+=temp;
           
            cout<<"Jei norite įvesti dar viena pažymį, įveskite 1, jei ne - 0: ";
        
            k=skaiciu_mastelis("", 0, 1);
            
            n++;
        }
        if(pasirinkimas==1 && n<Maxpazymiu) 
        {
            for(int i=0;i<Maxpazymiu-n;i++)
            {
            A.paz.push_back(0);
            }
        }
    
        A.egz = skaiciu_mastelis("Įveskite egzamino pažymį: ", 1, 10);
        if(pasirinkimas == 1)
            A.rez = sum*1.0/(A.paz.size()*1.0)*0.4+A.egz*0.6;
        else
        {
            sort (A.paz.begin(),A.paz.end());
            if(A.paz.size()%2==1) A.rez= A.paz[A.paz.size()/2]*0.4+A.egz*0.6;
            else  A.rez=((A.paz[A.paz.size()/2-1]+A.paz[A.paz.size()/2])/2.0)*0.4+A.egz*0.6;
        }
        grupe.push_back(A);// Pridedame studentą į grupę
        A.paz.clear();// Išvalome pažymių vektorių, kad jis būtų tuščias prieš kitą studento įvedimą
        cout<<"Jei norite ivesti dar viena studenta, iveskite 1, jei ne - 0: ";
        cin>>m;
    }
}
void outputas(const StudentuGrupe &vargsiukai, const StudentuGrupe &smartukai, int &pasirinkimas, int &isvedimas, int &m)
{
    
    auto start = std::chrono::high_resolution_clock::now();// Pradedame matuoti laiką
    /* std::chrono::high_resolution_clock::now() funkcija grąžina dabartinį laiką, 
    kuris bus naudojamas vėliau apskaičiuoti, kiek laiko užtruko failo nuskaitymas ir apdorojimas*/
    if(isvedimas==2)
    {
        std::ofstream out_f("vargsiukai"+std::to_string(m)+".txt");
        std::ofstream out_s("smartukai"+std::to_string(m)+".txt");
        
        if(pasirinkimas==1) 
        {
            out_f << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(vid.):" << '\n';
            out_f << " -------------------------------------------------------------------------------------------------------------------" << '\n';
            out_f << fixed << setprecision(2);
            for (const auto &A : vargsiukai)
            {
                out_f << left << setw(15) << A.Vardas << left << setw(30) << A.Pavarde << left << setw(45) << A.rez << '\n';
               
            }
        }
       else
        {
            out_f << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(med.):" << '\n';
            out_f << " -------------------------------------------------------------------------------------------------------------------" << '\n';
            out_f << fixed << setprecision(2);
            for (const auto &A : vargsiukai)
            {
                out_f << left << setw(15) << A.Vardas << left << setw(30) << A.Pavarde << left << setw(45) << A.rez << '\n';
                
            }
        }
         if(pasirinkimas==1) 
        {
            out_s << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(vid.):" << '\n';
            out_s << " -------------------------------------------------------------------------------------------------------------------" << '\n';
            out_s << fixed << setprecision(2);
            for (const auto &A : smartukai)
            {
                out_s << left << setw(15) << A.Vardas << left << setw(30) << A.Pavarde << left << setw(45) << A.rez << '\n';
               
            }
        }
       else
        {
            out_s << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(med.):" << '\n';
            out_s << " -------------------------------------------------------------------------------------------------------------------" << '\n';
            out_s << fixed << setprecision(2);
            for (const auto &A : smartukai)
            {
                out_s << left << setw(15) << A.Vardas << left << setw(30) << A.Pavarde << left << setw(45) << A.rez << '\n';
                
            }
        }
        
        
       cout<<"Rezultatai išsaugoti failuose vargsiukai"+std::to_string(m)+".txt ir smartukai"+std::to_string(m)+".txt"<<endl;
       std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;// Apskaičiuojame, kiek laiko praėjo nuo pradžios iki dabar, ir išsaugome šį laiką diff kintamajame
        //std::chrono::duration<double> yra tipas, kuris saugo laiką sekundėmis kaip double reikšmę, o diff.count() grąžina šią reikšmę, kurią mes išvedame į ekraną
        cout << "Duomenų išvedimas užtruko: " << diff.count() << " sekundžių." << endl;
        out_f.close();
        out_s.close();
       return;
    }
   

    
    //spausdinti_i_srauta(cout);
     std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;// Apskaičiuojame, kiek laiko praėjo nuo pradžios iki dabar, ir išsaugome šį laiką diff kintamajame
    //std::chrono::duration<double> yra tipas, kuris saugo laiką sekundėmis kaip double reikšmę, o diff.count() grąžina šią reikšmę, kurią mes išvedame į ekraną
    cout << "Duomenų išvedimas užtruko: " << diff.count() << " sekundžių." << endl;
    
}