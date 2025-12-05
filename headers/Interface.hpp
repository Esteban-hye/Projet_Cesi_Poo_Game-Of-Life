#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Grid.hpp"

class Interface {
public:
    virtual ~Interface() = default;

    virtual void ShowGrid(Grid* Grid) = 0;
    virtual bool WindowsOpen() = 0;
};

#endif
