#pragma once
#include "View.hpp"
#include "Grid.hpp"

class ConsoleView : public View {
public:
    ConsoleView(); 
    virtual ~ConsoleView();

    virtual void Render(const Grid& grid) override;
};