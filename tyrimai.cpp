#include "tyrimai.h"


void tyrimasFailoKurimas() {
    vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000}; 

    for (int n : dydziai) 
    {
        string failas = "studentai_" + std::to_string(n) + ".txt";

        auto pradzia = std::chrono::high_resolution_clock::now();
        failuGeneravimas(n);
        auto pabaiga = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> trukme = pabaiga - pradzia;
        cout << failas << " kurimo laikas: " << trukme.count() << " s\n";
    }
}
void tyrimasVisasProcesas() {
    vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000}; 

    for (int n : dydziai) 
    {
        string failas = "studentai_" + std::to_string(n) + ".txt";
        int pasirinkimas = 1;
        int rikiavimo_budas = 3;
        int isvedimas = 2;
        

        auto pradzia = std::chrono::high_resolution_clock::now();
        vector<Studentas> grupe = bufer_nusk(failas, pasirinkimas, n); // Nuskaitome duomenis iš failo
        auto pabaiga1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> trukme = pabaiga1 - pradzia;
        cout << failas << " nuskaitymo ir apdorojimo laikas: " << trukme.count() << " s\n";

        rikiavimas(grupe, rikiavimo_budas); // Rikiuojame pagal galutinį balą
         auto pabaiga2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> rikiavimo_trukme = pabaiga2 - pabaiga1;
        cout << failas << " rikiavimo laikas mazejimo tvarka su sort funkcija: " << rikiavimo_trukme.count() << " s\n";

        vector<Studentas> vargsiukai;
        vector<Studentas> smartukai;
        studentoLygis(grupe, vargsiukai, smartukai); // Skirstome į vargšus ir smartukus
        auto pabaiga3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> studentoLygio_trukme = pabaiga3 - pabaiga2;
        cout << failas << " studentų lygio nustatymo laikas: " << studentoLygio_trukme.count() << " s\n";

        outputas(vargsiukai, smartukai, pasirinkimas, isvedimas, n); // Išvedame į failus
        auto pabaiga4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> isvedimo_trukme = pabaiga4 - pabaiga3;
        cout << failas << " rezultatu isvedimo i faila laikas: " << isvedimo_trukme.count() << " s\n";
        std::chrono::duration<double> visa_trukme = pabaiga4 - pradzia;
        cout<<" \n";
        cout << failas << " visas proceso laikas: " << visa_trukme.count() << " s\n";
            cout << "-------------------------------------------------------------\n";
    }
}