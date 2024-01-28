/
#include "Carte.hpp"

using namespace std;

// Je modifie ça de mon côté
Carte::Carte(ifstream& inputFile) {
  

  // calculate surfaceTotale by adding the surface of every Parcelle object
  this->surfaceTotale=0;
  vector<Parcelle>::iterator it = this->parcelles.begin();
  for(it; it < this->parcelles.end(); it++){
    this->surfaceTotale+=it->getSurface();
  }
}

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