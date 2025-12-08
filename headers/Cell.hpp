#pragma once
#include "CellState.hpp"


// Chaque Cellule possede une position et un etat gerer par state 

class Cell {
private:
    int x;
    int y;
    CellState* currentState; //etat acutell (pointe vers singleton)

public:

    Cell(); 
    Cell(int x, int y, CellState* InitialState);
    Cell(const Cell& other); // copie l etat d une cellule

    Cell& operator=(const Cell& other); //  Opérateur d'assignation
    ~Cell();

    bool IsAlive() const;
    bool IsObstacle() const;
    void SetState(CellState* NewState);
    CellState* CalculNext(int Neighbors, const Rule* rule) const;
    
    int GetX() const;
    int GetY() const;
};