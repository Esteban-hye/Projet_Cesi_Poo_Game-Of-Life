#include "../headers/ConsoleView.hpp"
#include <iostream>
#include <thread>
#include <chrono>

// Attention au nom de la classe ici aussi !
ConsoleView::ConsoleView() {
    std::cout << "--- Mode Console Active ---" << std::endl;
}

ConsoleView::~ConsoleView() {
    std::cout << "--- Fin ---" << std::endl;
}

bool ConsoleView::IsOpen() const {
    return true; // La console reste toujours "ouverte"
}

void ConsoleView::Render(const Grid& grid) {
    // Efface l'écran
    std::cout << "\033[H\033[2J"; 
    
    for (int y = 0; y < grid.GetHeight(); ++y) {
        for (int x = 0; x < grid.GetWidth(); ++x) {
            
            const Cell* cell = grid.GetCell(x, y);

            if (cell->IsObstacle()) std::cout << "X ";
            else if (cell->IsAlive()) std::cout << "O ";
            else std::cout << ". ";
        }
        std::cout << std::endl;
    }
    std::cout << "Ctrl+C pour quitter." << std::endl;
}