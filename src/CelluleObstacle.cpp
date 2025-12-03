#include "../headers/CelluleObstacle.hpp"


CelluleObstacle::CelluleObstacle(int x,int y, bool vivant) :Cellule(x,y,vivant){}

bool CelluleObstacle::EstVivant() const  {
    return vivant;
}