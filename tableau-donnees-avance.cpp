#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees-avance.hpp"

int chercheIndice(vector<string> t, string valeur) {
    for(int i = 0 ; i < t.size() ; i++){
        if(t[i] == valeur) return i;
    }
        return -1;
}

vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> colonne;
    for(int i = 0; i < data.size(); i++){
        if(chercheIndice(colonne, data[i][j]) == -1){
            colonne.push_back(data[i][j]);
        }
    }
    return colonne;
}

vector<double> conversionDouble(vector<string> t) {
    vector<double> res = vector<double>(t.size());
    for(int i = 0; i < res.size(); i++){
        istringstream(t[i]) >> res[i];
    }
    return res;
}

vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<int> group = vector<int>(valeurs.size());
    for(int j = 0; j < valeurs.size(); j++){
        for(int i = 0; i < data.size(); i++){
            if(data[i][j1] == valeurs[j]){

                // conversion de la ligne actuelle en int, sinon impossible de faire une somme
                vector<int> dataInt = vector<int>(data[i].size());
                for(int k = 0; k < data[i].size(); k++) {
                    istringstream(data[i][k]) >> dataInt[k];
                }
                // Il faut s'assurer que l'on additionne pas une case vide du tableau...
                if(not group[j]) group[j] = dataInt[j2];
                else group[j] += dataInt[j2];
                }
            }
        }
    return group;
    }

vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<double> group = vector<double>(valeurs.size());
    for(int j = 0; j < valeurs.size(); j++){
        for(int i = 0; i < data.size(); i++){
            if(data[i][j1] == valeurs[j]){

                // conversion de la ligne actuelle en double, sinon impossible de faire une somme
                vector<double> dataDouble = conversionDouble(data[i]);
                // Il faut s'assurer que l'on additionne pas une case vide du tableau...
                if(not group[j]) group[j] = dataDouble[j2];
                else group[j] += dataDouble[j2];
                }
            }
        }
    return group;
    }

template<class T>
vector<T> conversion(vector<string> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction conversion non implantée ligne 35");
}

template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // Remplacer cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction groupBy non implantée ligne 41");
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
template vector<int> groupBy<int>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
template vector<double> groupBy<double>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);

