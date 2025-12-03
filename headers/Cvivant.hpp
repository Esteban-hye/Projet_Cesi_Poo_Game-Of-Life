#pragma once
#include "Cellule.hpp"


class Cvivant : public Cellule {
    public :
    Cvivant() Cellule(true){}
    bool EstVivant() override {
        return true;
    }
    ~Cvivant() override{}
};