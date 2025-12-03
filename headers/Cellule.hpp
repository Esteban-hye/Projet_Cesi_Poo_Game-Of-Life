#pragma once

class Cellule {
    protected :
    bool vivant;
    int x;
    int y;

    public :
    Cellule(int x, int y, bool vivant);
    virtual bool EstVivant()  const;
    virtual ~Cellule();
    int GetX() const;
    int GetY() const;

};