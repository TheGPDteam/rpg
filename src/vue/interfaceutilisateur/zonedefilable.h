#ifndef ZONEDEFILABLE_H
#define ZONEDEFILABLE_H

#include "affichable.h"
#include "cliquable.h"


class ZoneDefilable : public Cliquable, public Affichable
{
private:
    const float VITESSE_DEFILEMENT = 0.1;
    SDL_Rect m_fenetreGlissante;
    Affichable * m_contenu;

    SDL_Rect zone() const override;
public:
    ZoneDefilable() = delete;
    ZoneDefilable(Affichable *contenu, Controleur * controleur, bool actif, SDL_Rect rectangle);

    void afficher(SDL_Surface *surface) override;
    void redimensionner(SDL_Rect m_rectangle) override;

    void clique() override;
    void defiler(bool haut);
};

#endif // ZONEDEFILABLE_H