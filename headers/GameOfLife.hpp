#pragma once
#include <string>
#include "Grid.hpp"
#include "View.hpp"
#include "Rule.hpp"

class GameOfLife {
private:

    Grid* currentGrid;
    Grid* nextGrid;
    View* view;
    Rule* activeRule;
    int width, height;

public:
    GameOfLife(const std::string& filename, View* view, Rule* rule);
    ~GameOfLife();
    void NextGen();
    void Run();
};