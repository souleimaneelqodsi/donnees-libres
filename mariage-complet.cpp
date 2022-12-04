#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivi d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/
vector<int> litTableauAnnee(string nom_fichier) {
    ifstream mariages;
    mariages.open(nom_fichier);
    int annee; string jour; int nbre;
    vector<int> tab_annee = {0, 0, 0, 0, 0, 0}; // on initialise à 0 pour pouvoir faire les sommes
    while((mariages >> annee and mariages >> jour) and mariages >> nbre){
        tab_annee[annee-2010] += nbre;
    }
    mariages.close();
    return tab_annee;
}

/** Test de la fonction litTableauAnnee **/
void testLitTableauAnnee() {
    vector<int> t = litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    CHECK(t[0] == 9195); // Nombre de mariages en 2010
    CHECK(t[3] == 9443); // Nombre de mariages en 2013
    CHECK(t[5] == 9046); // Nombre de mariages en 2015
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractère contenant un jour de la semaine (première lettre en majuscule)
 * @return un numéro entre 0 et 6 correspondant au jour de la semaine ou
 * -1 si le jour n'est pas valide
 **/
int indiceJour(string jour) {
    for(int i=0; i < jours.size(); i++) {
        if (jour == jours[i]) {
            return i;
        }
    }
    return -1;
}

void testIndiceJour() {
    CHECK(indiceJour("Lundi") == 0);
    CHECK(indiceJour("Samedi") == 5);
    CHECK(indiceJour("Dimanche") == 6);
    CHECK(indiceJour("samedi") == -1);
}

/** Construction du tableau des mariages par jour
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivie d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/
vector<int> litTableauJours(string nom_fichier) {
    ifstream mariages;
    mariages.open(nom_fichier);
    int annee; string jour; int nbre;
    vector<int> tab_jours = {0, 0, 0, 0, 0, 0, 0}; // initialisation à 0 pour la même raison que dans litTableauAnnee
    while((mariages >> annee and mariages >> jour) and mariages >> nbre){
        tab_jours[indiceJour(jour)] += nbre;
    }
    mariages.close();
    return tab_jours;
}

/** Test de la fonction litTableauJours **/
void testLitTableauJours() {
    vector<int> t = litTableauJours("donnees/statistiques-des-jours-des-mariages.txt");
    CHECK(t[0] == 4171); // Nombre de mariages le lundi
    CHECK(t[3] == 4393); // Nombre de mariages le jeudi
    CHECK(t[6] == 2); // Nombre de mariages le dimanche
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs du tableau
 **/
int somme(vector<int> t) {
    int somme = 0;
    for(int valeur : t){
        somme += valeur;
    }
    return somme;
}

/** Test de la fonction somme **/
void testSomme() {
    CHECK(somme({1,2,3}) == 6);
    CHECK(somme({}) == 0);
    CHECK(somme({2,2,4,8}) == 16);
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 * (on arrondit à l'entier inférieur)
 **/
int moyenne(vector<int> t) {
    return somme(t)/t.size();
}

/** Test de la fonction moyenne **/
void testMoyenne() {
    CHECK(moyenne({1,2,3}) == 2);
    CHECK(moyenne({1}) == 1);
    CHECK(moyenne({2,2,4,8}) == 4);
}


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
int indiceMax(vector<int> t) {
    if(t.size() == 0) return -1;
    int ind = 0;
    for(int i = 1; i < t.size() ; i++){
        if(t[i] >= t[ind]) ind = i;
    }
    return ind;
}

/** Test de la fonction IndiceMax **/
void testIndiceMax() {
    CHECK(indiceMax({}) == -1);
    CHECK(indiceMax({1,2,3}) == 2);
    CHECK(indiceMax({1,3,2}) == 1);
    CHECK(indiceMax({1}) == 0);
    CHECK(indiceMax({2,8,4,4}) == 1);
}

/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/
int main() {
    // tests
    testLitTableauAnnee();
    testIndiceJour();
    testLitTableauJours();
    testSomme();
    testMoyenne();
    testIndiceMax();
    
    //affichages
    vector<int> tab_annee = litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    vector<int> tab_jours = litTableauJours("donnees/statistiques-des-jours-des-mariages.txt");
    double pour100sam = (tab_jours[indiceJour("Samedi")]*1./somme(tab_jours)*1.) * 100; // *1. permet de "convertir" les entiers en décimaux afin que l'opération soit possible
    cout << "Le nombre total de mariages célébrés entre 2010 et 2015 est de " << somme(tab_annee) << endl;
    cout << "Le nombre de mariages célébrés en moyenne par an est de " << moyenne(tab_annee) << endl;
    cout << "L'année où l'on a célébré le plus de mariages est " << indiceMax(tab_annee) + 2010 << " avec " << tab_annee[indiceMax(tab_annee)] << " mariages" << endl;
    cout << "Le jour de la semaine où l'on a célébré le plus de mariages est le " << jours[indiceMax(tab_jours)] <<  " avec " << tab_jours[indiceMax(tab_jours)] << " mariages" << endl;
    cout << "Le pourcentage de mariages célébrés le samedi est de " << pour100sam << "%" << endl;
    
    return 0;
}

