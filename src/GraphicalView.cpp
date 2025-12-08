#include "../headers/GraphicalView.hpp"

// CONSTRUCTEUR
GraphicalView::GraphicalView(int width, int height, float cellSize) 
    : cellSize(cellSize) {
    
    // 1. Création de la fenêtre
    // width * cellSize = largeur totale en pixels
    window = new sf::RenderWindow(sf::VideoMode(width * cellSize, height * cellSize), "Jeu de la Vie - Esteban");
    
    // 2. Limite de vitesse (5 FPS pour bien voir l'animation)
    window->setFramerateLimit(5);
}

// DESTRUCTEUR
GraphicalView::~GraphicalView() {
    if (window) {
        window->close();
        delete window;
    }
}

// --- FONCTION VITALE POUR QUE LE JEU S'ARRÊTE ---
bool GraphicalView::IsOpen() const {
    return window->isOpen();
}
// -----------------------------------------------

// AFFICHAGE
void GraphicalView::Render(const Grid& grid) {
    // 1. GESTION DES ÉVÉNEMENTS (Indispensable pour fermer la fenêtre)
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }

    // Sécurité : si la fenêtre est fermée, on arrête le dessin
    if (!window->isOpen()) return;

    // 2. DESSIN
    window->clear(); // Fond noir par défaut

    // On prépare la forme du carré
    // On enlève 1.0f pour faire une petite bordure noire entre les cellules
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    for (int x = 0; x < grid.GetWidth(); ++x) {
        for (int y = 0; y < grid.GetHeight(); ++y) {
            
            // On récupère la cellule
            const Cell* currentCell = grid.GetCell(x, y);

            // A. Cas OBSTACLE -> GRIS
            if (currentCell->IsObstacle()) {
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(sf::Color(128, 128, 128)); // Gris
                window->draw(cell);
            }
            // B. Cas VIVANT -> BLANC
            else if (currentCell->IsAlive()) {
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(sf::Color::White); // Blanc
                window->draw(cell);
            }
            // C. Cas MORT -> On ne dessine rien (on laisse le fond noir)
        }
    }

    // On affiche l'image finale
    window->display();
}