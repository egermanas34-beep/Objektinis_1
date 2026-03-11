#pragma once
#include "studentas.h"

void inputas(Studentas &A, vector<Studentas> &grupe, int &pasirinkimas);
void outputas(const vector<Studentas> &grupe, int &pasirinkimas, int &isvedimas, int &m);
vector<Studentas> bufer_nusk(int &pasirinkimas, int &m);