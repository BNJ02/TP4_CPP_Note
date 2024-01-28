#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>  // Pour std::unique_ptr

#include "za.hpp"
#include "zau.hpp"
#include "zn.hpp"
#include "zu.hpp"

#include "Carte.hpp"

using namespace std;

int main() {
  // Test surcharge << de ZA
  ZA za(10, "Jiben", Polygone<int>("[0;0] [10;0] [10;10] [0;10]"), "Blé", 50);
  cout << za << endl;
  
  ifstream inputFile("Parcelles.txt");
  if (inputFile.is_open()) {
    Carte maCarte(inputFile);
    inputFile.close();

    /// Afficher les propriétés de chaque Parcelle spécifique dans le vecteur
    for (const auto& parcelle : maCarte.getParcelles()) {
      if (parcelle->getType() == "ZU") {
        cout << dynamic_cast<ZU &>(*parcelle) << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      } else if (parcelle->getType() == "ZAU") {
        cout << dynamic_cast<ZAU &>(*parcelle) << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      } else if (parcelle->getType() == "ZA") {
        cout << dynamic_cast<ZA &>(*parcelle) << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      } else if (parcelle->getType() == "ZAU") {
        cout << dynamic_cast<ZN &>(*parcelle) << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      }
    }

    cout << endl << "Surface totale de la carte : " << maCarte.getSurfaceTotale() << endl;

    maCarte.saveCarte("saveFile.txt");
    
  } else {
    cerr << "Impossible d'ouvrir le fichier." << endl;
  }

  return 0;
}
