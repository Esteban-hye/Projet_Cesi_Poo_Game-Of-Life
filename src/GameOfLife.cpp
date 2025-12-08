#include "../headers/GameOfLife.hpp"
#include "../headers/file.hpp"
#include "../headers/DeadState.hpp"
#include "../headers/ObstacleState.hpp"
#include <thread>
#include <chrono>
#include <iostream>

GameOfLife::GameOfLife(const std::string& filename, View* view, Rule* rule): view(view),activeRule(rule) {
    
    currentGrid= file::LoadGrid(filename);
    width =currentGrid->GetWidth();
    height =currentGrid->GetHeight();
    nextGrid =new Grid(width, height);
}

GameOfLife::~GameOfLife() {
    delete currentGrid;
    delete nextGrid;
}

void GameOfLife::NextGen() {
    for (int x= 0; x < width;++x) {
        for (int y= 0; y < height;++y) {
            Cell* currentCell = currentGrid->GetCell(x, y);
            if (currentCell->IsObstacle()) {
                nextGrid->GetCell(x, y)->SetState(ObstacleState::Instance());
            }
            else {
                int neighbors =currentGrid->CountAliveNeighbors(x, y);
                CellState* nextState =currentCell->CalculNext(neighbors, activeRule);
                nextGrid->GetCell(x, y)->SetState(nextState);
            }
        }
    }
    std::swap(currentGrid, nextGrid);
}

void GameOfLife::Run() {
    while (true) {
        view->Render(*currentGrid);
        NextGen();
    }
}

void GameOfLife::Save(const std::string& filename) {
    file::SaveGrid(filename, *currentGrid);
}