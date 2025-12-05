#pragma once
#include "Grid.hpp"
#include "Interface.hpp"
#include <string>

class GameOfLife{
    private:
    Grid* Grid;
    Interface* interface;
    int nbIteration;
    bool Mode;
    std::string fichier;

    public :

    GameOfLife(const std::string& fichier, bool Mode);
    ~GameOfLife();
    void Init();
    void ExeConsole();
    void ExeGraphique();
    void Chargerfichier();
    void Savefichier();
};

