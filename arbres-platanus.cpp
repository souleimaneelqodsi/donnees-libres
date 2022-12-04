#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le nombre d'arbres du genre Platanus, et le nombre d'espèces
 *  différentes pour ce genre Platanus, parmi les "arbres remarquables"
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'elle produit bien l'affichage demandé
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("donnees/arbresremarquablesparis.csv", 19);
    vector<vector<string>> platanus = selectLignes(data, 2, "Platanus");
    int nbre_platanus = platanus.size();
    int nbre_especes = distinct(platanus, 3).size();
    cout << "On a " << nbre_platanus << " arbres de genre Platanus parmi les arbres remarquables et on en compte " << nbre_especes << " espèces différentes." << endl;
}

