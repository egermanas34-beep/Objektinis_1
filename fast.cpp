#include "struktura.h"

vector<Studentas> bufer_nusk(const string &read_vardas)
{
    vector<Studentas> grupe;// Sukuriame tuščią studentų grupės vektorių
    std::ifstream open_f(read_vardas);// Atidarome failą skaitymui
    if (!open_f.is_open())
    {
        cout << "Nepavyko atidaryti failo: " << read_vardas << endl;
        return grupe;
    }

    auto start = std::chrono::high_resolution_clock::now();// Pradedame matuoti laiką
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
        A.vidurkis = suma * 1.0 / (A.paz.size() * 1.0) * 0.4 + A.egz * 0.6;

        sort(A.paz.begin(), A.paz.end());
        if (A.paz.size() % 2 == 1) {
            A.mediana = A.paz[A.paz.size() / 2] * 0.4 + A.egz * 0.6;
        } else {
            A.mediana = ((A.paz[A.paz.size() / 2 - 1] + A.paz[A.paz.size() / 2]) / 2.0) * 0.4 + A.egz * 0.6;
        }

        grupe.push_back(A);
    }

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;// Apskaičiuojame, kiek laiko praėjo nuo pradžios iki dabar, ir išsaugome šį laiką diff kintamajame
    //std::chrono::duration<double> yra tipas, kuris saugo laiką sekundėmis kaip double reikšmę, o diff.count() grąžina šią reikšmę, kurią mes išvedame į ekraną
    cout << "Failo nuskaitymas ir apdorojimas uztruko: " << diff.count() << " sekundziu." << endl;
    return grupe;
}