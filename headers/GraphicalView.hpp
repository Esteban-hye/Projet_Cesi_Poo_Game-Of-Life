#pragma once
#include "View.hpp"
#include <SFML/Graphics.hpp>

class GraphicalView : public View {
private:
    sf::RenderWindow* window;
    float cellSize;

public:
    GraphicalView(int width,int height,float cellSize =10.0f);
    virtual ~GraphicalView();
    void Render(const Grid& grid) override;
};