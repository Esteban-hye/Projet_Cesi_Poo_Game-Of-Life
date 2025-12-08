#pragma once
#include "CellState.hpp"


class DeadState : public CellState{
    public :

     bool IsAlive() const override;
     CellState* NextState(int AliveNeigbors ,const Rule* rule ) override; // calcule l etat suivant selon les regles
     static CellState* Instance();  //pointe vers l instance unique
    bool IsObstacle() const override; //Vérifie si c'est un obstacle, sans modifier le type

};

