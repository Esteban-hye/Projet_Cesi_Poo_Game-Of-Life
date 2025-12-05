#include "../headers/InterfaceCons.hpp"
#include <iostream>

void InterfaceCons::ShowGrid(Grid* Grid) {
    for (int y = 0; y < Grid->GetLongeur(); ++y) {
        for (int x = 0; x < Grid->GetLargeur(); ++x) {
            std::cout << (Grid->GetCellule(x, y)->EstVivant() ? "O" : ".");
        }
        std::cout << "\n";
    }
    std::cout << std::string(20, '-') << "\n";
}

bool InterfaceCons::WindowsOpen() {
    return true;  // la console est "toujours ouverte"
}
