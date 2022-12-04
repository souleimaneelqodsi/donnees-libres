/** @file **/
#include <vector>
#include <string>
#include <iostream>
using namespace std;


/** Construction d'un tableau 2D de chaines de caractères lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
 * de colonnes séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaines de caractères à deux dimensions
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes);

