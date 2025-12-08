#pragma once
#include "Grid.hpp"
#include <string>

//charge et sauvegarde les grilles
//string pour le noms du fichier
class file{
    public : 
    static Grid* LoadGrid(const std::string& filename); //charge la grille depuis un fichier, static pour être appelé sans instance
    static void SaveGrid(const std::string& filename, const Grid& grille); //sauvegarde la grille dans un fichier

};