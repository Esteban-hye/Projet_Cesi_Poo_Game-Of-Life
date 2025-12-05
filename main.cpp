#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Grid.hpp"
#include "Interface.hpp"
#include "InterfaceCons.hpp"
#include "InterfaceGraph.hpp"

int main() {
    srand(time(nullptr));

    int largeur = 30;
    int longueur = 20;

    std::cout << "Please choose your mode : " << std::endl;
    std::cout << "1 - Console" << std::endl;
    std::cout << "2 - graphic mode" << std::endl;
    std::cout << "Your choice : ";

    int choice;
    std::cin >> choice;

    Grid grid(largeur, longueur);

    Interface* interface = nullptr;

    if (choice == 1) {
        interface = new InterfaceCons();
    }
    else if (choice == 2) {
        interface = new InterfaceGraph(largeur, longueur, 20);
    }
    else {
        std::cout << "Invalid choice.\n";
        return 0;
    }

    while (interface->WindowsOpen()) {
        interface->ShowGrid(&grid);
        grid.Maj(); 
    }

    delete interface;
    return 0;
}
