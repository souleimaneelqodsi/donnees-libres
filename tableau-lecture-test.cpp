/** @file **/
#include <iostream>
#include "tableau-lecture.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    { "M", "2011", "Bubulle", "3"},
    { "F", "2012", "Bichette", "4"},
    { "F", "2011", "Babouche", "7"},
    { "F", "2011", "Ziboulette", "1"}
};


void testLitTableau() {
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    ASSERT(t.size() == 22994);
    ASSERT(t[0][0] == "F");
    ASSERT(t[4][2] == "Astrid");
    ASSERT(t[5][3] == "12");
}


int main() {
    cout << "Lancement des tests de litTableau" << endl;
    testLitTableau();
}

