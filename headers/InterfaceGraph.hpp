#ifndef INTERFACE_GRAPH_HPP
#define INTERFACE_GRAPH_HPP

#include <SFML/Graphics.hpp>
#include "Interface.hpp"

class InterfaceGraph : public Interface {
private:
    sf::RenderWindow window;
    int cellSize;

public:
    InterfaceGraph(int l, int h, int cellSize = 10);

    void ShowGrid(Grid* Grid) override;
    bool WindowsOpen() override;
};

#endif
