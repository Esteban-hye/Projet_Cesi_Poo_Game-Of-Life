class Cellule {
    protected :
    bool vivant;

    public :
    Cellule(bool etat=false): vivant(etat){}
    virtual bool EstVivant();
    virtual ~Cellule(){}
}