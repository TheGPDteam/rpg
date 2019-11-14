#ifndef ECRANGENERAL_H
#define ECRANGENERAL_H

#include "controleur.h"
#include "dictionnairedeboutons.h"
#include "observateur.h"
#include "policetexte.h"
#include "outilsvue.h"
#include "gestionnaireressource.h"

class EcranGeneral : public DictionnaireDeBoutons, public Observateur
{
protected :
    Controleur* m_controleur;
    SDL_Surface * m_fond;
    SDL_Rect m_ecran = {0, 0, WIDTH_FENETRE_PRINCIPALE, HEIGHT_FENETRE_PRINCIPALE};
    GestionnaireRessource* m_gestionnaireRessource;

public:
    EcranGeneral(Controleur * controleur, GestionnaireRessource* gestionnaireRessource);

    void afficherFondEcran(SDL_Surface* fenetre_affichage);
    virtual void afficherEcran(std::pair<int, int> coord_souris, SDL_Surface* fenetre_affichage) = 0;
    virtual void gestionDesEvenements(Controleur *controleur, bool &quitter_jeu, bool &clique_souris, std::pair<int, int> &coord_souris) = 0;

    virtual ~EcranGeneral();
};

#endif // ECRANGENERAL_H
