#include "../headers/AliveState.hpp"
#include "../headers/DeadState.hpp"

CellState* DeadState::Instance(){ //instance unique instance 
    static DeadState instance;
    return &instance;
}
bool DeadState::IsAlive() const{ 
    return false;
}

CellState* DeadState::NextState(int AliveNeighbors, const Rule* rule){
    bool BecomeAlive = rule->CalNewState(AliveNeighbors,false);
    if (BecomeAlive){
        return AliveState::Instance();
    }
    return DeadState::Instance();
}

bool DeadState::IsObstacle() const{
    return false;
}