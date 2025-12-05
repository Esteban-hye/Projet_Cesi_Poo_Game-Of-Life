#ifndef Interface_hpp
#define Interface_hpp

#include <SFML/Graphics.hpp>
#include "Grille.hpp"

class Interface {
private:
    sf::RenderWindow window;
    int cellSize;

public:
    Interface (int l, int h, int cellSize = 10);

    void ShowGrid(Grille* grille);
    bool WindowsOpen();

};

#endif