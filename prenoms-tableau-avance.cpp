#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-lecture.hpp"
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
using namespace std;


/**
 * Calcule et affiche :
 * - le nombre total de naissances de garçons et de naissances de filles
 * - l'année qui a eu le plus de naissances (garçons et filles confondus), avec leur nombre
 * - le nombre de naissances en moyenne par an
 * - les nombres de prénoms féminins et masculins différents
 * - le prénom masculin et le prénom féminin le plus populaire
 **/
int main() {
    vector<vector<string>> data = litTableau("donnees/liste_des_prenoms.txt", 4);
    for(auto data2:data){for(auto data3:data2){cout << data3; } cout << endl;}
    vector<int> sommeFG = groupByInt(data, {"M, F"}, 0, 3);
    cout << sommeFG.size() << endl;
    cout << "Il y'a eu " << sommeFG[0] << " naissances de garçons et " << sommeFG[1] << " naissances de filles" << endl;
}

