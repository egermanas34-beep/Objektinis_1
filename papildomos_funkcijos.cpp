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
