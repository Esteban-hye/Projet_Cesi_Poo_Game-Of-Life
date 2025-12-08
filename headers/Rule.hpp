#pragma once

// class abstraite qui definie les regles 

class Rule {
    public : 
    virtual ~Rule() = default;
    virtual bool CalNewState(int Neighbors,  bool Alive) const = 0; //Calcul le nouvel etat selon la regle 


};