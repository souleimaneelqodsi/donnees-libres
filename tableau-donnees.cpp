#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees.hpp"

void afficheTableau(vector<vector<string>> tableau) {
    for(auto ligne:tableau){
        for(string data:ligne){
            cout << data << " ";
    }
        cout << endl;
    }
}

int somme(vector<int> t) {
    int s = 0;
    for(int v : t){
        s+=v;
    }
    return s;
}

int moyenne(vector<int> t) {
    return somme(t)/t.size();
}

int indiceMax(vector<int> t) {
    if(t.size() == 0) return -1;
    int ind = 0;
    for(int i = 1; i < t.size() ; i++){
        if(t[i] >= t[ind]) ind = i;
    }
    return ind;
}

vector<string> colonne(vector<vector<string>> t, int j) {
    vector<string> colonne;
    for(vector<string> ligne : t){
        colonne.push_back(ligne[j]);
    }
    return colonne;
}


vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> selected_lines;
    vector<string> col = colonne(t, j); // sélection de la colonne
    for(int i = 0; i < col.size(); i++){
        if(col[i] == valeur){
            selected_lines.push_back(t[i]);
        } 
    }
    return selected_lines;
}

