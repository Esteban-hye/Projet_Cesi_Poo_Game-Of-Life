#include "AliveState.hpp"
#include "DeadState.hpp"

CellState* AliveState::Instance(){
    static AliveState instance;
    return &instance;
}

bool AliveState::IsAlive() const{
    return true;
}

CellState* AliveState::NextState(int AliveNeighbors){
    if (AliveNeighbors ==2 || AliveNeighbors == 3){
        return AliveState::Instance();
    }
    return DeadState::Instance();
}