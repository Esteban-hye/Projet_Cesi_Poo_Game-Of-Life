#include "../headers/AliveState.hpp"
#include "../headers/DeadState.hpp"

CellState* DeadState::Instance(){ //instance unique instance 
    static DeadState instance; // Unique instance (pattern Singleton)
    return &instance; //retourne toujours la meme instance
}
bool DeadState::IsAlive() const{ //Si la cellule est vivante, cela renvoie False
    return false;
}

CellState* DeadState::NextState(int AliveNeighbors, const Rule* rule){ //calcule l etat suivant selon les regles
    bool BecomeAlive = rule->CalNewState(AliveNeighbors,false);
    if (BecomeAlive){
        return AliveState::Instance();
    }
    return DeadState::Instance();
}

bool DeadState::IsObstacle() const{ //Si c'est un obstacle, cela renvoie False
    return false;
}