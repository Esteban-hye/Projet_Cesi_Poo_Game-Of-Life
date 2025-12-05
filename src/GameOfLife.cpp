#include "../headers/GameOfLife.hpp"
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>


GameOfLife::GameOfLife(const std::string& fichier, bool mode)
    : Grid(nullptr), interface(nullptr), nbIteration(0),
      Mode(mode), fichier(fichier)
{
}


GameOfLife::~GameOfLife()
{
    delete Grid;
    delete interface;
}


void GameOfLife::Init()
{
    if (!Grid)
        Grid = new Grid();

    if (!fichier.empty())
        ChargerFichier();

    if (!interface)
        interface = new Interface();
}


void GameOfLife::ExeConsole()
{
    Init();

    bool continuer = true;

    while (continuer)
    {
        system("clear"); 

        interface->AfficherConsole(*Grid);

        Grid->MettreAJour(); 

        std::this_thread::sleep_for(std::chrono::milliseconds(200));


    }
}


void GameOfLife::ExeGraphique() {
    Init();

    interface->WindowsOpen();

     while (interface->WindowsOpen()) {

        interface->ShowGrid(Grid);

        Grid->Update();

        sf::sleep(sf::milliseconds(100));
} }



void GameOfLife::ChargerFichier()
{
    std::ifstream in(fichier);

    if (!in.is_open())
    {
        std::cerr << "Error, the file is not correct" << fichier << std::endl;
        return;
    }

    int x = 0, y = 0;
    std::string ligne;

    while (std::getline(in, ligne))
    {
        y = 0;
        for (char c : ligne)
        {
            if (c == '1')
                Grid->SetCelluleVivante(x, y, true);
            else
                Grid->SetCelluleVivante(x, y, false);

            y++;
        }
        x++;
    }

    in.close();
}



void GameOfLife::SaveFichier()
{
    std::ofstream out("save.txt");

    if (!out.is_open())
    {
        std::cerr << "Error, unable to save" << std::endl;
        return;
    }

    for (int i = 0; i < Grid->GetLargeur(); i++)
    {
        for (int j = 0; j < Grid->GetHauteur(); j++)
        {
            out << (Grid->GetCellule(i, j).EstVivant() ? '1' : '0');
        }
        out << "\n";
    }

    out.close();
}



