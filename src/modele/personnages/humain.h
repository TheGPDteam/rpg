#ifndef humain_h
#define humain_h

#include <fstream>
#include <iostream>
#include "../survie/experience/competence.h"
#include "string"
#include "../objets/armes/arme.h"
#include "../survie/experience/niveau.h"
#include "personnage.h"
#include "../utilitaires.h"

enum Genre {
    Homme,
    Femme,
    Inconnu
};

class Humain : public Personnage
{
protected:
    std::string m_nom;
    std::string m_prenom;
    Genre m_genre;

    Competence m_chasse;
    Competence m_recolte;
    Competence m_campement;
    unsigned short m_coutEntretien;
    Niveau m_niveau;
    Arme* m_arme;
    int m_consommation;
public:
    Humain();
    Competence obtenirChasse() const;
    Competence obtenirRecolte() const;
    Competence obtenirCampement() const;
    std::string obtenirNom() const;
    void definirNom(std::string nom);
    std::string obtenirPrenom() const;
    Arme* obtenirArme() const;
    void definirArme(Arme *arme);
    unsigned short obtenirEntretien() const;
    void definirEntretien(unsigned short entretien);
    Niveau obtenirNiveau();
    unsigned short obtenirDegats() override;
    unsigned short obtenirVitesse() override;
    void augmenterExperience(int exp);
    int obtenirConsommation() const;
    std::string serialiser() const override;
    void charger(const std::string &donnees);
};

#endif
