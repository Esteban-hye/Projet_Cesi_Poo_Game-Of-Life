#pragma once
#include "Regle.hpp"

class RegleClassic : public Regle {
    public : 
     bool CalculerNouvelEtat(int VoisinsVivants,  bool EtatActuel) override;
};