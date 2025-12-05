#pragma once
#include "GameOfLife.hpp"
#include <string>

class fichier{
    public : 
    static Grid* ChargerGrid(std::string& fichier);
    void SauvegarderGrid(std::string& fichier,Grid*) Grid;

};