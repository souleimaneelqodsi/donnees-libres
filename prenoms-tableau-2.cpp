#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;


/**
 * Demande à l'utilisateur un prénom et calcule
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {

    // Tableau 2D correspondant au fichier
    auto fichier = litTableau("donnees/liste_des_prenoms.txt", 4);
    
    // Naissances
    cout << "Nombre total de naissances : " << somme(conversionInt(colonne(fichier, 3))) << endl;

    // Entrée utilisateur
    string prenom; cout << "Choisissez un prénom : "; cin >> prenom;

    
    // Collecte de données sur le prénom choisi par l'utilisateur
    auto infos_prenom = selectLignes(fichier, 2, prenom);
    auto nb_garcons = somme(conversionInt(colonne(selectLignes(infos_prenom, 0, "M"),3)));
    auto nb_filles = somme(conversionInt(colonne(selectLignes(infos_prenom, 0, "F"),3)));

    // Affichages garçons 
    if(not nb_garcons){ // si le nombre de garçons est égal à 0
        cout << "Le prénom " << prenom << " n'a été donné à aucun garçon entre 2006 et 2021" << endl;
        
    } else {
        cout << "Le prénom " << prenom << " a été donné à " << nb_garcons << " garçons entre 2006 et 2021" << endl;
        cout << "L'année la plus forte est ";
        int max_garcons = indiceMax(conversionInt(colonne(selectLignes(infos_prenom, 0, "M"),3)));
        
    cout << selectLignes(infos_prenom, 0, "M")[max_garcons][1];
    cout << " avec " << selectLignes(infos_prenom, 0, "M")[max_garcons][3] << " enfants" << endl; }

    // Affichages filles
    if(not nb_filles){ // si le nombre de filles est égal à 0
        cout << "Le prénom " << prenom << " n'a été donné à aucune fille entre 2006 et 2021" << endl;
        
    } else {
        cout << "Le prénom " << prenom << " a été donné à " << nb_filles << " filles entre 2006 et 2021" << endl;
        cout << "L'année la plus forte est ";
        int max_filles = indiceMax(conversionInt(colonne(selectLignes(infos_prenom, 0, "F"),3)));
    cout << selectLignes(infos_prenom, 0, "F")[max_filles][1];
    cout << " avec " << selectLignes(infos_prenom, 0, "F")[max_filles][3] << " enfants" << endl;}
}

