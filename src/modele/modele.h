#ifndef modele_h
#define modele_h

#include <string>
#include "../direction.h"
#include "humain.h"
#include "temps.h"
#include "carte.h"
#include "campement.h"
#include "combat.h"
#include "joueur.h"

class Modele
{
private:
    Temps m_temps;
    Carte m_carte;
    Campement m_campement;
    Combat m_combat;
    Joueur m_joueur;
    std::string m_nomPartie;
    int m_deplacementDepuisDernierCombat;

    Humain* m_nouvelArrivant;

    bool testerDeplacement(Direction &dir);
public:
    Modele();
    void premiereJournee();//TO-DO
    Humain journeeSuivante();//TO-DO
    void acceptationNouveauSurvivant();
    std::string obtenirNomPartie() const;
    void definirNomPartie(std::string nom);
    void deplacement(Direction dir);
    void lancerCombat();//TO-DO


    Temps *obtenirTemps();
    void definirTemps(Temps temps);
    Carte* obtenirCarte() ;
    void definirCarte(Carte carte);
    Campement *obtenirCampement() ;
    void definirCampement(Campement campement);
    Combat *obtenirCombat();
    void definirCombat(Combat combat);
    Joueur *obtenirJoueur() ;
    void definirJoueur(Joueur joueur);
    std::string serialiser() const;
};

#endif
