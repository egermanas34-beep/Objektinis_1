#pragma once
#include "bibliotekos.h"

struct Studentas {
  string Vardas="A", Pavarde="B";
  vector<int> paz;
  int egz;
  double vidurkis;
  double mediana;
  double rez;
  string lygis;
};
//sukurti alias StudentuGrupe, kuri galima nuadoti kaip vektoriu, lista arba deque tipo konteineri, tam, kad patikrinti programos sparta, su skirtingo tipo konteineriais.
//using StudentuGrupe = std::vector<Studentas>;  // vector
//using StudentuGrupe = std::list<Studentas>;      // list
using StudentuGrupe = std::deque<Studentas>;   // deque
const int Maxpazymiu=20;
