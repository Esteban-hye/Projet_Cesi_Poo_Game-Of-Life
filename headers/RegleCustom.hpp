#pragma once
#include "Regle.hpp"

class RegleCustom : public Regle {
    public : 
     bool CalculerNouvelEtat(int VoisinsVivants,  bool EtatActuel) override;
};