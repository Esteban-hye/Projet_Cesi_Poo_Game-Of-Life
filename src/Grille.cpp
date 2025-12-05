#include "../headers/Grille.hpp"


Grille::Grille(int Largeur, int Longeur):Largeur(Largeur), Longeur(Longeur){
    c = new cellules*[Largeur * Longeur]
   for (int x=0; x<Largeur; x++){
    for (int y=0; y<Longeur; y++){
        int i = y = y* largeur +x;
        c[i] = new Cellule(x,y, new EtatCellule());
    }
}
}


Cellule* Grille::GetCellule(int x, int y) const {
    int i = y*Largeur +x;
    return cellules[i];
}


void Grille::SetRegle(Regle* regle){

}


int Grille::CompterVoisinsVivants(int x, int y) const {
    int nbvoisins = 0;
    for(int a= -1; a<=1;a++){
        for(int b =-1;b<=1; b++){
            if(a == 0 && b==0) continue;
            int c = x+a;
            int d =y+b;

            Cellule* voisin = GetCellule(c,d);
            if(voisin != nullptr && voisin->EstVivant()){
                nbvoisins++;
            }
        }
    }
    return nbvoisins;
}


Grille ::~Grille(){
    for(int i=0; i<largeur*hauteur; i++){
        delete cellules[i];
    }
}


void Grille::Maj() {
    CalculerGen();
}

int Grille::GetLongeur(){
    return longeur;
}

int Grille::GetLargeur(){
    return largeur;
}

void Grille::Maj{
}