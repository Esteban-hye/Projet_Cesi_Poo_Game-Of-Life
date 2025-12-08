#include "../headers/AliveState.hpp"
#include "../headers/DeadState.hpp"

CellState* AliveState::Instance(){ //instance unique instance 
    static AliveState instance; //une seule instance dans le programme
    return &instance;
}


bool AliveState::IsAlive() const{ //vérifie que la cellule est vivante
    return true;
}

CellState* AliveState::NextState(int AliveNeighbors, const Rule* rule){ // calcule l etat suivant selon les regles
    bool StayAlive = rule->CalNewState(AliveNeighbors,true); // true car cellule vivante
    if (StayAlive){
        return AliveState::Instance();
    }
    return DeadState::Instance();
}
bool AliveState::IsObstacle() const{ //Si la fonction n'est pas vivantes alors, elle cela renvoie False
    return false;
}