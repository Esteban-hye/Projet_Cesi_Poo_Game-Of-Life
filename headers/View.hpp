#pragma once
#include "Grid.hpp"

class View {
public:
    virtual ~View() = default;
    virtual void Render(const Grid& grid) = 0;

    // --- CETTE LIGNE EST OBLIGATOIRE ---
    virtual bool IsOpen() const = 0; 
    // -----------------------------------
};