#include <SFML/Graphics.hpp>
#include "headers/Interface.hpp"

// ---- Fausse cellule juste pour le test ----
class FakeCellule {
public:
    bool EstVivant() const { return true; }
};

// ---- Fausse grille juste pour le test ----
class FakeGrille {
public:
    int getLargeur() const { return 20; }
    int getHauteur() const { return 20; }
    FakeCellule* getCellule(int, int) { 
        static FakeCellule c;
        return &c;
    }
};

int main() {
    Interface interface(20, 20, 20);
    FakeGrille grille;

    while (interface.WindowsOpen()) {
        interface.ShowGrid((Grille*)&grille); 
        // Cast seulement pour contourner ton prototype sans modifier le .hpp
    }

    return 0;
}
