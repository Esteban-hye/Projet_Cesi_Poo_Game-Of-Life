
#include "../headers/ObstacleState.hpp"

CellState* ObstacleState::Instance() { //instance unique instance 
    static ObstacleState instance;
    return &instance;
}

CellState* ObstacleState::NextState(int AliveNeigbors, const Rule* rule) { //Onstacle reste un obstacle
    return ObstacleState::Instance();
}

bool ObstacleState::IsAlive() const {
    return true;
}
bool ObstacleState::IsObstacle() const {
    return true;
}