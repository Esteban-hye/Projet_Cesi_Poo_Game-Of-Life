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
    GameOfLife(const std::string& filename, View* view, Rule* rule); //constructeur du jeu
    ~GameOfLife();//destructeur du jeu
    void NextGen();//méthode pour passer à la génération suivante
    void Run(); //méthode pour lancer le jeu
};