#pragma once 
#include "Rule.hpp"

//class abstraite qui sert a representer l'etat d une cellule ( pattern d'etat)
// patern state + singleton
//state permet de changer le comportement d une cellule selon son etat 
// singleton permet d avoir 1 instance de chaque etat en memoire

class CellState{
    public : 
    virtual bool IsAlive() const= 0; // verifie si l etat est une cellule vivante
    virtual CellState* NextState(int AliveNeigbors, const Rule* rule) = 0; //Calcule letat suivant selon les regles 
    virtual ~CellState()= default;
    virtual bool IsObstacle() const =0;
    
};