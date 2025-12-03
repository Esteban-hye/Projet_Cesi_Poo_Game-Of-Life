#pragma once
#include "Cellule.hpp"


class CelluleObstacle : public Cellule {
    public :
    CelluleObstacle(int x, int y);
    bool EstVivant() const  override; 
    Cellule* CalculerProchainEtat(int VoisnsVivants) override;
};