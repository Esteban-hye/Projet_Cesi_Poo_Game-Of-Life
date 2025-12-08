#pragma once
#include "View.hpp"
#include <SFML/Graphics.hpp>

class GraphicalView : public View {
private:
    sf::RenderWindow* window; //fenetre SML
    float cellSize; //Taille d une cellule

public:
    GraphicalView(int width,int height,float cellSize =10.0f); //constructeur 
    virtual ~GraphicalView(); //destructeur
    void Render(const Grid& grid) override; //methode pour afficher la grille
};