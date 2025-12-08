#include "../headers/GraphicalView.hpp"

GraphicalView::GraphicalView(int width, int height, float cellSize) : cellSize(cellSize) {
    window = new sf::RenderWindow(sf::VideoMode(width * cellSize, height * cellSize), "Game of Life");
    window->setFramerateLimit(5);
}

GraphicalView::~GraphicalView(){
    if (window){
        window->close();
        delete window;
    }
}

void GraphicalView::Render(const Grid& grid) {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type ==sf::Event::Closed)
            window->close();
    }
    window->clear(); 
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    for (int x =0; x< grid.GetWidth();++x) {
        for (int y= 0;y< grid.GetHeight();++y){
           const Cell* currentCell= grid.GetCell(x,y);
            if (currentCell->IsObstacle()) {
                cell.setPosition(x *cellSize, y *cellSize);
                cell.setFillColor(sf::Color(128, 128, 128)); 
                window->draw(cell);
            }
            else if(currentCell->IsAlive()){
                cell.setPosition(x *cellSize, y* cellSize);
                cell.setFillColor(sf::Color::White); 
                window->draw(cell);
            }
        }
    }

    window->display();
}