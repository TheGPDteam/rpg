#ifndef modele_h
#define modele_h

#include <string>
#include <typeinfo>
#include "../direction.h"
#include "humain.h"
#include "temps.h"
#include "carte.h"
#include "campement.h"
#include "combat.h"
#include "joueur.h"
#include "utilitaires.h"
#include "typedefaite.h"

class Modele
{
private:
    TypeDefaite m_td;
    Temps m_temps;
    Carte m_carte;
    Campement m_campement;
    Combat m_combat;
    Joueur m_joueur;
    std::string m_nomPartie;
    int m_deplacementDepuisDernierCombat;

    unsigned int m_vivresConsommesNuit;
    unsigned int m_nbPersosMorts;
    unsigned int m_nbZombiesTues;
    unsigned int m_nbZombiesAttaquant;

    unsigned int m_nbJoursPasses;

    bool testerDeplacement(Direction &dir);

    bool m_perdu;
public:
    Humain* m_nouvelArrivant;

    Modele();
    void premiereJournee();
    Humain *journeeSuivante();
    std::string obtenirNomPartie() const;
    void definirNomPartie(std::string nom);
    void deplacement(Direction dir);
    bool testChangementDeCarte(Direction dir);
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
    void charger(const std::string &donnees);
    void reinitialiserTemps();

    void finJournee();

    unsigned int obtenirVivresConsommesNuit() const;
    unsigned int obtenirNbPersosMorts() const;
    unsigned int obtenirNbZombiesTues() const;
    unsigned int obtenirNbZombiesAttaquants() const;

    bool perdu();
    TypeDefaite obtenirTypeDefaite() const;
};

#endif
