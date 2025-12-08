#include "../headers/RuleCustom.hpp"

bool RuleCustom::CalNewState(int Neighbors, bool Alive) const{
    if (Alive){
        return(Neighbors== 2 || Neighbors==3); // si une cellule vivante à 2 ou 3 voisins vivant elle meur
    }
    else {
        return (Neighbors==3 || Neighbors ==6); // si une cellule morte à  3 voisins vivant ou 6 elle devient vivante 
    }
}