#pragma once
#include "Rule.hpp"

class RuleCustom : public Rule {
    public : 
     bool CalNewState(int Neighbors,  bool Alive) const override; //Calcul le nouvel etat selon la regle 
};