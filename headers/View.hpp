#pragma once
#include "Grid.hpp"

//calss abstaite pour choisir les modes  d'affichage

class View {
public:

    virtual ~View() = default;
    virtual void Render(const Grid& grid)= 0;
};