#pragma once

class Regle {
    public : 
    virtual bool CalculerNouvelEtat(int VoisinsVivants,  bool EtatActuel);
    virtual ~Regle();
};