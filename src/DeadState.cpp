#include "AliveState.hpp"
#include "DeadState.hpp"

CellState* DeadState::Instance(){
    static DeadState instance;
    return &instance;
}

bool DeadState::IsAlive() const{
    return false;
}

CellState* DeadState::NextState(int AliveNeighbors){
    if (AliveNeighbors ==2 || AliveNeighbors == 3){
        return AliveState::Instance();
    }
    return DeadState::Instance();
}