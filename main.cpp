#include <iostream>
#include <fstream> 
#include "headers/GameOfLife.hpp"
#include "headers/GraphicalView.hpp" 
#include "headers/RuleClassic.hpp"
#include "headers/RuleCustom.hpp"
#include "headers/ConsoleView.hpp"

int main() {

    // Pour la taille de la fenetre
    int hauteur; 
    int largeur;
    std::ifstream fichier("Grille.txt") ;
    
    if(fichier.is_open()) {
        fichier>> hauteur>>largeur;
        fichier.close(); 
        std::cout <<"Taille: " <<largeur <<"x"<< hauteur<<std::endl;
    } else {
        std::cerr << "Erreur : taille impossible." << std::endl;
        return -1;
    }

    float tailleCellule = 800.0f / std::max(largeur, hauteur);
    if(tailleCellule<2.0f) tailleCellule= 2.0f;   //taille minimun fenetre 
    if(tailleCellule>50.0f) tailleCellule =50.0f; // taille maximun fenetre 



   // View* maVue = new GraphicalView(largeur, hauteur, tailleCellule);
    View* maVue = new ConsoleView();

    Rule* maRegle = new RuleClassic();

    std::cout << "Lancement" << std::endl;
    GameOfLife jeu("Grille.txt", maVue, maRegle);

    jeu.Run();

    delete maVue ;
    delete maRegle;
    return 0 ;
}