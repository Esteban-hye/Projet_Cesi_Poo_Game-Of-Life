#include "../headers/Cell.hpp"
#include "../headers/DeadState.hpp"
#include "../headers/AliveState.hpp"
#include "../headers/ObstacleState.hpp"

Cell::Cell() : x(0), y(0) {
    currentState = DeadState::Instance(); 
}
Cell::Cell(int x, int y, CellState* InitialState) 
    : x(x), y(y), currentState(InitialState) {
    if (!currentState) currentState = DeadState::Instance();
}

Cell::Cell(const Cell& other) : x(other.x), y(other.y) { //copie
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

Cell& Cell::operator=(const Cell& other) {
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

bool Cell::IsAlive() const {
    return currentState ? currentState->IsAlive() : false;
}

bool Cell::IsObstacle() const {
    return currentState ? currentState->IsObstacle() : false;
}

void Cell::SetState(CellState* NewState) {
    currentState = NewState;
}

CellState* Cell::CalculNext(int Neighbors, const Rule* rule) const {
    return currentState ? currentState->NextState(Neighbors, rule) : DeadState::Instance();
}

int Cell::GetX() const { 
    return x; 
}
int Cell::GetY() const {
     return y; 
    }