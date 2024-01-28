#include "Carte.hpp"

using namespace std;

Carte::Carte(ifstream& inputFile) {
  // Vérifier si le fichier est ouvert avec succès
  if (inputFile.is_open()) {
    string ligne;

    // Lire le fichier ligne par ligne
    while (getline(inputFile, ligne)) {
      // Utiliser un flux de chaînes pour extraire les informations
      istringstream flux(ligne);

      // Variables pour stocker les informations extraites
      string data1, data2, data3, data4, data5, data6;
      // Extraire les premiers quatre datas
      flux >> data1 >> data2 >> data3 >> data4 >> data5;

      // Lire la deuxième ligne de la paire
      if (!getline(inputFile, data6)) {
        cerr << "Format du fichier invalide (ligne manquante)." << endl;
        break;
      }

      if (data1 == "ZAU") {
        // Create a new Parcelle object using the values from the match and add it to the vector
        unique_ptr<Parcelle> p = make_unique<ZAU>(stoi(data2), data3, Polygone<int>(data6)); // , stoi(data4)
        parcelles.push_back(move(p));
      } else if (data1 == "ZU") {
          // Create a new Parcelle object using the values from the match and add it to the vector
          unique_ptr<Parcelle> p = make_unique<ZU>(stoi(data2), data3, Polygone<int>(data6), stoi(data4), stoi(data5));
          parcelles.push_back(move(p));
        } else if (data1 == "ZA") {
          // Create a new Parcelle object using the values from the match and add it to the vector
          unique_ptr<Parcelle> p = make_unique<ZA>(stoi(data2), data3, Polygone<int>(data6), data4);
          parcelles.push_back(move(p));
        } else if (data1 == "ZN") {
          // Create a new Parcelle object using the values from the match and add it to the vector
          unique_ptr<Parcelle> p = make_unique<ZN>(stoi(data2), data3, Polygone<int>(data6));
          parcelles.push_back(move(p));
        }
      }

    // Fermer le fichier
    inputFile.close();
  } else {
    cerr << "Impossible d'ouvrir le fichier." << endl;
  }

  // calculate surfaceTotale by adding the surface of every Parcelle object
  this->surfaceTotale = 0;
  for (const auto& parcellePtr : this->parcelles) {
      this->surfaceTotale += (*parcellePtr).getSurface();
  }
}


void Carte::saveCarte(string savePath) {
  ofstream saveFile(savePath);

  // mettre les attributs des parcelles dans la string fileContent
  for (vector<unique_ptr<Parcelle>>::iterator it = this->parcelles.begin(); it < this->parcelles.end(); it++) {
    saveFile << (*it)->getType() << " " << (*it)->getNumero() << " " << (*it)->getProprietaire();

    if ((*it)->getType() == "ZU") {
      saveFile << " " << to_string((*it)->getPConstructible()) << " " << to_string((int)dynamic_cast<ZU &>(*(*it)).getSurfaceConstruite());
    } else if ((*it)->getType() == "ZAU") {
      saveFile << " " << to_string((*it)->getPConstructible());
    } else if ((*it)->getType() == "ZA") {
      saveFile << " " << (dynamic_cast<ZA &>(*(*it))).getCulture();
    }
    saveFile << endl; // next line

    for(int i=0; i<(*it)->getForme().getSommets().size(); i++){ // points
      saveFile << (*it)->getForme().getSommets()[i] << " "; // put the output of Point2D's << operator straight into the file
    }
    saveFile << endl; // next parcelle
  }
  saveFile.close();
}


/* Getters */
const vector<unique_ptr<Parcelle>>& Carte::getParcelles(void) const { return this->parcelles; }

float Carte::getSurfaceTotale(void) const { return this->surfaceTotale; }

/* Setters */
void Carte::setParcelles(vector<unique_ptr<Parcelle>>&& nouvellesParcelles) { this->parcelles = move(nouvellesParcelles); }

void Carte::setSurfaceTotale(float nouvelleSurfaceTotale) { this->surfaceTotale = nouvelleSurfaceTotale; }
