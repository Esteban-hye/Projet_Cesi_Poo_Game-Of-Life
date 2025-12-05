#include "../headers/JeuDeLaVie.hpp"
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>


JeuDeLaVie::JeuDeLaVie(const std::string& fichier, bool mode)
    : grille(nullptr), interface(nullptr), nbIteration(0),
      Mode(mode), fichier(fichier)
{
}


JeuDeLaVie::~JeuDeLaVie()
{
    delete grille;
    delete interface;
}


void JeuDeLaVie::Init()
{
    if (!grille)
        grille = new Grille();

    if (!fichier.empty())
        ChargerFichier();

    if (!interface)
        interface = new Interface();
}


void JeuDeLaVie::ExeConsole()
{
    Init();

    bool continuer = true;

    while (continuer)
    {
        system("clear"); 

        interface->AfficherConsole(*grille);

        grille->MettreAJour(); 

        std::this_thread::sleep_for(std::chrono::milliseconds(200));


    }
}


void JeuDeLaVie::ExeGraphique() {
    Init();

    interface->WindowsOpen();

     while (interface->WindowsOpen()) {

        interface->ShowGrid(grille);

        grille->Update();

        sf::sleep(sf::milliseconds(100));
} }



void JeuDeLaVie::ChargerFichier()
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
                grille->SetCelluleVivante(x, y, true);
            else
                grille->SetCelluleVivante(x, y, false);

            y++;
        }
        x++;
    }

    in.close();
}



void JeuDeLaVie::SaveFichier()
{
    std::ofstream out("save.txt");

    if (!out.is_open())
    {
        std::cerr << "Error, unable to save" << std::endl;
        return;
    }

    for (int i = 0; i < grille->GetLargeur(); i++)
    {
        for (int j = 0; j < grille->GetHauteur(); j++)
        {
            out << (grille->GetCellule(i, j).EstVivant() ? '1' : '0');
        }
        out << "\n";
    }

    out.close();
}



