#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>
#include <random>
#include <chrono>
#include <stdlib.h>
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
using std::mt19937;
using std::uniform_int_distribution;
using std::chrono::high_resolution_clock;
using std::sort;
const int MaxStudentu = 100;
const int MaxPazymiu = 20;

struct Studentas {
    string vardas;
    string pavarde;
    int paz[MaxPazymiu];
    int pazKiek;
    int egz;
    double rez;
};

void inputas(Studentas &A, Studentas grupe[], int &pasirinkimas, int &studentuKiek);
int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);
void outputas(const Studentas grupe[], int pasirinkimas, int studentuKiek);
void generavimasSk(Studentas &A, Studentas grupe[], int &pasirinkimas, int &studentuKiek);
void generavimasVisko(Studentas &A, Studentas grupe[], int &pasirinkimas, int &studentuKiek);