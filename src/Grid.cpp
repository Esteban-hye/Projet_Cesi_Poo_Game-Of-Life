#include "../headers/Grid.hpp"
#include "../headers/DeadState.hpp"
#include "../headers/AliveState.hpp"
#include "../headers/ObstacleState.hpp"

Grid::Grid(int width, int height) : width(width), height(height) {
    cells.resize(width);
    for (int x = 0; x < width; ++x) {
        cells[x].resize(height);
        for (int y = 0; y < height; ++y) {
            cells[x][y] = Cell(x, y, DeadState::Instance());
        }
    }
}

Grid::~Grid() {
}

Cell* Grid::GetCell(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return &cells[x][y];
    }
    return nullptr;
}

const Cell* Grid::GetCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return &cells[x][y];
    }
    return nullptr;
}

int Grid::CountAliveNeighbors(int x, int y) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (cells[nx][ny].IsAlive()) count++;
            }
        }
    }
    return count;
}

void Grid::SetCellAlive(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        cells[x][y].SetState(AliveState::Instance());
        aliveCells.insert({x, y});
    }
}

void Grid::SetCellDead(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        cells[x][y].SetState(DeadState::Instance());
        aliveCells.erase({x, y});
    }
}

void Grid::SetObstacle(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        cells[x][y].SetState(ObstacleState::Instance());
        obstacles.insert({x, y});
        aliveCells.erase({x, y});
    }
}

std::set<Position> Grid::GetCellsToCheck() const {
    std::set<Position> toCheck;
    
    for (const auto& pos : aliveCells) {
        toCheck.insert(pos);
        
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = pos.x + dx;
                int ny = pos.y + dy;
                
                if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                    if (obstacles.find({nx, ny}) == obstacles.end()) {
                        toCheck.insert({nx, ny});
                    }
                }
            }
        }
    }
    
    return toCheck;
}