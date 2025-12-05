<<<<<<< HEAD
#include <iostream>
=======

>>>>>>> 3505bc405206df4c1f09f32b690e8fcc6c04412e





#include "InterfaceGraph.hpp"
// ou : #include "InterfaceCons.hpp"

int main() {
    Grille grille(50, 50);

    Interface* ui = new InterfaceGraph(50, 50);
    // Interface* ui = new InterfaceCons();

    while (ui->WindowsOpen()) {
        ui->ShowGrid(&grille);
        grille.Evoluer();  // Exemple
    }

    delete ui;
    return 0;
}
