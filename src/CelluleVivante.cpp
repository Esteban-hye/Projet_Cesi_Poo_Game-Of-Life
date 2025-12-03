#include "../headers/CelluleVivante.hpp"

CelluleVivante::CelluleVivante(int x,int y) :Cellule(x,y,false){}

bool CelluleVivante::EstVivant() const  {
    return false;
}