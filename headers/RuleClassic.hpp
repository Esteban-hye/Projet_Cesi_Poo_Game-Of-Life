#pragma once
#include "Rule.hpp"

class RuleClassic : public Rule {
    public : 
     bool CalNewState(int Neighbors,  bool Alive) const override; //Calcul le nouvel etat selon la regle 
};