#pragma once
#include "Regle.hpp"

class Cellule {
    protected :
    bool vivant;
    int x;
    int y;
    Regle* regle;

    public :
    Cellule(int x, int y, bool vivant);
    virtual bool EstVivant()  const;
    virtual ~Cellule();
    int GetX() const;
    int GetY() const;
    void SetRegle(Regle* regle);
    virtual Cellule CalculerProchainEtat(int VoisinsVivants) = 0;

};