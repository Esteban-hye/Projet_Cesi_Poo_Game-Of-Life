#include "../headers/Interface.hpp"

Interface::Interface(int l, int h, int cellSize)
    : window(sf::VideoMode(l * cellSize, h * cellSize), "Jeu de la Vie"),

      cellSize(cellSize)
{}

bool Interface::WindowsOpen() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    return window.isOpen();
}

void Interface::ShowGrid(Grille* grille) {

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    for (int x = 0; x < grille->GetLargeur(); ++x) {
        for (int y = 0; y < grille->GetLongeur(); ++y) {

            if (grille->GetCellule(x, y)->EstVivant()) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }

    window.display();
}

