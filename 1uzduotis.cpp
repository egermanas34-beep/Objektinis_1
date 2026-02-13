
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::vector;
using std::fixed;
using std::setprecision;

struct Studentas {
     string Vardas="A", Pavarde="B";
   // int *paz;
     vector<int> paz;
    int egz;
    double rez;
    
};
void inputas(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
void outputas(const vector<Studentas> &grupe, int pasirinkimas);
int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);

int main(){

    Studentas A;
    vector<Studentas> grupe;
    int pasirinkimas;
    inputas(A, grupe, pasirinkimas);
    outputas(grupe, pasirinkimas);
    return 0;
}


void outputas(const vector<Studentas> &grupe, int pasirinkimas)
{if(pasirinkimas==1) {
    for(auto A:grupe){
    cout<<left<<setw(10)<<"Vardas:"<<left<<setw(20)<<"Pavarde:"<<left<<setw(30)<<"Galutinis(vid.):"<<endl;
    cout<<" ----------------------------------------------"<<endl;
    cout<<left<<setw(10)<<A.Vardas<<left<<setw(20)<<A.Pavarde<<left<<setw(30)<<fixed<<setprecision(2)<<A.rez<<endl;}}
else { for(auto A:grupe){
    cout<<left<<setw(10)<<"Vardas:"<<left<<setw(20)<<"Pavarde:"<<left<<setw(30)<<"Galutinis(med.):"<<endl;
    cout<<" ----------------------------------------------"<<endl;
    cout<<left<<setw(10)<<A.Vardas<<left<<setw(20)<<A.Pavarde<<left<<setw(30)<<fixed<<setprecision(2)<<A.rez<<endl;}
    //for(auto a:A.paz){cout<<setw(3)<<a;}

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
void inputas(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas)
{
    int m = skaiciu_mastelis("Kiek studentu yra grupeje: ", 1, 1000);
     pasirinkimas = skaiciu_mastelis("galutinio pazymio skaiciavimui bus naudojamas: \n 1 - vidurkis \n 2 - mediana \n Pasirinkite: ", 1, 2);
    for(int ii=0;ii<m;ii++){
    A.Vardas = vardo_skaitymas("Iveskite studento varda: ");
    A.Pavarde = vardo_skaitymas("Iveskite studento pavarde: ");
    cout<<"Iveskite semestro pazymius : \n";
    int n = skaiciu_mastelis("Kiek pazymiu bus ivesta? ", 1, 100);
    int temp, sum=0;
    for(int i=0;i<n;i++){
        temp = skaiciu_mastelis("Iveskite " + std::to_string(i + 1) + " pazymi is " + std::to_string(n) + ": ", 1, 10);

        A.paz.push_back(temp);
        sum+=temp;
    }
    
    A.egz = skaiciu_mastelis("Iveskite egzamino pazymi: ", 1, 10);
    if(pasirinkimas==1) A.rez=sum*1.0/(A.paz.size()*1.0)*0.4+A.egz*0.6;  
    else {std::sort (A.paz.begin(),A.paz.end());
if(A.paz.size()%2==1) A.rez= A.paz[A.paz.size()/2];
else  A.rez=(A.paz[A.paz.size()/2-1]+A.paz[A.paz.size()/2])/2.0;}
    grupe.push_back(A);
    A.paz.clear();
    }}
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
