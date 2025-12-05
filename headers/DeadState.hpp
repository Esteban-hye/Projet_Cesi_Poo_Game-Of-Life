#pragma once
#include "CellState.hpp"


class DeadState : public CellState {
    public :
     bool IsAlive() const override;
     CellState* NextState(int AliveNeigbors ) override;
     static CellState* Instance();
};

