#pragma once
#include "studentas.h"

void inputas(Studentas &A, StudentuGrupe &grupe, int &pasirinkimas);
void outputas(const StudentuGrupe &vargsiukai, const StudentuGrupe &smartukai, int &pasirinkimas, int &isvedimas, int &m);
StudentuGrupe bufer_nusk(string &read_vardas,int &pasirinkimas, int &m);