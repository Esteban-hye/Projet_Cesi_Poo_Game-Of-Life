#pragma once
#include "CellState.hpp"

class ObstacleState : public CellState {
public:
    bool IsAlive() const override ;
    CellState* NextState(int AliveNeigbors, const Rule* rule) override;
    static CellState* Instance();  //pointe vers l instance unique
    bool IsObstacle() const override;

};