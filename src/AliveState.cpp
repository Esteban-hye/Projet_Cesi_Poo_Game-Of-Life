#include "../headers/AliveState.hpp"
#include "../headers/DeadState.hpp"

CellState* AliveState::Instance(){ //instance unique instance 
    static AliveState instance;
    return &instance;
}


bool AliveState::IsAlive() const{
    return true;
}

CellState* AliveState::NextState(int AliveNeighbors, const Rule* rule){
    bool StayAlive = rule->CalNewState(AliveNeighbors,true);
    if (StayAlive){
        return AliveState::Instance();
    }
    return DeadState::Instance();
}
bool AliveState::IsObstacle() const{
    return false;
}