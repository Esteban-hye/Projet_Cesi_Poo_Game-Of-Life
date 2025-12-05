#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Grille.hpp"

class Interface {
public:
    virtual ~Interface() = default;

    // Méthodes abstraites
    virtual void ShowGrid(Grille* grille) = 0;
    virtual bool WindowsOpen() = 0;
};

#endif
