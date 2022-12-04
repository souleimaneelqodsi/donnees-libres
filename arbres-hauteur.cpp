#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le genre et l'espece de l'arbre le plus haut de Paris
 * parmi les "arbres remarquables"
 **/
int main() { 
    vector<vector<string>> data = litTableauCSV("donnees/arbresremarquablesparis.csv", 19);
    cout << "L'arbre le plus haut de Paris parmi les arbres remarquables est : " << endl;
    cout << endl;
    int indMaxHauteur = indiceMax(conversionInt(colonne(data, 12)));
    cout << "  - Nom français : " << data[indMaxHauteur][1] << endl;
    cout << "  - Genre : " << data[indMaxHauteur][2] << endl;
    cout << "  - Espèce : " << data[indMaxHauteur][3] << endl;
    cout << "  - Hauteur : " << conversionInt(colonne(data, 12))[indMaxHauteur] << "m" << endl;
    cout << endl;
    return 0;
}

