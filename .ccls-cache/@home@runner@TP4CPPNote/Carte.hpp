#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "Parcelle.hpp"

#include "za.hpp"
#include "zau.hpp"
#include "zn.hpp"
#include "zu.hpp"

using namespace std;

class Carte {
private:
  vector<unique_ptr<Parcelle>> parcelles;  // Utilisation de pointeurs intelligents
  float surfaceTotale;

public: 
  Carte(ifstream& inputFile);
  void saveCarte(string savePath);

  /* Getters */
  const vector<unique_ptr<Parcelle>>& getParcelles(void) const;
  float getSurfaceTotale(void) const;

  /* Setters */
  void setParcelles(vector<unique_ptr<Parcelle>>&& nouvellesParcelles);
  void setSurfaceTotale(float nouvelleSurface);
};