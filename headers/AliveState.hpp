#pragma once
#include "CellState.hpp"

class AliveState : public CellState {
    public :
     bool IsAlive() const override;
     CellState* NextState(int AliveNeigbors ) override;
     static CellState* Instance();

};

