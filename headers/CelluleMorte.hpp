#pragma once
#include "Cellule.hpp"


class CelluleMorte : public Cellule {
    public :
    CelluleMorte(int x, int y);
    bool EstVivant() const  override; 
    Cellule* CalculerProchainEtat(int VoisnsVivants) override;

};