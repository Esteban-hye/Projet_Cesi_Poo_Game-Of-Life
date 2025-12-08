#pragma once
#include <vector>
#include <set>
#include "Cell.hpp"

//Structure representant une position x y dans la grile Cellules vivante et obstacle
struct Position {
    int x;
    int y;
    bool operator<(const Position& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
        std::set<Position> aliveCells;
    
    // liste obstacle
    std::set<Position> obstacles;

public:
    Grid(int width, int height);
    ~Grid();

    Cell* GetCell(int x, int y);
    const Cell* GetCell(int x, int y) const;

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    
    int CountAliveNeighbors(int x, int y) const;
    
    void SetCellAlive(int x, int y);
    void SetCellDead(int x, int y);
    void SetObstacle(int x, int y);
    
    const std::set<Position>& GetAliveCells() const { return aliveCells; }
    const std::set<Position>& GetObstacles() const { return obstacles; }
    
    std::set<Position> GetCellsToCheck() const;

};