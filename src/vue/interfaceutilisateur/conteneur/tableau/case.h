#ifndef CASE_H
#define CASE_H

#include "affichable.h"
#include <iostream>
#include "zonetexte.h"
#include "policetexte.h"
#include "cliquable.h"


class Case : public Affichable, public Cliquable
{
private :
    Affichable* m_donnee;

public :
    Case(SDL_Rect rect, Affichable * donnee, Controleur * controleur);
    Case() = delete;
    ~Case();

    void afficher(SDL_Surface *surface) override;
    void redimensionner(SDL_Rect m_rectangle) override;
    void clique() override;

    void definirDonnee(Affichable* donnee);
    Affichable* obtenirDonnee() const;
    SDL_Rect zone() const;
};

#endif // CASE_H
