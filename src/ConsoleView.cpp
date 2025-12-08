#include "../headers/ConsoleView.hpp"
#include <iostream>

ConsoleView::ConsoleView() {
    // Rien de spécial à initialiser pour la console
    std::cout << "--- Mode Console Active ---" << std::endl;
}

ConsoleView::~ConsoleView() {
    std::cout << "--- Fin de la simulation ---" << std::endl;
}


void ConsoleView::Render(const Grid& grid) {
    // 1. EFFACER L'ÉCRAN (Commande ANSI pour Linux/Mac)
    // Cela permet d'avoir une animation au lieu d'un défilement
    std::cout << "\033[H\033[2J"; 

    // 2. DESSINER LA GRILLE
    // On parcourt Y d'abord (lignes), puis X (colonnes) pour l'affichage console
    for (int y = 0; y < grid.GetHeight(); ++y) {
        for (int x = 0; x < grid.GetWidth(); ++x) {
            
            const Cell* cell = grid.GetCell(x, y);

            if (cell->IsObstacle()) {
                std::cout << "X "; // Obstacle (ex: Mur)
            }
            else if (cell->IsAlive()) {
                std::cout << "O "; // Cellule Vivante
            }
            else {
                std::cout << ". "; // Cellule Morte
            }
        }
        // Fin de la ligne, on saute une ligne
        std::cout << std::endl;
    }
    
    // Un petit espace en bas pour faire propre
    std::cout << "Génération affichée (Ctrl+C pour quitter)" << std::endl;
}