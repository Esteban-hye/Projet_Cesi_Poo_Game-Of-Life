#include "../headers/Cellule.hpp"


Cellule::Cellule(int x, int y, bool vivant) : x(x),y(y), vivant(vivant){}

Cellule::~Cellule(){}

bool Cellule::EstVivant() const{
    return vivant;
}

int Cellule::GetX() const {
    return x;
}
int Cellule::GetY() const {
    return x;
}


