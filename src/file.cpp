#include "../headers/file.hpp"
#include "../headers/ObstacleState.hpp"
#include <fstream>
#include <iostream>

Grid* file::LoadGrid(const std::string& filename) { // Charge une grille depuis un fichier
    std::ifstream file(filename); // On ouvre le fichier en lecture

    if (!file.is_open()){
        std::cerr << "Erreur fichier s ouvre pas "<<filename << std::endl;
    }

    int height; 
    int width;
    file>>height >>width; // On lit la taille de la grille (hauteur, largeur)
    Grid* newGrid = new Grid(width, height); // On crée une grille vide de cette taille

    int val;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) { //place les cellules selon le fichier
            file >> val;
            if (val == 2) {
                newGrid->SetObstacle(x, y); //place les obstacles
            }
            else if (val == 1) {
                newGrid->SetCellAlive(x, y); //places les cellules vivantes
            }
        }
    }

    file.close();  // On ferme le fichier
    std::cout << "Grille chargee:" << width << "x" << height<<std::endl;
    std::cout << "Cellules vivantes:"<<newGrid->GetAliveCells().size() << std::endl;
    std::cout << "Obstacles:"<< newGrid->GetObstacles().size() <<std::endl;
    return newGrid;
}

void file::SaveGrid(const std::string& filename, const Grid& grid) { // Sauvegarde la grille dans un fichier

    std::ofstream file(filename);
    
    if (file.is_open()) { 
        file << grid.GetHeight() <<" "<< grid.GetWidth() << std::endl;
        
        for (int y = 0; y < grid.GetHeight(); ++y) { //écriture des cellules dans le fichier
            for (int x = 0; x < grid.GetWidth(); ++x) {
                const Cell* cell = grid.GetCell(x, y);
                if (cell->IsObstacle()) {
                    file <<"2"; //obstacles
                }
                else if (cell->IsAlive()) {
                    file <<"1"; //vivantes 
                }
                else {
                    file <<"0 "; //mortes
                }
            }
            file << std::endl;
        }
        std::cout << "Grille sauvegardee  " << filename << std::endl;
    }
}