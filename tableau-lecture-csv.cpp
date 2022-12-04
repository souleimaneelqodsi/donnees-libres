#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-lecture-csv.hpp"


vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
    ifstream file;
    file.open(nom_fichier);

    vector<vector<string>> tableau;
    
    string entete;
    getline(file, entete);

    string data; string ligne;
    while(getline(file, ligne)){
        istringstream ligne_actuelle = istringstream(ligne);
        vector<string> dataLine = vector<string>(nb_colonnes);
        for(int i = 0; i < nb_colonnes ; i++){
            getline(ligne_actuelle, data, ';');
            if ( data.size() > 0 and data[data.length()-1] == '\r' ) {
                 data.resize(data.length() - 1);
            }
            dataLine[i] = data;
        }
    tableau.push_back(dataLine);
    }

    file.close();
    return tableau;
}

/**vector<vector<string>> litTableauCSV(string nom_fichier) {
    // Remplacer cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction litTableauCSV non implantée ligne 16");
}**/




