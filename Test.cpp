#include <iostream>
#include <cassert> 
#include "headers/Grid.hpp"
#include "headers/Cell.hpp"
#include "headers/AliveState.hpp"
#include "headers/DeadState.hpp"
#include "headers/RuleClassic.hpp"
#include "headers/ObstacleState.hpp" 

void TestEtatCellule(){
    std::cout << "[Test] Etat cellule ";
    
    Cell c(0, 0, new DeadState()); // On crée une cellule avec un état initial
    assert(c.IsAlive() == false); 
    c.SetState(new AliveState()); // On change l'état
    assert(c.IsAlive() == true);  

    std::cout << "Test Réussi avec succes" << std::endl;
}

void TestVoisins(){
    std::cout << "[Test] Comptage voisins";
    Grid g(10, 10);
    g.SetCellAlive(0, 0); // On place 3 cellules vivantes
    g.SetCellAlive(1, 0);
    g.SetCellAlive(2, 0);

    int voisins = g.CountAliveNeighbors(1, 1);     // Compte les voisin de 1 1
    assert(voisins == 3); 
    std::cout << "Test Réussi avec succes" << std::endl;
}


void TestRegles() {
    std::cout << "[Test] Regles Classiques";

    RuleClassic regle;
    assert(regle.CalNewState(2, true) == true);
    assert(regle.CalNewState(3, true) == true);
    assert(regle.CalNewState(1, true) == false); // Sous-population
    assert(regle.CalNewState(4, true) == false); // Surpopulation
    assert(regle.CalNewState(3, false) == true);
    assert(regle.CalNewState(2, false) == false);     // Sinon elle reste morte (false)
    assert(regle.CalNewState(4, false) == false);

    std::cout << "Test Réussi avec succes" << std::endl;
}

int main() {
    std::cout << "LANCEMENT DES TESTS" << std::endl;
    
    TestEtatCellule();
    TestVoisins();
    TestRegles();

    std::cout << "Tout les test on ete validé" << std::endl;
    return 0;
}