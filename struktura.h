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

struct Studentas {
     string Vardas="A", Pavarde="B";
   // int *paz;
     vector<int> paz;
    int egz;
    double rez;
    
};
const int Maxpazymiu=10;

void inputas(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
void outputas(const vector<Studentas> &grupe, int pasirinkimas);
int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);
void generavimasSk(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
void generavimasVisko(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);