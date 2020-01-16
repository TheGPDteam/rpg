#ifndef modele_h
#define modele_h

#include <string>
#include <typeinfo>
#include "../direction.h"
#include "./personnages/humain.h"
#include "./temps.h"
#include "./environnement/carte/carte.h"
#include "./environnement/campement.h"
#include "./survie/combat/combat.h"
#include "joueur.h"
#include "./utilitaires.h"
#include "./survie/typedefaite.h"
#include "zonechangementzone.h"

class Modele : public Observable
{
private:
    std::string m_nomObjetRecompense;

    Joueur m_joueur;
    int m_deplacementDepuisDernierCombat;
    Humain* m_nouvelArrivant;
    bool m_perdu;
    unsigned int m_nbPersosMorts;
    unsigned int m_nbZombiesAttaquant;
    unsigned int m_nbZombiesTues;
    TypeDefaite m_td;

    Temps* m_temps;
    Carte m_carte;
    Campement m_campement;
    Combat m_combat;
    std::string m_nomPartie;    
    unsigned int m_vivresConsommesNuit;
    unsigned int m_nbJoursPasses;

    bool testerDeplacement(Direction &dir);

    void tuerPersos();

public:
    Modele();

    std::string obtenirRecompense() const;
    void premiereJournee();
    Humain *journeeSuivante();
    std::string obtenirNomPartie() const;
    void definirNomPartie(std::string nom);
    void deplacement(Direction dir);
    bool testChangementDeCarte(Direction dir);
//    void lancerCombat();//TO-DO

    Temps* obtenirTemps();
    void definirTemps(Temps temps);
    Carte* obtenirCarte() ;
    void definirCarte(Carte carte);
    Campement *obtenirCampement() ;
    void definirCampement(Campement campement);
    Combat *obtenirCombat();
    void definirCombat(Combat combat);
    Joueur *obtenirJoueur() ;
    Humain * obtenirNouvelArrivant();
    void changerNouvelArrivant(Humain * h);
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
