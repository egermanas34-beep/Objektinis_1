#pragma once
#include "studentas.h"

void inputas(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
void outputas(const vector<Studentas> &vargsiukai, const vector<Studentas> &smartukai, int &pasirinkimas, int &isvedimas, int &m);
vector<Studentas> bufer_nusk(string &read_vardas,int &pasirinkimas, int &m);