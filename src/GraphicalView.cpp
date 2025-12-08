#include "../headers/GraphicalView.hpp"

// Constructeur : initialise la fenêtre graphique
GraphicalView::GraphicalView(int width, int height, float cellSize) : cellSize(cellSize) { 
    // Création de la fenêtre SFML, taille = largeur*tailleCell, hauteur*tailleCell
    window = new sf::RenderWindow(sf::VideoMode(width * cellSize, height * cellSize), "Game of Life");
    window->setFramerateLimit(5);     // Limite le nombre d'images par seconde
}
// Destructeur : ferme et détruit la fenêtre correctement

GraphicalView::~GraphicalView(){
    if (window){
        window->close();
        delete window;
    }
}

void GraphicalView::Render(const Grid& grid) { // Affichage de la grille à l’écran
    sf::Event event; //permet de savoir ce que fait l'utilisateur
    // Permet de savoir quand la fenêtre est fermée
    while (window->pollEvent(event)) {
        if (event.type ==sf::Event::Closed)
            window->close();
    }
    window->clear();  // efface la fenêtre avant de redessiner
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    for (int x =0; x< grid.GetWidth();++x) {     // Parcourt les cellules de la grille
        for (int y= 0;y< grid.GetHeight();++y){
           const Cell* currentCell= grid.GetCell(x,y);
            if (currentCell->IsObstacle()) {
                cell.setPosition(x *cellSize, y *cellSize);
                cell.setFillColor(sf::Color(128, 128, 128)); //si c'est un obstacle c'est gris
                window->draw(cell);
            }
            else if(currentCell->IsAlive()){
                cell.setPosition(x *cellSize, y* cellSize);
                cell.setFillColor(sf::Color::White); // Si la cellule est vivante → couleur blanche
                window->draw(cell);
            }
        } //si c'est mort, ça reste vide
    }

    window->display(); // affiche tout à l’écran
}