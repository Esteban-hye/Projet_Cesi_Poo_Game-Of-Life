#pragma once 
#include <list>
#include "Cellule.hpp"



class Grille {
    private :
    Cellule** cellules;
    int largeur;
    int longeur;
    std::list<Cellule*> ListeCVivant;

    public :

    Grille(int largeur, int longeur);
    ~Grille();


    Cellule* GetCellule(int x,int y) const;

    void Maj();
    int CompterVoisinsVivants(int x, int y) const;

    std::list<Cellule*> GetVoisins(int x, int y) const;
    int GetLargeur() const;
    int GetLongeur() const;

    void AddCvivant(Cellule* cellule);
    void SuppCmort(Cellule* cellule);

};