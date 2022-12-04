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
    fichier.open("donnees/liste_des_prenoms.csv");

    // Passage de l'entête
    string entete;
    getline(fichier, entete);
    
    // variables de parcours
    // note : les variables annee_lect et nbre_total vont contenir les données dont on aura besoin, mais sous forme de string, on les convertira ensuite en int dans annee et nbre
    string declare; string genre ; string annee_lect ; string prenom ; string nbre_total; int nbre; int annee;

    // entrée utilisateur
    int entree ; cout << "Entrée une année entre 2006 et 2021 : " ; cin >> entree;

    // Variables de calcul sur les données
    int somme_annee = 0; int nbre_max = 0; string prenom_max;

    // Parcours et calculs
    string ligne; // cette variable va contenir chaque ligne (caractères séparateurs inclus)
    while(getline(fichier, ligne)){ // on parcourt toutes les lignes du fichier
        istringstream ligne_actuelle = istringstream(ligne); // on convertit la ligne sur laquelle on se trouve dans le parcours en flux
        // de sorte à récupérer chaque élément de chaque colonne grâce à getline() et le stocker dans la variable correspondante :
        getline(ligne_actuelle, declare, ';');
        getline(ligne_actuelle, genre, ';');
        getline(ligne_actuelle, annee_lect, ';');
        getline(ligne_actuelle, prenom, ';');
        // nul besoin de spécifier le caractère séparateur puisque, arrivé à la fin de la ligne, il ne reste que l'élément nombre :
        getline(ligne_actuelle, nbre_total);

        // comme dans getline-exemple, on assure la compatibilité avec Linux
        if(nbre_total.size() > 0 and nbre_total[nbre_total.length()-1] == '\r' ) {
            nbre_total.resize(nbre_total.length()-1);
}
        // conversion de l'année et du nombre total en chaînes de caractère
        istringstream(nbre_total) >> nbre;
        istringstream(annee_lect) >> annee;
        // calculs de l'exercice 2
        if(annee == entree) somme_annee += nbre;
        if(nbre > nbre_max) {
            nbre_max = nbre;
            prenom_max = prenom;}}

    // Affichages
    cout << "En " << entree << ", il y'a eu " << somme_annee << " naissances" << endl;
    cout << "Le prénom le plus donné a été : " << prenom_max << " (donné " << nbre_max << " fois)" << endl;
    
    fichier.close();
    return 0; 
}
