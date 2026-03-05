#pragma once
#include "studentas.h"


int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);
double skaiciu_skaitymas(const string &prompt, double min_val, double max_val);
void rikiavimas(vector<Studentas> &grupe, int &pasirinkimas);
