#include "../headers/Cell.hpp"
#include "../headers/DeadState.hpp"
#include "../headers/AliveState.hpp"
#include "../headers/ObstacleState.hpp"

Cell::Cell() : x(0), y(0) {
    currentState = DeadState::Instance(); //Les cases de bases sont des cellules mortes
}
Cell::Cell(int x, int y, CellState* InitialState) 
    : x(x), y(y), currentState(InitialState) {
    if (!currentState) currentState = DeadState::Instance(); // si la cellule n'a pas d'état, alors elle est considérer comme morte
}

Cell::Cell(const Cell& other) : x(other.x), y(other.y) { //copie la cellule, dans le but de générer le nouvelle état
    if (other.IsObstacle()) {
        currentState = ObstacleState::Instance(); 
    }
    else if (other.IsAlive()) {
        currentState = AliveState::Instance(); 
    }
    else {
        currentState = DeadState::Instance(); 
    }
}

Cell& Cell::operator=(const Cell& other) {  // Vérifie qu'on n'est pas en train de s'assigner à soi-même, permet d'éviter les doublons

    if (this != &other) {
        x = other.x;
        y = other.y;
        if (other.IsObstacle()) {
            currentState = ObstacleState::Instance();
        }
        else if (other.IsAlive()) {
            currentState = AliveState::Instance();
        }
        else {
            currentState = DeadState::Instance();
        }
    }
    return *this;
}

Cell::~Cell() {}

bool Cell::IsAlive() const { // Renvoie true si l'état actuel existe et correspond à AliveState, sinon false

    return currentState ? currentState->IsAlive() : false; 
}

bool Cell::IsObstacle() const { // Renvoie true si l'état actuel existe et correspond à ObstacleState, sinon false
    return currentState ? currentState->IsObstacle() : false;
}

void Cell::SetState(CellState* NewState) { //fonction du nouvelle état
    currentState = NewState;
}

CellState* Cell::CalculNext(int Neighbors, const Rule* rule) const { //calcule le nouvel état de la cellule
    return currentState ? currentState->NextState(Neighbors, rule) : DeadState::Instance();
}

int Cell::GetX() const {  //coordonnées des cellules
    return x; 
}
int Cell::GetY() const {
     return y; 
    }