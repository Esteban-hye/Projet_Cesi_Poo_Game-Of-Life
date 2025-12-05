#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "InterfaceCons.hpp"
#include "InterfaceGraph.hpp"

// ---------------------------------------------------------
// Grille factice MINIMALE pour tester l'interface
// ---------------------------------------------------------
class FakeCell {
public:
    bool vivant;
    FakeCell(bool v = false) : vivant(v) {}
    bool EstVivant() const { return vivant; }
};

class FakeGrille {
private:
    int largeur;
    int hauteur;
    std::vector<std::vector<FakeCell>> cells;

public:
    FakeGrille(int w, int h) : largeur(w), hauteur(h) {
        cells.resize(h, std::vector<FakeCell>(w));
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                cells[y][x] = FakeCell(rand() % 2);
    }

    int GetLargeur() const { return largeur; }
    int GetLongeur() const { return hauteur; }
    FakeCell* GetCellule(int x, int y) { return &cells[y][x]; }
};
// ---------------------------------------------------------

int main() {
    srand(time(nullptr));

    std::cout << "Choisir interface :" << std::endl;
    std::cout << "1 - Console" << std::endl;
    std::cout << "2 - Graphique" << std::endl;
    std::cout << "Votre choix : ";

    int choix;
    std::cin >> choix;

    FakeGrille grille(30, 20); // petite grille de test

    Interface* interface = nullptr;

    if (choix == 1) {
        interface = new InterfaceCons();
    } 
    else if (choix == 2) {
        interface = new InterfaceGraph(30, 20, 20);
    }
    else {
        std::cout << "Choix invalide.\n";
        return 0;
    }

    while (interface->WindowsOpen()) {
        interface->ShowGrid(reinterpret_cast<Grille*>(&grille));
    }

    delete interface;
    return 0;
}
