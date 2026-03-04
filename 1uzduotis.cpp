
#include "struktura.h"


int main(){
system("powershell ls studentai*.txt");
   std::ios::sync_with_stdio(false);// Išjungia sinchronizaciją tarp C++ srautų ir C srautų, kad pagerintų įvesties/išvesties našumą
    //std::ios::sync_with_stdio(false) funkcija yra naudojama norint pagerinti įvesties/išvesties našumą,
    // išjungiant sinchronizaciją tarp C++ srautų (std::cin, std::cout) ir C srautų (scanf, printf).
    // Tai leidžia C++ srautams veikti greičiau, nes jie nebėra priversti sinchronizuotis su C srautais.
    // Tačiau tai reiškia, kad negalima naudoti C srautų funkcijų kartu su C++ srautais, nes tai gali sukelti nenumatytų rezultatų,
    // todėl rekomenduojama naudoti tik vieną tipą srautų visame programoje. pvz. jei naudojate std::cout, venkite naudoti printf ir atvirkščiai.
    
    Studentas A;
    vector<Studentas> grupe;
    int pasirinkimas;
    int isvedimas;
    cout<<"Ka jus norite padaryti? \n 1 - rankiniu budu ivesti studentus \n 2 - generuoti tik pazymius \n 3 - generuoti vardus su pazymiais \n 4 - nuskaityti is failo \n 5 -baigti darba  \n Pasirinkite: ";
    int veiksmas = skaiciu_mastelis("", 1, 5);
    if(veiksmas==5) return 0;
    cout<<"Kaip norite apskaiciuoti galutini bala? \n 1 - pagal vidurki \n 2 - pagal mediana \n Pasirinkite: ";
    pasirinkimas = skaiciu_mastelis("", 1, 2);  
    cout<<"Kaip noriti rekiuoti rezultatus? \n 1 - pagal varda \n 2 - pagal pavarde \n 3 - pagal galutini bala \n Pasirinkite: ";
    int rik = skaiciu_mastelis("", 1, 3);
    cout<<"Kaip norite isvesti rezultatus? \n 1 - i ekrana \n 2 - i faila \n Pasirinkite: ";
    isvedimas = skaiciu_mastelis("", 1, 2);
    if(veiksmas==1) inputas(A, grupe, pasirinkimas);
    else if(veiksmas==2) generavimasSk(A, grupe, pasirinkimas);
    else if(veiksmas==3) generavimasVisko(A, grupe, pasirinkimas);
    else if (veiksmas==4) grupe = bufer_nusk(failo_vardas, pasirinkimas);
   
    
    rikiavimas(grupe, rik);
   outputas(grupe, pasirinkimas, isvedimas);
    return 0;
}


