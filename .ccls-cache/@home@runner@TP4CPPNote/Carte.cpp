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

  /*
  // calculate surfaceTotale by adding the surface of every Parcelle object
  this->surfaceTotale=0;
  vector<unique_ptr<Parcelle>>::iterator it = this->parcelles.begin();
  for(it; it < this->parcelles.end(); it++){
    this->surfaceTotale+=it->getSurface();
  }
  */
}

/*
void Carte::saveCarte(string savePath) {
  ofstream saveFile(savePath);
  string fileContent;

  // mettre les attributs des parcelles dans la string fileContent
  vector<Parcelle>::iterator it = this->parcelles.begin();
  for (it; it < this->parcelles.end(); it++) {
    fileContent += it->getType();
    fileContent += " ";
    fileContent += to_string(it->getNumero());
    fileContent += " ";
    fileContent += it->getProprietaire();

    if (it->getType() == "ZU") {
      fileContent += " ";
      fileContent += to_string(it->getPConstructible());
      fileContent += " ";
      fileContent += dynamic_cast<ZU &>(*it).getSurfaceConstruite();
    } else if (it->getType() == "ZAU") {
      fileContent += " ";
      fileContent += to_string(it->getPConstructible());
    } else if (it->getType() == "ZA") {
      fileContent += " ";
      fileContent += (dynamic_cast<ZA &>(*it)).getCulture();
    }

    fileContent += "\n\r";
    saveFile << fileContent; // puts the content into the file
    for(int i=0; i<4; i++){ // points
      saveFile << it->getForme().getSommets()[i]; // put the output of Point2D's << operator straight into the file
      fileContent += " "; // add space and put it into the file
      saveFile << fileContent;
    }
  }
  saveFile.close();
}
*/

/* Getters */
const vector<unique_ptr<Parcelle>>& Carte::getParcelles(void) const { return this->parcelles; }

/* Setters */
void Carte::setParcelles(vector<unique_ptr<Parcelle>>&& nouvellesParcelles) { this->parcelles = move(nouvellesParcelles); }
