#include "generavimas.h"
#include "papildomos.h"

void generavimasSk(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas)
{
    int m = skaiciu_mastelis("Kiek yra studentu? ", 1, 1000);
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
        if(pasirinkimas == 1)
            A.rez=sum*1.0/(A.paz.size()*1.0)*0.4+A.egz*0.6;  
        else
        {
            sort (A.paz.begin(),A.paz.end());
            if(A.paz.size()%2==1) A.rez= A.paz[A.paz.size()/2]*0.4+A.egz*0.6;
            else  A.rez=((A.paz[A.paz.size()/2-1]+A.paz[A.paz.size()/2])/2.0)*0.4+A.egz*0.6;
        }
        grupe.push_back(A);
        A.paz.clear();
    }
}
void generavimasVisko(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas)
{
   mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));// Inicijuojame atsitiktinių skaičių generatorių su dabartiniu laiku 
   //static_cast<long unsigned int> naudojamas norint užtikrinti, kad laiko reikšmė būtų tinkamai konvertuota į generatoriaus sėklą
   uniform_int_distribution<int> dist(0,9);// Sukuriame tolygų skaičių pasiskirstymą nuo 0 iki 9   
   
   string vardai[10]={"Jonas", "Petras", "Ona", "Maryte", "Antanas", "Ieva", "Tomas", "Rasa", "Dainius", "Asta"};
   string pavardes_m[10]={"Pavardaite1", "Pavardaite2", "Pavardaite3", "Pavardaite4", "Pavardaite5", "Pavardaite6", "Pavardaite7", "Pavardaite8", "Pavardaite9", "Pavardaite10"};
   string pavardes_v[10]={"Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"};
    int m = skaiciu_mastelis("Kiek yra studentu? ", 1, 1000);
    cout<<"is viso gali buti ivesta "<<Maxpazymiu<<" pazymiu."<<endl;
    cout<<"kiek pazymiu norite sugeneruoti? "<<endl;
        int n = skaiciu_mastelis("", 1, Maxpazymiu);
    for(int i=0;i<m;i++)
    {
        A.Vardas=vardai[dist(mt)];
        switch(*A.Vardas.rbegin())//pasirenkame pavarde pagal vardo gala
        {
            
            case 's': A.Pavarde=pavardes_v[dist(mt)]; break;
            default: A.Pavarde=pavardes_m[dist(mt)]; break;
        }
        int temp, sum=0;
        for(int ii=0;ii<n;ii++)
        {
            temp = dist(mt)+1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
            cout<<"Sugeneruotas "<<ii+1<<" pazymys: "<<temp<<endl;
            A.paz.push_back(temp);
            sum+=temp;
        }
        
        A.egz = dist(mt)+1; // Generuoja atsitiktinius skaičius nuo 1 iki 10
        cout<<"Sugeneruotas egzamino pazymys: "<<A.egz<<endl;
        if(pasirinkimas == 1)
            A.rez=sum*1.0/(A.paz.size()*1.0)*0.4+A.egz*0.6;  
        else
        {
            sort (A.paz.begin(),A.paz.end());
            if(A.paz.size()%2==1) A.rez= A.paz[A.paz.size()/2]*0.4+A.egz*0.6;
            else  A.rez=((A.paz[A.paz.size()/2-1]+A.paz[A.paz.size()/2])/2.0)*0.4+A.egz*0.6;
        }
        grupe.push_back(A);
        A.paz.clear();
    
    }
}    
