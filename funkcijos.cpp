#include "struktura.h"
void outputas(const vector<Studentas> &grupe, int pasirinkimas)
{
    cout<<left<<setw(10)<<"Vardas:"<<left<<setw(20)<<"Pavarde:"<<left<<setw(30)<<"Galutinis(vid.):"<<left<<setw(40)<<"galutinis(med.):"<<endl;
    cout<<" ----------------------------------------------"<<endl;
    for(auto A:grupe){ 
    cout<<left<<setw(10)<<A.Vardas<<left<<setw(20)<<A.Pavarde<<left<<setw(30)<<fixed<<setprecision(2)<<A.vidurkis<<left<<setw(40)<<A.mediana<<endl;}
    

    
}
int skaiciu_mastelis(const string &prompt, int min_val, int max_val)
{
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {// Tikriname, ar įvyko įvesties klaida
            cin.clear();// Išvalome klaidos būseną
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignoruojame likusius įvesties simbolius
            cout << "Neteisinga ivestis. Iveskite skaiciu.\n";
            continue;       
        }
        if (value < min_val || value > max_val) { // Tikriname, ar įvestas skaičius yra nurodytame intervale
            cout << "Neteisinga ivestis. Turi buti nuo " << min_val << " iki " << max_val << ".\n";
            continue;
        }
        return value;
    }
}
void inputas(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas)
{
    int m = 1; // Pradinis studentų kiekis, nustatomas į 1, kad įvesties ciklas prasidėtų
    int k = 1; // Pradinis pažymių kiekis, nustatomas į 1, kad įvesties ciklas prasidėtų
     pasirinkimas = skaiciu_mastelis("galutinio pazymio skaiciavimui bus naudojamas: \n 1 - vidurkis \n 2 - mediana \n Pasirinkite: ", 1, 2);
    while (m!=0)
    {
        A.Vardas = vardo_skaitymas("Iveskite studento varda: ");
        A.Pavarde = vardo_skaitymas("Iveskite studento pavarde: ");
        cout<<"is viso gali buti ivesta "<<Maxpazymiu<<" pazymiu."<<endl;
        cout<<"Iveskite semestro pazymius : \n";
        int n = 1;
        int temp, sum=0;
        while (k!=0 && n<=Maxpazymiu)
        {
            
            temp = skaiciu_mastelis("Iveskite " + std::to_string(n) + " pazymi : ", 1, 10);
            A.paz.push_back(temp);
            sum+=temp;
           
            cout<<"Jei norite ivesti dar viena pazymi, iveskite 1, jei ne - 0: ";
        
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
    
        A.egz = skaiciu_mastelis("Iveskite egzamino pazymi: ", 1, 10);
        
        A.vidurkis = sum*1.0/(A.paz.size()*1.0)*0.4+A.egz*0.6;
       sort (A.paz.begin(),A.paz.end());
        if(A.paz.size()%2==1) A.mediana= A.paz[A.paz.size()/2]*0.4+A.egz*0.6;
        else  A.mediana=((A.paz[A.paz.size()/2-1]+A.paz[A.paz.size()/2])/2.0)*0.4+A.egz*0.6;
        grupe.push_back(A);// Pridedame studentą į grupę
        A.paz.clear();// Išvalome pažymių vektorių, kad jis būtų tuščias prieš kitą studento įvedimą
        cout<<"Jei norite ivesti dar viena studenta, iveskite 1, jei ne - 0: ";
        cin>>m;
    }
}
string vardo_skaitymas(const string &prompt)
{
    string value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) { // Tikriname, ar įvyko įvesties klaida
            cin.clear(); // Išvalome klaidos būseną
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignoruojame likusius įvesties simbolius
            cout << "Neteisinga ivestis. Iveskite raides arba raides su skaiciais.\n";
            continue;
        }
        bool has_alpha = false;// Patikriname, ar yra bent viena raidė
        bool all_alnum = true;// Patikriname, ar visi simboliai yra raidės arba skaičiai
        for (unsigned char ch : value) {
            if (std::isalpha(ch)) {// Jei yra bent viena raidė, nustatome has_alpha į true
                has_alpha = true;
                continue;
            }
            if (!std::isdigit(ch)) {// Jei simbolis nėra nei raidė, nei skaičius, nustatome all_alnum į false ir išeiname iš ciklo
                all_alnum = false;
                break;
            }
        }
        if (!all_alnum || !has_alpha) {// Jei įvestis neteisinga, informuojame vartotoją ir prašome įvesti dar kartą
            cout << "Neteisinga ivestis. Iveskite raides arba raides su skaiciais.\n";
            continue;
        }
        return value;
    }
}
void generavimasSk(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas)
{
    int m = skaiciu_mastelis("Kiek yra studentu? ", 1, 1000);
    pasirinkimas = skaiciu_mastelis("galutinio pazymio skaiciavimui bus naudojamas: \n 1 - vidurkis \n 2 - mediana \n Pasirinkite: ", 1, 2);
    for(int i=0;i<m;i++)
    {
        A.Vardas = vardo_skaitymas("Iveskite studento varda: ");
        A.Pavarde = vardo_skaitymas("Iveskite studento pavarde: ");
        cout<<"is viso gali buti ivesta "<<Maxpazymiu<<" pazymiu."<<endl;
        cout<<"Iveskite semestro pazymius : \n";
        int n = skaiciu_mastelis("Kiek pazymiu norite sugeneruoti? ", 1, Maxpazymiu);
        int temp, sum=0;
        for(int ii=0;ii<n;ii++)
        {
            temp = rand() % 10 + 1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
            cout<<"Sugeneruotas "<<ii+1<<" pazymys: "<<temp<<endl;
            A.paz.push_back(temp);
            sum+=temp;
        }
        if(pasirinkimas==1 && n<Maxpazymiu) 
        {
            for(int ii=0;ii<Maxpazymiu-n;ii++)
            {
            A.paz.push_back(0);
            }
        }
        A.egz = rand() % 10 + 1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
        cout<<"Sugeneruotas egzamino pazymys: "<<A.egz<<endl;
       A.vidurkis=sum*1.0/(A.paz.size()*1.0)*0.4+A.egz*0.6;  
        sort (A.paz.begin(),A.paz.end());
        if(A.paz.size()%2==1) A.mediana= A.paz[A.paz.size()/2]*0.4+A.egz*0.6;
        else  A.mediana=((A.paz[A.paz.size()/2-1]+A.paz[A.paz.size()/2])/2.0)*0.4+A.egz*0.6;
        grupe.push_back(A);
        A.paz.clear();
    }
}
void generavimasVisko(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas)
{
   mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));// Inicijuojame atsitiktinių skaičių generatorių su dabartiniu laiku 
   uniform_int_distribution<int> dist(0,9);// Sukuriame tolygų skaičių pasiskirstymą nuo 0 iki 9   
   
   string vardai[10]={"Jonas", "Petras", "Ona", "Maryte", "Antanas", "Ieva", "Tomas", "Rasa", "Dainius", "Asta"};
   string pavardes_m[10]={"Pavardaite1", "Pavardaite2", "Pavardaite3", "Pavardaite4", "Pavardaite5", "Pavardaite6", "Pavardaite7", "Pavardaite8", "Pavardaite9", "Pavardaite10"};
   string pavardes_v[10]={"Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"};
    int m = skaiciu_mastelis("Kiek yra studentu? ", 1, 1000);
    pasirinkimas = skaiciu_mastelis("galutinio pazymio skaiciavimui bus naudojamas: \n 1 - vidurkis \n 2 - mediana \n Pasirinkite: ", 1, 2);
    for(int i=0;i<m;i++)
    {
        A.Vardas=vardai[dist(mt)];
        switch(*A.Vardas.rbegin())//pasirenkame pavarde pagal vardo gala
        {
            
            case 's': A.Pavarde=pavardes_v[dist(mt)]; break;
            default: A.Pavarde=pavardes_m[dist(mt)]; break;
        }
        cout<<"is viso gali buti ivesta "<<Maxpazymiu<<" pazymiu."<<endl;
        cout<<"kiek pazymiu norite sugeneruoti? "<<endl;
        int n = skaiciu_mastelis("", 1, Maxpazymiu);
        int temp, sum=0;
        for(int ii=0;ii<n;ii++)
        {
            temp = dist(mt)+1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
            cout<<"Sugeneruotas "<<ii+1<<" pazymys: "<<temp<<endl;
            A.paz.push_back(temp);
            sum+=temp;
        }
        if(pasirinkimas==1 && n<Maxpazymiu) 
        {
            for(int i=0;i<Maxpazymiu-n;i++)
            {
            A.paz.push_back(0);
            }
        }
        A.egz = dist(mt)+1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
        cout<<"Sugeneruotas egzamino pazymys: "<<A.egz<<endl;
       A.vidurkis=sum*1.0/(A.paz.size()*1.0)*0.4+A.egz*0.6;  
        sort (A.paz.begin(),A.paz.end());
        if(A.paz.size()%2==1) A.mediana= A.paz[A.paz.size()/2]*0.4+A.egz*0.6;
        else  A.mediana=((A.paz[A.paz.size()/2-1]+A.paz[A.paz.size()/2])/2.0)*0.4+A.egz*0.6;
        grupe.push_back(A);
        A.paz.clear();
    
    }
}    