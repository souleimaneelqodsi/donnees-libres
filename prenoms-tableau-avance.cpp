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
 * - le prénom masculin et le prénom féminin le plus populairee
 **/
int main() {
    vector<vector<string>> data = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<int> sommeFG = groupByInt(data, {"M", "F"}, 0, 3);

    cout << "Il y'a eu " << sommeFG[0] << " naissances de garçons et " << sommeFG[1] << " naissances de filles" << endl;
    cout << "L'année qui a eu le plus de naissances est : ";
    vector<string> annees = distinct(data, 1); // on crée un tableau de référence contenant les années (sans doublon)...
    vector<int> somme_annees = groupByInt(data, annees, 1, 3); // ...afin de récupérer les sommes groupées pour chaque année
    cout << annees[indiceMax(somme_annees)] << " avec " << somme_annees[indiceMax(somme_annees)] << " naissances" << endl;
    cout << "En moyenne, naissent " << moyenne(somme_annees) << " enfants par an" << endl;
    vector<vector<string>> garcons = selectLignes(data, 0, "M");
    vector<vector<string>> filles = selectLignes(data, 0, "F");
    vector<int> nb_filles_distinct = groupByInt(filles, distinct(filles, 2), 2, 3); // nombre de naissances pour chaque prénom féminin -> distinct(filles, 2) permet d'avoir une liste des prénoms féminins sans doublons, pareil pour les garçons
    vector<int> nb_garcons_distinct = groupByInt(garcons, distinct(garcons, 2), 2, 3); // nombre de naissances pour chaque prénom masculin
    cout << "Il y'a eu " << groupByInt(filles, distinct(filles, 2), 2, 3).size() << " prénoms de filles différents et " << groupByInt(garcons, distinct(garcons, 2), 2, 3).size() << " prénoms de garçons" << endl;
    cout << "Le prénom féminin le plus populaire est " << distinct(filles, 2)[indiceMax(nb_filles_distinct)] << " avec " << nb_filles_distinct[indiceMax(nb_filles_distinct)] << " naissances" << endl;
    cout << "Le prénom masculin le plus populaire est " << distinct(garcons, 2)[indiceMax(nb_garcons_distinct)] << " avec " << nb_garcons_distinct[indiceMax(nb_garcons_distinct)] << " naissances" << endl;
    return 0;
}

