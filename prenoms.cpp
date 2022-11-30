#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le prénom le plus utilisé une année donnée
 * ainsi que le nombre de naissances cette année là **/
int main() {
    ifstream prenoms;
    prenoms.open("donnees/liste_des_prenoms.txt");
    string genre; int annee ; string prenom ; int nbre; 
    int somme_annee = 0; int nbre_max = 0; string prenom_max;
    int entree;
    cout << "Entrez une année  entre 2006 et 2021 : "; 
    cin >> entree;
    while (((prenoms >> genre and prenoms >> annee) and (prenoms >> prenom and prenoms >> nbre))){
        //cout << annee << " " << nbre << endl;
        if(annee == entree){
            somme_annee += nbre;
            if(nbre > nbre_max) {
                prenom_max = prenom; nbre_max = nbre;
            }
        }
    }
    cout << "En " << entree << ", il y a eu " << somme_annee << " naissances" << endl;
    cout << "Le prénom le plus donné a été : " << prenom_max << " (donné " << nbre_max << " fois)" << endl;
    prenoms.close();
    return 0;
}

