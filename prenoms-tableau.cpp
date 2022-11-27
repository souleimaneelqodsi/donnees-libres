#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    { "M", "2011", "Bubulle", "3"},
    { "F", "2012", "Bichette", "4"},
    { "F", "2011", "Babouche", "7"},
    { "F", "2011", "Ziboulette", "1"}
};

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 **/
void afficheTableau(vector<vector<string>> tableau) {
    for(auto ligne:tableau){
        for(string data:ligne){
            cout << data << " ";
    }
        cout << endl;
    }
}

void testAfficheTableau() {
    afficheTableau(tableauTest);
}


/** Construction d'un tableau 2D de chaines de caractères lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de colonnes séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaines de caractères à deux dimensions
 **/
vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    fichier.open(nom_fichier);
    string data;
    vector<vector<string>> tab_data;
    while(fichier >> data){
        vector<string> data_line;
        data_line.push_back(data); // insertion de la première donnée, déjà lue
        for(int colonne = 0; colonne < nb_colonnes-1 ; colonne++){
        // on arrête à nb_colonne - 1 car on a déjà récupéré le premier élément dans la boucle while
                fichier >> data;
                data_line.push_back(data);
            }
        tab_data.push_back(data_line);
    }
    fichier.close();
    return tab_data;
}

/** Test de la fonction litTableau **/
void testLitTableau() {
    CHECK(litTableau("donnees/donnees-test.txt", 4) == tableauTest);
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    CHECK(t.size() == 22994);
    CHECK(t[0][0] == "F");
    CHECK(t[4][2] == "Astrid");
    CHECK(t[5][3] == "12");
}

/** Extraction d'une colonne d'un tableau de données
 * @param t un tableau 2D de chaines de caractères
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur de chaines de caractères
 **/
vector<string> colonne(vector<vector<string>> t, int j) {
    vector<string> colonne;
    for(vector<string> ligne : t){
        colonne.push_back(ligne[j]);
    }
    return colonne;
}

/** Test de la fonction colonne **/
void testColonne() {
    CHECK(colonne(tableauTest, 0) == vector<string>({"M","F","F","F"}));
    CHECK(colonne(tableauTest, 1) == vector<string>({"2011","2012","2011","2011"}));
    CHECK(colonne(tableauTest, 2) == vector<string>({"Bubulle","Bichette","Babouche","Ziboulette"}));
    CHECK(colonne(tableauTest, 3) == vector<string>({"3","4","7","1"}));
}

/** Convertit un tableau de chaines de caractères en un tableau d'entiers
 * @param t, un vecteur de chaines de caractères
 * @return un vecteur d'entiers
 **/
vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

void testConversionInt() {
    CHECK(conversionInt({}) == vector<int>({}));
    CHECK(conversionInt({"1","2","3"}) == vector<int>({1,2,3}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
    int s = 0;
    for(int v : t){
        s+=v;
    }
    return s;
}

/** copier la fonction moyenne déjà écrite **/
int moyenne(vector<int> t) {
    return somme(t)/t.size();
}

/** copier la fonction indiceMax déjà écrite **/
int indiceMax(vector<int> t) {
    if(t.size() == 0) return -1;
    int ind = 0;
    for(int i = 1; i < t.size() ; i++){
        if(t[i] >= t[ind]) ind = i;
    }
    return ind;
}

/** Sélection des lignes d'un tableau de données
 * Sélectionne un ensemble de lignes en fonction d'un critère donné
 * @param t, un tableau contenant des lignes de données
 * @param j, l'indice de la colonne à vérifier
 * @param valeur, une chaine de caractères correspondant au critère
 * @return un tableau de données ne contenant que les lignes de t telles
 *  que la colonne j ait la valeur correspondant au critère
 **/
vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> selected_lines;
    auto col = colonne(t, j); // sélection de la colonne
    for(int i = 0; i < col.size(); i++){
        if(col[i] == valeur){
            selected_lines.push_back(t[i]);
        } 
    }
    return selected_lines;
}

/** Test de la fonction selectLignes **/
void testSelectLignes() {
    CHECK(selectLignes(tableauTest, 0, "M") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}}));
    CHECK(selectLignes(tableauTest, 1, "2011") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}, { "F", "2011", "Babouche", "7"}, { "F", "2011", "Ziboulette", "1"}}));
}

/** Lance les tests de litTableau, selectLignes et colonne puis
 * affiche le nombre total de naissances puis
 * demande à l'utilisateur un prénom et calcule et affiche
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {

    // Tests
    testAfficheTableau();
    testLitTableau();
    testColonne();
    testConversionInt();
    testSelectLignes();

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