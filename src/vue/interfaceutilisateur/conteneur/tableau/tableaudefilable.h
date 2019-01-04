#ifndef TABLEAUDEFILABLE_H
#define TABLEAUDEFILABLE_H

#include "tableau.h"
#include "zonedefilable.h"
#include "affichable.h"
#include "ligne.h"


class TableauDefilable : Affichable
{
private :
    SDL_Rect m_rectDonnees;
    float m_hauteurLigne;
    Controleur * m_controleur;
    Tableau * m_tableauEntete;
    Tableau * m_tableauDonnee;
    ZoneDefilable * m_zoneDefilableDonnees;
    void ajoutertitre(std::string titre);
    void ajouterEnTeteHumain();
    void ajouterEnTeteObjet(TypeObjet typeObjet);
    TableauDefilable(SDL_Rect rect, Controleur *controleur, float hauteurLigne);
    static TableauDefilable * creationTableauDefilableDefaut(SDL_Rect rect, Controleur *controleur, const std::string titre, bool aUneImage, float hauteurLigne);

public:
    void afficher(SDL_Surface *surface) override;
    void redimensionner(SDL_Rect m_rectangle) override;
    static TableauDefilable * tableauHumain(SDL_Rect rect, Controleur *controleur, const std::string titre, bool aUneImage, float hauteurLigne=32);
    static TableauDefilable * tableauObjet(SDL_Rect rect, Controleur *controleur, const std::string titre, bool aUneImage, TypeObjet typeObjet=TypeObjet::Objet, float hauteurLigne=64);
    static TableauDefilable * tableau(SDL_Rect rect, Controleur *controleur, const std::string titre, bool aUneImage, std::vector<std::string> nomColoneEnTete = std::vector<std::string>(), float hauteurLigne=32);
    Ligne * gestionEvenementClique(std::pair<int, int> &coord_souris);
    void trieDefault();
    bool gestionAffichageLigneSurvole(std::pair<int, int> coord_souris);
    std::pair<int, int> coordSourisElement(std::pair<int, int> &coord_sourisEcran);
    ~TableauDefilable() override;

    //methode de tableau
    void vider();
    void ajouterLigne(std::vector<Affichable*> affichables);
    void ajouterLigne(std::vector<std::string> strings);
    void ajouterLigne(Humain* perso);
    void ajouterLigne(Objet* obj);
    void ajouterLigne(Campement *c);
};

#endif // TABLEAUDEFILABLE_H