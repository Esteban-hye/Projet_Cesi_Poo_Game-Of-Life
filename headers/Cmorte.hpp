#pragma once
#include "Cellule.hpp"


class Cmorte : public Cellule {
    public :
    Cmorte() : Cellule(false){}
    bool EstVivant() override {
        return false;
    }
    ~Cmorte() override{}
};