
#include "struktura.h"

//const string failo_vardas = "kursiokai.txt";
//const string failo_vardas = "studentai10000.txt";
//const string failo_vardas = "studentai100000.txt";
const string failo_vardas = "studentai1000000.txt";

int main(){

    Studentas A;
    vector<Studentas> grupe;
    int pasirinkimas = 0;
    cout<<"Ka jus norite padaryti? \n 1 - rankiniu budu ivesti studentus \n 2 - generuoti tik pazymius \n 3 - generuoti vardus su pazymiais \n 4 - nuskaityti is failo \n 5 -baigti darba  \n Pasirinkite: ";
    int veiksmas = skaiciu_mastelis("", 1, 5);
    if(veiksmas==1) inputas(A, grupe, pasirinkimas);
    else if(veiksmas==2) generavimasSk(A, grupe, pasirinkimas);
    else if(veiksmas==3) generavimasVisko(A, grupe, pasirinkimas);
    else if (veiksmas==4) grupe = bufer_nusk(failo_vardas);
    else if(veiksmas==5) return 0;
    
    if (!grupe.empty()) outputas(grupe, pasirinkimas);
    return 0;
}


