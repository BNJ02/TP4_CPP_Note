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
  vector<Parcelle> parcelles;
  float surfaceTotale;

public: 
  Carte(ifstream& inputFile);
  void saveCarte(string savePath);
};