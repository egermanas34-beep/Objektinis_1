
#include "struktura.h"



int main(){

    Studentas A;
    vector<Studentas> grupe;
    int pasirinkimas;
    cout<<"Ka jus norite padaryti? \n 1 - rankiniu budu ivesti studentus \n 2 - generuoti tik pazymius \n 3 - generuoti vardus su pazymiais \n 4 - baigti darba  \n Pasirinkite: ";
    int veiksmas = skaiciu_mastelis("", 1, 4);
    if(veiksmas==1) inputas(A, grupe, pasirinkimas);
    else if(veiksmas==2) generavimasSk(A, grupe, pasirinkimas);
    //else if(veiksmas==3) {inputas(A, grupe, pasirinkimas); generavimasSk(A);}
    else if(veiksmas==4) return 0;
    
    outputas(grupe, pasirinkimas);
    return 0;
}


