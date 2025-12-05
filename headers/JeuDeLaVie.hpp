#pragma once
#include "Grille.hpp"
#include "Interface.hpp"
#include <string>

class JeuDeLaVie{
    private:
    Grille* grille;
    Interface* interface;
    int nbIteration;
    bool Mode;
    std::string fichier;

    public :

    JeuDeLaVie(const std::string& fichier, bool Mode);
    ~JeuDeLaVie();
    void Init();
    void ExeConsole();
    void ExeGraphique();
    void Chargerfichier();
    void Savefichier();
};

