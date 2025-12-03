#pragma once
#include "Cellule.hpp"


class CelluleVivante: public Cellule {
    public :
    CelluleVivante(int x, int y);
    bool EstVivant() const  override; 
};