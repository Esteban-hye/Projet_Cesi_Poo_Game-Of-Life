#include "../headers/InterfaceGraph.hpp"

InterfaceGraph::InterfaceGraph(int l, int h, int cellSize)
    : window(sf::VideoMode(l * cellSize, h * cellSize), "Game of Life"),
      cellSize(cellSize)
{}

bool InterfaceGraph::WindowsOpen() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    return window.isOpen();
}

void InterfaceGraph::ShowGrid(Grid* Grid) {

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    for (int x = 0; x < Grid->GetLargeur(); ++x) {
        for (int y = 0; y < Grid->GetLongeur(); ++y) {

            if (Grid->GetCellule(x, y)->EstVivant()) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }

    window.display();
}
