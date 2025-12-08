#include <iostream>
#include <fstream> 
#include "headers/GameOfLife.hpp"
#include "headers/GraphicalView.hpp" 
#include "headers/RuleClassic.hpp"
#include "headers/ConsoleView.hpp"

int main() {
    // 1. Lecture de la taille
    int hauteur, largeur;
    std::ifstream fichier("Grille2.txt");
    
    if(fichier.is_open()) {
        fichier >> hauteur >> largeur;
        fichier.close(); 
    } else {
        std::cerr << "ERREUR CRITIQUE : Impossible d'ouvrir Grille2.txt" << std::endl;
        return -1;
    }

    // Calcul du zoom
    float tailleCellule = 800.0f / std::max(largeur, hauteur);
    if(tailleCellule < 2.0f) tailleCellule = 2.0f;
    if(tailleCellule > 50.0f) tailleCellule = 50.0f;

    View* maVue = new GraphicalView(largeur, hauteur, tailleCellule);
    Rule* maRegle = new RuleClassic();
    GameOfLife jeu("Grille2.txt", maVue, maRegle);

    std::cout << "--- ETAPE 1 : Le jeu va se lancer ---" << std::endl;
    
    // Le programme va rester bloqué ici tant que la fenêtre est ouverte
    jeu.Run(); 

    // Si on arrive ici, c'est que la fenêtre est fermée
    std::cout << "--- ETAPE 2 : La fenêtre est fermée, on passe à la suite ---" << std::endl;

    std::cout << "--- ETAPE 3 : Tentative de sauvegarde... ---" << std::endl;
    jeu.Save("Resultat.txt");
    
    std::cout << "--- ETAPE 4 : Sauvegarde terminée ! Vérifie le fichier. ---" << std::endl;

    delete maVue;
    delete maRegle;
    
    std::cout << "--- FIN DU PROGRAMME ---" << std::endl;
    return 0;
}