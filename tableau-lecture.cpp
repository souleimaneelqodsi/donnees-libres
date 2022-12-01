#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-lecture.hpp"


vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    fichier.open(nom_fichier);
    string data;
    vector<vector<string>> tab_data;
    while(fichier >> data){
        vector<string> data_line = vector<string>(nb_colonnes);
        data_line[0] = data; // insertion de la première donnée, déjà lue
        for(int colonne = 1; colonne < nb_colonnes ; colonne++){
        // on arrête à nb_colonne - 1 car on a déjà récupéré le premier élément dans la boucle while
                fichier >> data;
                data_line[i] = data;
            }
        tab_data.push_back(data_line);
    }
    fichier.close();
    return tab_data;
}

