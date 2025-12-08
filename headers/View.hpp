#pragma once
#include "Grid.hpp"

//calss abstaite pour choisir les modes  d'affichage

class View {
public:

    virtual ~View() = default; //destructeur par défaut
    virtual void Render(const Grid& grid)= 0; //methode pour afficher la grille
};
