#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche l'année avec le plus de naissances et l'année avec le plus de mariages
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("donnees/statistiques_de_creation_d_actes_d_etat_civil_par_arrondissement.csv", 4);
    vector<vector<string>> data2 = litTableauCSV("donnees/statistiques-des-jours-des-mariages.csv", 3);
    
    // naissances
    vector<vector<string>> lignesnaissance = selectLignes(data, 0, "Naissances");
    int indMaxDeclarations = indiceMax(conversionInt(colonne(data, 3)));
    string annee_max = data[indMaxDeclarations][1];

    // mariages
    int indMaxMariages = indiceMax(conversionInt(colonne(data2, 2)));
    string annee_max2 = data2[indMaxMariages][0];
    
    // affichages
    
    cout << "L'année où l'on a eu le plus de déclarations de naissance est " << annee_max << endl;
    cout << "L'année où a eu lieu le plus de mariage est " << annee_max2 << endl;
    return 0;
}

