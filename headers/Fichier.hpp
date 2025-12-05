#pragma once
#include "JeuDeLaVie.hpp"
#include <string>

class fichier{
    public : 
    static grille* ChargerGrille(std::string& fichier);
    void SauvegarderGrille(std::string& fichier,Grille*) grille;

};