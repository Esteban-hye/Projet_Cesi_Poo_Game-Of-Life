#include "../headers/CelluleMorte.hpp"

CelluleMorte::CelluleMorte(int x,int y) :Cellule(x,y,false){}

bool CelluleMorte::EstVivant() const  {
    return false;
}