#include "../headers/file.hpp"
#include "../headers/ObstacleState.hpp"
#include <fstream>
#include <iostream>

Grid* file::LoadGrid(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr << "Erreur fichier s ouvre pas "<<filename << std::endl;
    }

    int height; 
    int width;
    file>>height >>width; 
    Grid* newGrid = new Grid(width, height);

    int val;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file >> val;
            if (val == 2) {
                newGrid->SetObstacle(x, y);
            }
            else if (val == 1) {
                newGrid->SetCellAlive(x, y);
            }
        }
    }

    file.close();
    std::cout << "Grille chargee:" << width << "x" << height<<std::endl;
    std::cout << "Cellules vivantes:"<<newGrid->GetAliveCells().size() << std::endl;
    std::cout << "Obstacles:"<< newGrid->GetObstacles().size() <<std::endl;
    return newGrid;
}

void file::SaveGrid(const std::string& filename, const Grid& grid) {
    std::ofstream file(filename);
    
    if (file.is_open()) {
        file << grid.GetHeight() <<" "<< grid.GetWidth() << std::endl;
        
        for (int y = 0; y < grid.GetHeight(); ++y) {
            for (int x = 0; x < grid.GetWidth(); ++x) {
                const Cell* cell = grid.GetCell(x, y);
                if (cell->IsObstacle()) {
                    file <<"2";
                }
                else if (cell->IsAlive()) {
                    file <<"1";
                }
                else {
                    file <<"0 ";
                }
            }
            file << std::endl;
        }
        std::cout << "Grille sauvegardee  " << filename << std::endl;
    }
}