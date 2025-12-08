#pragma once
#include "View.hpp"
#include <SFML/Graphics.hpp>

class GraphicalView : public View {
private:
    sf::RenderWindow* window;
    float cellSize;

public:
    GraphicalView(int width, int height, float cellSize);
    virtual ~GraphicalView();

    virtual void Render(const Grid& grid) override;

    // --- CETTE LIGNE EST OBLIGATOIRE ---
    virtual bool IsOpen() const override;
    // -----------------------------------
};