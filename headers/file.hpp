#pragma once
#include "Grid.hpp"
#include <string>

//charge et sauvegarde les grilles

class file{
    public : 
    static Grid* LoadGrid(const std::string& filename);
    static void SaveGrid(const std::string& filename, const Grid& grille);

};