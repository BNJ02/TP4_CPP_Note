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
  ZA za(10, "Jiben", Polygone<int>("[-135;75] [-113;50] [-69;115]"), "Blé", 50);
  cout << za << endl;

  
  ifstream inputFile("Parcelles.txt");
  if (inputFile.is_open()) {
    Carte maCarte(inputFile);
    inputFile.close();

    /// Afficher les propriétés de chaque Parcelle spécifique dans le vecteur
    for (const auto& parcelle : maCarte.getParcelles()) {
      cout << *parcelle << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      }
  } else {
    cerr << "Impossible d'ouvrir le fichier." << endl;
  }

  


  /*
  vector<unique_ptr<Parcelle>> parcelles;  // Utilisation de pointeurs intelligents
  
  // Ouvrir le fichier en mode lecture
  ifstream fichier("content.txt");

  // Vérifier si le fichier est ouvert avec succès
  if (fichier.is_open()) {
    string ligne;

    // Lire le fichier ligne par ligne
    while (getline(fichier, ligne)) {
      // Utiliser un flux de chaînes pour extraire les informations
      istringstream flux(ligne);

      // Variables pour stocker les informations extraites
      string champ1, champ2, champ3, champ4, champ5, champ6;

      // Extraire les premiers quatre champs
      flux >> champ1 >> champ2 >> champ3 >> champ4 >> champ5;

      // Afficher les informations extraites
      cout << "Champ 1 : " << champ1 << endl;
      cout << "Champ 2 : " << champ2 << endl;
      cout << "Champ 3 : " << champ3 << endl;
      cout << "Champ 4 : " << champ4 << endl;
      cout << "Champ 5 : " << champ5 << endl;

      // Lire la deuxième ligne de la paire
      if (getline(fichier, champ6)) {
        // Afficher la cinquième colonne
        cout << "Champ 6 : " << champ6 << endl << endl;
      } else {
        cerr << "Format du fichier invalide (ligne manquante)." << endl;
        break;
      }

      if (champ1 == "ZAU") {
        // Create a new Parcelle object using the values from the match and add
        // it to the vector
        unique_ptr<Parcelle> p = make_unique<ZAU>(stoi(champ2), champ3, Polygone<int>(champ6)); // , stoi(champ4)
        parcelles.push_back(move(p));
      } else if (champ1 == "ZU") {
          // Create a new Parcelle object using the values from the match and add
          // it to the vector
          unique_ptr<Parcelle> p = make_unique<ZU>(stoi(champ2), champ3, Polygone<int>(champ6), stoi(champ4), stoi(champ5));
          parcelles.push_back(move(p));
        } else if (champ1 == "ZA") {
          // Create a new Parcelle object using the values from the match and add
          // it to the vector
          unique_ptr<Parcelle> p = make_unique<ZA>(stoi(champ2), champ3, Polygone<int>(champ6), champ4);
          parcelles.push_back(move(p));
        } else if (champ1 == "ZN") {
          // Create a new Parcelle object using the values from the match and add
          // it to the vector
          unique_ptr<Parcelle> p = make_unique<ZN>(stoi(champ2), champ3, Polygone<int>(champ6));
          parcelles.push_back(move(p));
        }
      }

    // Fermer le fichier
    fichier.close();
  } else {
    cerr << "Impossible d'ouvrir le fichier." << endl;
  }
  */

  

  // Afficher les propriétés de chaque Parcelle spécifique dans le vecteur
  //for (const auto& parcelle : parcelles) {
  //  cout << *parcelle << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
  //}

  return 0;
}
