#include "strukturaCmas.h"

int main() {
    Studentas A;
    Studentas grupe[MaxStudentu];
    int pasirinkimas;
    int studentuKiek = 0;
    cout << "Ka jus norite padaryti? \n 1 - rankiniu budu ivesti studentus \n 2 - generuoti tik pazymius \n 3 - generuoti vardus su pazymiais \n 4 - baigti darba  \n Pasirinkite: ";
    int veiksmas = skaiciu_mastelis("", 1, 4);
    if (veiksmas == 1) inputas(A, grupe, pasirinkimas, studentuKiek);
    else if (veiksmas == 2) generavimasSk(A, grupe, pasirinkimas, studentuKiek);
    else if (veiksmas == 3) generavimasVisko(A, grupe, pasirinkimas, studentuKiek);
    else if (veiksmas == 4) return 0;

    outputas(grupe, pasirinkimas, studentuKiek);
    return 0;
}




void inputas(Studentas &A, Studentas grupe[], int &pasirinkimas, int &studentuKiek)
{
    int testi = 1;
    int studentoIndeksas = 0;
    
     pasirinkimas = skaiciu_mastelis("galutinio pazymio skaiciavimui bus naudojamas: \n 1 - vidurkis \n 2 - mediana \n Pasirinkite: ", 1, 2);
    while (testi != 0 && studentoIndeksas < MaxStudentu)
    {
        A.vardas = vardo_skaitymas("Iveskite studento varda: ");
        A.pavarde = vardo_skaitymas("Iveskite studento pavarde: ");
        cout<<"is viso gali buti ivesta "<<MaxPazymiu<<" pazymiu."<<endl;
        cout<<"Iveskite semestro pazymius : \n";
        int n = 1;
        int k = 1;
        int temp, sum=0;
        while (k!=0 && n<=MaxPazymiu)
        {
            
            temp = skaiciu_mastelis("Iveskite " + std::to_string(n) + " pazymi : ", 1, 10);
            A.paz[n-1] = temp;
            sum+=temp;
           
            cout<<"Jei norite ivesti dar viena pazymi, iveskite 1, jei ne - 0: ";
        
            k=skaiciu_mastelis("", 0, 1);
            
            n++;
        }
        A.pazKiek = n-1;
        if(pasirinkimas==1 && n<MaxPazymiu) 
        {
            for(int i=0;i<MaxPazymiu-n;i++)
            {
            A.paz[n+i] = 0;
            }
        }
    
        A.egz = skaiciu_mastelis("Iveskite egzamino pazymi: ", 1, 10);
        if(pasirinkimas==1) A.rez=sum*1.0/(A.pazKiek*1.0)*0.4+A.egz*0.6;  
        else {sort (A.paz, A.paz+A.pazKiek);
        if(A.pazKiek%2==1) A.rez= A.paz[A.pazKiek/2]*0.4+A.egz*0.6;
        else  A.rez=((A.paz[A.pazKiek/2-1]+A.paz[A.pazKiek/2])/2.0)*0.4+A.egz*0.6;}
        
        grupe[studentoIndeksas] = A;
        studentoIndeksas++;
        studentuKiek = studentoIndeksas;
        cout<<"Jei norite ivesti dar viena studenta, iveskite 1, jei ne - 0: ";
        testi = skaiciu_mastelis("", 0, 1);
    }
}
int skaiciu_mastelis(const string &prompt, int min_val, int max_val)

