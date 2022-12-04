/** @file **/
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/** Renvoie l'indice d'une valeur dans un tableau
 * @param t un tableau de chaines de caractères
 * @param valeur une chaine de caractères
 * @return renvoie l'indice de la valeur dans la chaine ou -1 si la
 *  chaine est absente
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
int chercheIndice(vector<string> t, string valeur);

/** Renvoie un tableau contenant les valeurs distinctes d'une colonne
 * @param data, un tableau 2D de données (chaines de caractères)
 * @param j un numéro de colonne
 * @return un tableau de chaines de caractères contenant les valeurs
 *  distinctes de la colonne j
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 */
vector<string> distinct(vector<vector<string>> data, int j);

/** Calcule des sommes groupées (entières) sur les données
 * @param data, un tableau 2D de données (chaines de caractères)
 * @param valeurs, un tableau de chaines de caractères correspondant
 *  à des valeurs à sélectionner dans les données
 * @param j1 l'indice de la colonne utilisée pour sélectionner les valeurs
 * @param j2 l'indice de la colonne dont on veut faire les sommes groupées
 * @return un tableau d'entiers t tel que t[indice] contient la somme de data[i][j2]
 *  sur toutes les lignes telles que data[i][j1] == valeurs[indice]
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'il y'a présence de tests et la fonction a été réutilisée plusieurs fois sans problème
 **/
vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);

/** Calcule des sommes groupées (double) sur les données
 * @param data, un tableau 2D de données (chaines de caractères)
 * @param valeurs, un tableau de chaines de caractères correspondant
 *  à des valeurs à sélectionner dans les données
 * @param j1 l'indice de la colonne utilisée pour sélectionner les valeurs
 * @param j2 l'indice de la colonne dont on veut faire les sommes groupées
 * @return un tableau de double t tel que t[indice] contient la somme de data[i][j2]
 *  sur toutes les lignes telles que data[i][j1] == valeurs[indice]
 * Auteurs : Souleimane et Lina
 * Assez bon degré de confiance en l'implantation puisqu'il y'a présence de tests mais la fonction n'a jamais été utilisée
 **/
vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);

/** Conversion d'un vecteur de chaînes de caractères en vecteur de doubles
 * @param t un vecteur de chaînes de caractères
 * @return le vecteur, converti en vecteur de doubles
 * Auteurs : Souleimane et Lina
 * Assez bon degré de confiance en l'implantation puisqu'il y'a présence de tests mais la fonction n'a jamais été utilisée
 **/
vector<double> conversionDouble(vector<string> t);

/** Conversion en vecteur de valeurs de type T
 * @param t un vecteur de chaînes de caractères
 * @return le vecteur, converti en vecteur de T
 **/
template<class T>
vector<T> conversion(vector<string> t);

/** Calcule des sommes groupées (de type T) sur les données
 * @param data, un tableau 2D de données (chaines de caractères)
 * @param valeurs, un tableau de chaines de caractères correspondant
 *  à des valeurs à sélectionner dans les données
 * @param j1 l'indice de la colonne utilisée pour sélectionner les valeurs
 * @param j2 l'indice de la colonne dont on veut faire les sommes groupées
 * @return un tableau (de type T) t tel que t[indice] contient la somme de data[i][j2]
 *  sur toutes les lignes telles que data[i][j1] == valeurs[indice]
 **/
template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
