#pragma once
#include "CellState.hpp"


// Chaque Cellule possede une position et un etat gerer par state 

class Cell {
private:
    int x; //Déclaration des coordonnees
    int y; 
    CellState* currentState; //etat acutell (pointe vers singleton, 1 instance par etat)

public:

    Cell(); 
    Cell(int x, int y, CellState* InitialState); 
    Cell(const Cell& other); // copie l etat d une cellule

    Cell& operator=(const Cell& other); //  Opérateur d'assignation
    ~Cell();

    bool IsAlive() const; //verifie si la cellule est vivante
    bool IsObstacle() const; //verifie si la cellule est un obstacle
    void SetState(CellState* NewState); //Pour le nouvelle état
    CellState* CalculNext(int Neighbors, const Rule* rule) const; //Pointeur vers le prochain etat selon les règles
    
    int GetX() const; //Les coordonnées
    int GetY() const;
};