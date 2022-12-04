#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le nombre total de mariages célébrés entre 2010 et 2015 
 * Auteurs : Souleimane et Lina
 * Bon degré de confiance en l'implantation puisqu'elle produit bien l'affichage demandé
**/
int main() {
    ifstream mariages;
    mariages.open("donnees/statistiques-des-jours-des-mariages.txt");
    int annee ; string jour ; int nbre; int somme = 0;
    while ((mariages >> annee and mariages >> jour) and mariages >> nbre){
        somme += nbre;
        }
    cout << "Nombre total de mariages : " << somme << endl;
    mariages.close();
    return 0;
}

