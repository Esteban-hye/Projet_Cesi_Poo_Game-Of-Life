#pragma once
#include "Cellule.hpp"


class Cobstacle : public Cellule {
    public :
    Cobstacle() : Cellule(false){}
    bool EstVivant() override {
        return false;
    }
    ~Cobstacle() override{}
};