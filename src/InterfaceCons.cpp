#include "../headers/InterfaceCons.hpp"
#include <iostream>

void InterfaceCons::ShowGrid(Grille* grille) {
    for (int y = 0; y < grille->GetLongeur(); ++y) {
        for (int x = 0; x < grille->GetLargeur(); ++x) {
            std::cout << (grille->GetCellule(x, y)->EstVivant() ? "O" : ".");
        }
        std::cout << "\n";
    }
    std::cout << std::string(20, '-') << "\n";
}

bool InterfaceCons::WindowsOpen() {
    return true;  // la console est "toujours ouverte"
}
