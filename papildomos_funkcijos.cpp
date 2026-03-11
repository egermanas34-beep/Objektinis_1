#include "papildomos.h"
#include "generavimas.h"

void rikiavimas(vector<Studentas> &grupe, int &rik)
{
    if (rik == 1) {
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) //Lambda funkcija, kuri nurodo, kaip rikiuoti studentus pagal vardą
        {
            return a.Vardas > b.Vardas; // Rikiuojame pagal vardą maŽėjimo tvarka
        });
        ///lambda funkcija-galima aprasyti tiesiog toje vietoje, kur jos reikia.
        ///Sintaksė: [capture](parameters) -> return_type { body }
        ///capture - nurodo, kokius kintamuosius iš išorinėsaplinkos lambda funkcija gali naudoti.
        /// parameters - nurodo, kokius parametrus lambda funkcija priima. return_type - nurodo, kokio tipo reikšmę lambda funkcija grąžina. body - tai lambda funkcijos kūnas, kuriame aprašoma, ką ji daro.
    } else if (rik == 2) {
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {
            return a.Pavarde > b.Pavarde; // Rikiuojame pagal pavardę maŽėjimo tvarka
        });
    } else if (rik == 3) {
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) 
        {
            return a.rez > b.rez; // Rikiuojame pagal rezultatą mažėjimo tvarka
        });
    }
}
int skaiciu_mastelis(const string &prompt, int min_val, int max_val)
{
    int value;
    while (true) {
        try 
        {
            cout<<prompt;
            cin >> value;
            if(cin.fail())
            {
                throw std::runtime_error("Įvestas ne skaičius");
            }
            if (value < min_val || value > max_val) {
                throw std::out_of_range("Įvestas skaičius už intervalo ribų");

            }
            return value;
        }
        
        catch(const std::runtime_error& e)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Klaida: "<<e.what()<<". Bandykite dar karta.\n";
                
        }
        catch(const std::out_of_range& e)
        {
            cout<<"Klaida: "<<e.what()<<". Turi būti nuo "<<min_val<<" iki "<<max_val<<".\n";
                
        }
   
    }
    
}
void studentoLygis(vector<Studentas> &grupe)
{
    for (auto &A : grupe) {
        if(A.rez<5.0) A.lygis="vargšiukas";
        else A.lygis="smartas";
    }
}
string vardo_skaitymas(const string &prompt)
{
    string value;
    while (true) {
        try 
        {
            cout<<prompt;
            cin>>value;
            if(cin.fail())
            {
                throw std::runtime_error("Įvesties klaida");

            }

            bool has_alpha = false; // Kintamasis, kuris nurodo, ar įvestyje yra bent viena raidė
            bool all_alnum = true; // Kintamasis, kuris nurodo, ar visi įvesties simboliai yra raidės arba skaičiai

            for(unsigned char ch : value) 
            {
                if(std::isalpha(ch)) // std::isalpha funkcija tikrina, ar simbolis yra raidė
                {
                    has_alpha = true;
                }
                else if(!std::isalnum(ch)) // std::isalnum funkcija tikrina, ar simbolis yra raidė arba skaičius  
                {
                    all_alnum = false;
                    break;
                }
            }
            if(!all_alnum ||!has_alpha)
            {
                throw std::invalid_argument("Turi būti bent viena raidė ir tik raidės bei skaičiai");    

            }
            return value;
        }
            catch(const std::runtime_error& e)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //std::numeric_limits<std::streamsize>::max() - tai funkcija, kuri grąžina didžiausią galimą streamsize reikšmę, kuri yra naudojama kaip argumentas ignore funkcijai, kad būtų ignoruojami visi likę simboliai įvesties sraute iki naujos eilutės simbolio ('\n').
                cout<<"Klaida: "<<e.what()<<". Bandykite dar karta.\n";
                    
            }
            catch(const std::invalid_argument& e)
            {
                cout<<"Klaida: "<<e.what()<<". Bandykite dar karta.\n";
                    
            }
        
    }
}
double skaiciu_skaitymas(const string &prompt, double min_val, double max_val)
{
    double value;
    while (true) {
        try 
        {
            cout<<prompt;
            cin >> value;
            if(cin.fail())
            {
                throw std::runtime_error("Įvestas ne skaičius");
            }
            if (value < min_val || value > max_val) {
                throw std::out_of_range("Įvestas skaičius už intervalo ribų");

            }
            return value;
        }
        
        catch(const std::runtime_error& e)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Klaida: "<<e.what()<<". Bandykite dar karta.\n";
                
        }
        catch(const std::out_of_range& e)
        {
            cout<<"Klaida: "<<e.what()<<". Turi būti nuo "<<min_val<<" iki "<<max_val<<".\n";
                
        }
   
    }
    
}