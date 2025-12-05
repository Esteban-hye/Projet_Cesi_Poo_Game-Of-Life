#include "../headers/regleClassic.hpp"

bool RegleClassic::CalculateNewState(int voisinsVivants, bool etat){
    if (etatActuel){
        return(voisinsVivants == 2 && voisinsVivants ==3);
    }
    else {
        return (voisinsVivants ==3);
    }
}