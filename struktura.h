#pragma once
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
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
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
  vector<int> paz;
  int egz;
  double vidurkis;
  double mediana;
  double rez;
};
const int Maxpazymiu=10;


//const string failo_vardas = "kursiokai.txt";
const string failo_vardas = "studentai10000.txt";
//const string failo_vardas = "studentai100000.txt";
//const string failo_vardas = "studentai1000000.txt";

void inputas(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
void outputas(const vector<Studentas> &grupe, int &pasirinkimas, int &isvedimas);
int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);
void generavimasSk(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
void generavimasVisko(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
vector<Studentas> bufer_nusk(const string &read_vardas, int &pasirinkimas);
void rikiavimas(vector<Studentas> &grupe, int &pasirinkimas);
