#ifndef tuile_h
#define tuile_h

#include "direction.h"

enum TypeTuile {
    Eau=0,
    Sable,
    Herbe,
    Beton,
    Terre,
    Arbre,
    AucunType
};

enum TypeJonction{
    AucuneJonction,
    HautGaucheEntrant,
    HautDroiteSortant,
    HautDroiteEntrant,
    BasDroiteSortant,
    BasDroiteEntrant,
    BasGaucheSortant,
    BasGaucheEntrant,
    Haut,
    Gauche,
    Droite,
    Bas,
    HautGaucheSortant
};

class Tuile
{
protected:
    TypeTuile m_type;
    int m_jonction;
private:
    Direction m_directionChangementZone;

public:
    Direction obtenirDirection() const;
    void definirDirection(Direction dir);
    Tuile(int val);
    TypeTuile obtenirType() const;
    bool obtenirEstMarchable() const;
    bool obtenirPeutApparaitre() const;

    void definirHachageJonction(TypeTuile typeVoisin, TypeJonction positionVoisin);
    int obtenirHachageJonction() const;

    static int hacher(TypeTuile typeVoisin, TypeJonction positionVoisin);
};

#endif
