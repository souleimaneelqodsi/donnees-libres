/** @file **/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
void afficheTableau(vector<vector<string>> tableau);

/** Somme d'un tableau
 * @param t un tableau d'entiers
 * @result la somme de ces entiers
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
int somme(vector<int> t);

/** Moyenne d'un tableau
 * @param t un tableau d'entiers
 * @result la moyenne de ces entiers
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
int moyenne(vector<int> t);


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entiers
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
int indiceMax(vector<int> t);

/** Sélection des lignes d'un tableau de données
 * Sélectionne un ensemble de lignes en fonction d'un critère donné
 * @param t, un tableau contenant des lignes de données
 * @param j, l'indice de la colonne à vérifier
 * @param valeur, une chaine de caractères correspondant au critère
 * @return un tableau de données ne contenant que les lignes de t telles
 *  que la colonne j ait la valeur correspondant au critère
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur);

/** Extraction d'une colonne d'un tableau de données
 * @param t un tableau 2D de chaines de caractères
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur de chaines de caractères
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
vector<string> colonne(vector<vector<string>> t, int j);

/** Convertit un tableau de chaines de caractères en un tableau d'entiers
 * @param t, un vecteur de chaines de caractères
 * @return un vecteur d'entiers
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
vector<int> conversionInt(vector<string> t);
