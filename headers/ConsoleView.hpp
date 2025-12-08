#pragma once
#include "View.hpp"

// ERREUR ICI AVANT : class GraphicalView : public View
class ConsoleView : public View { 
public:
    ConsoleView(); // Constructeur vide
    virtual ~ConsoleView();

    virtual void Render(const Grid& grid) override;
    virtual bool IsOpen() const override;
};