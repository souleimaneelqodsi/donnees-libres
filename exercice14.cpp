#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;


/** Calcule et affiche le taux d'évolution de la qualité de l'air 
 * dans les stations métro de Châtelet et Franklin D. Roosevelet
 * Auteur : Souleimane
**/

int main(){

    // Tableaux 2D des fichiers
    vector<vector<string>> t1 = litTableauCSV("donnees/qualite-de-lair-mesuree-dans-la-station-chatelet.csv", 7);
    //vector<vector<string>> t2 = litTableauCSV("donnees/qualite-de-lair-mesuree-dans-la-station-franklin-d-roosevelt.csv", 7);


    vector<vector<vector<int>>> t_annees;

    vector<vector<int>> sous_tableau;
    for(int a = 2015 ; a <= 2022 ; a++){
            for(int i = 0; i < t1.size() ; i++){
               if(conversionInt({t1[i][0].substr(0, 4)})[0] == a){ 
                    vector<string> sous_sous_tableau;
                    if (not(((((t1[i][1] == "ND") or (t1[i][2] == "ND")) or (t1[i][3] == "ND"))))){
                      if((((t1[i][1][0] == '<') or (t1[i][2][0] == '<')) or (t1[i][3][0] == '<'))){
                        for(int k = 1; k <= 3 ; k++){
                            t1[i][k] = t1[i][k].substr(1,1);
                        }
                    }
                        sous_sous_tableau.push_back(t1[i][1]);
                        sous_sous_tableau.push_back(t1[i][2]);
                        sous_sous_tableau.push_back(t1[i][3]);
                }
                    sous_tableau.push_back(conversionInt(sous_sous_tableau));
                }
        }
        t_annees.push_back(sous_tableau);
    }
    vector<vector<int>> moyenneschatelet;
    for(auto annee:t_annees){
        vector<int> annee_actuelle_moyennes;
        for(int k = 1 ; k <= 3 ; k++){
            annee_actuelle_moyennes.push_back(moyenne(conversionInt(colonne(annee, k))));x
        } 
            moyenneschatelet.push_back(annee_actuelle_moyennes);
    }

    vector<vector<int>> tauxEvolutionAnneeParAnnee;
    for(int indMoyennes = 1 ; indMoyennes < moyenneschatelet.size() ; indMoyennes++){
        for(int k = 1; k<=3 ; k++){
            vector<int> taux_evolution_annee;
            taux_evolution_annee.push_back({(100*(moyennes_chatelet[indMoyennes][k] - moyennes_chatelet[indMoyennes - 1][k])/abs(moyennes_chatelet[indMoyennes-1]))}); // formule mathématique de calcul de taux d'évolution (en pourcentage) : (Valeur d'arrivée - valeur de départ/valeur de départ) * 100
            }
        tauxEvolutionAnneeParAnnee.push_back(taux_evolution_annee);
    }

    vector<int> annees = {2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022};

    cout << "Station métro Châtelet : " << endl;
    for(int indAnnees = 1 ; indAnnees < annees.size(); indAnnees++){
        cout << "Entre l'année " << annees[indAnnees - 1] << " et l'année " << annees[indAnnees];
        if(((tauxEvolutionAnneeParAnnee[indAnnee][0] >= 10) or (tauxEvolutionAnneeParAnnee[indAnnee][1] >= 5) or (tauxEvolutionAnneeParAnnee[indAnnee][2] >= 5))) {
            cout << ", la qualité de l'air s'est dégradée." << endl;
            cout << "En effet, les particules fines ont augmenté : ";
            for(int k = O ; k <= 2 ; k++){
                vector<string> particules = {"NO", "NO2", "PM10"};
                if(tauxEvolutionAnneeParAnnee[indAnnee][k] > 0){
                    cout << "+ " << tauxEvolutionAnneeParAnnee[indAnnee][0] << "% " << particules[k] << " ";
                }
                else{
                    cout << tauxEvolutionAnneeParAnnee[indAnnee][0] << "% " << particules[k] << " ";
                }
            }
            cout << "(déterminent, entre autres, la qualité de l'air).";
        }
         else {
             cout << ", la qualité de l'air n'a pas beaucoup changée, voire s'est améliorée." << endl;
        }
    }
    
    return 0;
}