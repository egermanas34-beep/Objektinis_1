#pragma once
#include "studentas.h"

void inputas(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
void outputas(const vector<Studentas> &grupe, int &pasirinkimas, int &isvedimas);
vector<Studentas> bufer_nusk(const string &read_vardas, int &pasirinkimas);