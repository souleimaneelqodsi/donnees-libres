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
    fichier.open("donnees/donnees-test");

    // Passage de l'entête
    string entete;
    getline(fichier, entete);
    cout << "En tete : " << entete << endl;
    
    // variables de parcours
    string declare; string genre ; string annee_lect ; string prenom ; string nbre_total; int nbre; int annee;

    // entrée utilisateur
    int entree ; cout << "Entrée une année entre 2006 et 2021 : " ; cin >> entree; cout << endl;

    int somme_annee = 0; int nbre_max = 0; string prenom_max;
    string ligne;
    while(getline(fichier, ligne)){
        stringstream ss(ligne);
        getline(ss, declare, ';');
        getline(ss, genre, ';');
        getline(ss, annee_lect, ';');
        getline(ss, prenom, ';');
        getline(ss, nbre_total, ';');
        cout << declare << " " << genre << " " << annee_lect << " " << prenom << " " << nbre_total << " " << endl;
    }
    
    /**while(((getline(fichier, declare, ';') and getline(fichier, genre, ';')) and (getline(fichier, annee, ';') and getline(fichier, prenom, ';')) and (getline(fichier, nbre_total, ';')))) {
    if ( nbre_total.size() > 0 and nbre_total[nbre_total.length()-1] == '\r' ) {
        nbre_total.resize(nbre_total.length() - 1);
    }
        istringstream(nbre_total) >> nbre;
        istringstream(annee_lect) >> annee;
        if(annee == entree) {somme_annee += nbre;}
        if(nbre > nbre_max) {
            nbre_max = nbre;
            prenom_max = prenom;**/

    cout << "En " << entree << ", il y'a eu " << somme_annee << " naissances" << endl;
    cout << "Le prénom le plus donné a été :" << prenom_max << " (donné " << nbre_max << " fois)" << endl;
    
    fichier.close();
    return 0; 
}
