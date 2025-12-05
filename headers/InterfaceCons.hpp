#ifndef INTERFACE_CONS_HPP
#define INTERFACE_CONS_HPP

#include "Interface.hpp"

class InterfaceCons : public Interface {
public:
    InterfaceCons() = default;

    void ShowGrid(Grid* Grid) override;
    bool WindowsOpen() override;
};

#endif


