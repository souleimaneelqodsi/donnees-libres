#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/** Calcule et affiche le prénom le plus donné une année donnée
 * ainsi que le nombre de naissance cette année là **/
int main() {
    ifstream fichier;
    fichier.open("donnees/liste_des_prenoms.txt");

    // Passage de l'entête
    string entete;
    getline(fichier, entete);
    
    // variables de parcours
    int declare; string genre ; int annee ; string prenom ; int nbre_total;

    // entrée utilisateur
    int entree ; cout << "Entrée une année entre 2006 et 2021 : " ; cin >> entree; cout << endl;

    int somme_annee = 0; int nbre_max = 0; int prenom_max;
    while(((getline(fichier, declare, ';') and getline(fichier, genre, ';')) and (getline(fichier, annee, ';') and getline(fichier, prenom, ';')) and (getline(fichier, nbre_total, ';')))){
        if(annee == entree) somme_annee += nbre_total;
        if(nbre > nbre_max){
            nbre_max = nbre;
            prenom_max = prenom;
        }
    }

    cout << "En " << entree << ", il y'a eu " << somme_annee << " naissances" << endl;
    cout << "Le prénom le plus donné a été :" << prenom_max << " (donné " << nbre_max << " fois)" << endl;
    
    fichier.close();
    return 0;
}