{
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Neteisinga ivestis. Iveskite skaiciu.\n";
            continue;
        }
        if (value < min_val || value > max_val) {
            cout << "Neteisinga ivestis. Turi buti nuo " << min_val << " iki " << max_val << ".\n";
            continue;
        }
        return value;
    }
}
string vardo_skaitymas(const string &prompt)
{
    string value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        if (!all_alnum || !has_alpha) {
            cout << "Neteisinga ivestis. Iveskite raides arba raides su skaiciais.\n";
            continue;
        }
        return value;
    }
}
void outputas(const Studentas grupe[], int pasirinkimas, int studentuKiek)
{
    if (studentuKiek == 0) {
        cout << "Nera ivestu studentu." << endl;
        return;
    }

    if(pasirinkimas==1){
        cout<<left<<setw(10)<<"Vardas:"<<left<<setw(20)<<"Pavarde:"<<left<<setw(30)<<"Galutinis(vid.):"<<endl;
        for (int i = 0; i < studentuKiek; i++) {
            cout<<" ----------------------------------------------"<<endl;
            cout<<left<<setw(10)<<grupe[i].vardas<<left<<setw(20)<<grupe[i].pavarde<<left<<setw(30)<<fixed<<setprecision(2)<<grupe[i].rez<<endl;}}
    else { 
        cout<<left<<setw(10)<<"Vardas:"<<left<<setw(20)<<"Pavarde:"<<left<<setw(30)<<"Galutinis(med.):"<<endl;
        for(int i = 0; i < studentuKiek; i++){
            cout<<" ----------------------------------------------"<<endl;
            cout<<left<<setw(10)<<grupe[i].vardas<<left<<setw(20)<<grupe[i].pavarde<<left<<setw(30)<<fixed<<setprecision(2)<<grupe[i].rez<<endl;}

    }
    
}
void generavimasSk(Studentas &A, Studentas grupe[], int &pasirinkimas, int &studentuKiek)
{
    int m = skaiciu_mastelis("Kiek yra studentu? ", 1, MaxStudentu);
    int studentoIndeksas = 0;
    pasirinkimas = skaiciu_mastelis("galutinio pazymio skaiciavimui bus naudojamas: \n 1 - vidurkis \n 2 - mediana \n Pasirinkite: ", 1, 2);
    for(int i=0;i<m;i++)
    {
        A.vardas = vardo_skaitymas("Iveskite studento varda: ");
        A.pavarde = vardo_skaitymas("Iveskite studento pavarde: ");
        cout<<"is viso gali buti ivesta "<<MaxPazymiu<<" pazymiu."<<endl;
        cout<<"Iveskite semestro pazymius : \n";
        int n = skaiciu_mastelis("Kiek pazymiu norite sugeneruoti? ", 1, MaxPazymiu);
        int temp, sum=0;
        for(int ii=0;ii<n;ii++)
        {
            temp = rand() % 10 + 1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
            cout<<"Sugeneruotas "<<ii+1<<" pazymys: "<<temp<<endl;
            A.paz[ii] = temp;
            sum+=temp;
        }
        A.pazKiek = n;
        if(pasirinkimas==1 && n<MaxPazymiu) 
        {
            for(int ii=n;ii<MaxPazymiu;ii++)
            {
            A.paz[ii] = 0;
            }
        }
        A.egz = rand() % 10 + 1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
        cout<<"Sugeneruotas egzamino pazymys: "<<A.egz<<endl;
        if(pasirinkimas==1) A.rez=sum*1.0/(MaxPazymiu*1.0)*0.4+A.egz*0.6;  
        else {sort (A.paz,A.paz+A.pazKiek);
        if(A.pazKiek%2==1) A.rez= A.paz[A.pazKiek/2]*0.4+A.egz*0.6;
        else  A.rez=((A.paz[A.pazKiek/2-1]+A.paz[A.pazKiek/2])/2.0)*0.4+A.egz*0.6;}
        grupe[studentoIndeksas] = A;
        studentoIndeksas++;
        studentuKiek = studentoIndeksas;
    }
}
void generavimasVisko(Studentas &A, Studentas grupe[], int &pasirinkimas, int &studentuKiek)
{
   mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));// Inicijuojame atsitiktinių skaičių generatorių su dabartiniu laiku 
   uniform_int_distribution<int> dist(0,9);// Sukuriame tolygų skaičių pasiskirstymą nuo 0 iki 9   
   
   string vardai[10]={"Jonas", "Petras", "Ona", "Maryte", "Antanas", "Ieva", "Tomas", "Rasa", "Dainius", "Asta"};
   string pavardes_m[10]={"Pavardaite1", "Pavardaite2", "Pavardaite3", "Pavardaite4", "Pavardaite5", "Pavardaite6", "Pavardaite7", "Pavardaite8", "Pavardaite9", "Pavardaite10"};
   string pavardes_v[10]={"Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"};
    int m = skaiciu_mastelis("Kiek yra studentu? ", 1, 1000);
    int studentoIndeksas = 0;
    pasirinkimas = skaiciu_mastelis("galutinio pazymio skaiciavimui bus naudojamas: \n 1 - vidurkis \n 2 - mediana \n Pasirinkite: ", 1, 2);
    for(int i=0;i<m;i++)
    {
        A.vardas=vardai[dist(mt)];
        switch(*A.vardas.rbegin())//pasirenkame pavarde pagal vardo gala
        {
            
            case 's': A.pavarde=pavardes_v[dist(mt)]; break;
            default: A.pavarde=pavardes_m[dist(mt)]; break;
        }
        cout<<"is viso gali buti ivesta "<<MaxPazymiu<<" pazymiu."<<endl;
        cout<<"kiek pazymiu norite sugeneruoti? "<<endl;
        int n = skaiciu_mastelis("", 1, MaxPazymiu);
        int temp, sum=0;
        for(int ii=0;ii<n;ii++)
        {
            temp = dist(mt)+1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
            cout<<"Sugeneruotas "<<ii+1<<" pazymys: "<<temp<<endl;
            A.paz[ii] = temp;
            sum+=temp;
        }
            A.pazKiek = n;
        if(pasirinkimas==1 && n<MaxPazymiu) 
        {
            for(int ii=n;ii<MaxPazymiu;ii++)
            {
            A.paz[ii] = 0;
            }
        }
        A.egz = dist(mt)+1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
        cout<<"Sugeneruotas egzamino pazymys: "<<A.egz<<endl;
        if(pasirinkimas==1) A.rez=sum*1.0/(MaxPazymiu*1.0)*0.4+A.egz*0.6;  
        else {sort (A.paz,A.paz+A.pazKiek);
        if(A.pazKiek%2==1) A.rez= A.paz[A.pazKiek/2]*0.4+A.egz*0.6;
        else  A.rez=((A.paz[A.pazKiek/2-1]+A.paz[A.pazKiek/2])/2.0)*0.4+A.egz*0.6;}
        grupe[studentoIndeksas] = A;
        studentoIndeksas++;
        studentuKiek = studentoIndeksas;
    
    }
}    