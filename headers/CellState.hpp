#pragma once 

class CellState{
    public : 
    virtual bool IsAlive() const = 0;
    virtual CellState* NextState(int AliveNeigbors) = 0;
    virtual ~CellState();
};