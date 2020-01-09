#include "actionsboutons.h"


//!
//! \brief Constructeur par défaut
//! \author pgutierrez
//! \date 20/11/16
//! \version 0.1
//!

ActionsBoutons::ActionsBoutons(Controleur * controleur)
    :m_controleur{controleur}
{
}


//!
//! \brief Méthode lançant le jeu principale
//! @return TypeEcran retourne le nouveau type de l'écran
//! \author pgutierrez
//! \date 20/11/16
//! \version 1.0
//!
//! Si un bouton "continuer" est cliqué alors on retourne le nouveau type de l'écran
//!

TypeEcran ActionsBoutons::boutonJeuPrincipal() const {
    m_controleur->obtenirModele()->obtenirTemps()->reprendre();
    return TypeEcran::JeuPrincipal;
}


//!
//! \brief Méthode quittant le jeu
//! @return TypeEcran retourne le nouveau type de l'écran
//! \author pgutierrez
//! \date 20/11/16
//! \version 1.0
//!
//! Si un bouton "quitter" est cliqué alors on quitte le jeu
//!

TypeEcran ActionsBoutons::boutonQuitter() const {
    return TypeEcran::Quitter;
}


//!
//! \brief Méthode lançant l'affichage de l'ecran inventaire
//! @return TypeEcran retourne le nouveau type de l'écran
//! \author pgutierrez
//! \date 25/01/17
//! \version 1.0
//!
//! Si un bouton "Inventaire" est cliqué alors on retourne le nouveau type de l'écran
//!

TypeEcran ActionsBoutons::boutonInventaire() const{
    return TypeEcran::Inventaire;
}


//!
//! \brief Méthode lançant l'affichage de l'ecran equipe
//! @return TypeEcran retourne le nouveau type de l'écran
//! \author pgutierrez
//! \date 25/01/17
//! \version 1.0
//!
//! Si un bouton "Equipe" est cliqué alors on retourne le nouveau type de l'écran
//!

TypeEcran ActionsBoutons::boutonEquipe() const {
    return TypeEcran::Equipe;
}



//!
//! \brief Méthode lançant l'affichage de l'ecran ChoixPersonnage
//! @return TypeEcran retourne le nouveau type de l'écran
//! \author pgutierrez
//! \date 18/10/17
//! \version 1.0
//!
//! Si un bouton "ChoixPersonnage" est cliqué alors on retourne le nouveau type de l'écran
//!
TypeEcran ActionsBoutons::boutonChoixPersonnage() const {
    m_controleur->obtenirModele()->changerNouvelArrivant(new Humain);
    return TypeEcran::ChoixPersonnage;
}

TypeEcran ActionsBoutons::boutonQuete() const {
    return TypeEcran::ChoixQuete;
}

TypeEcran ActionsBoutons::boutonQueteAcceptation(){
    m_controleur->choixNouvelArrivant(true);
    m_controleur->obtenirModele()->obtenirJoueur()->obtenirQuete()->definirValeurObjectif(m_controleur->obtenirModele()->obtenirCampement()->obtenirConsommation());
    return TypeEcran::ChoixQuete;
}

TypeEcran ActionsBoutons::boutonQueteRefus(){
    m_controleur->choixNouvelArrivant(false);
    return TypeEcran::ChoixQuete;
}

TypeEcran ActionsBoutons::lancerExploration() const {
    return TypeEcran::JeuPrincipal;
}

TypeEcran ActionsBoutons::boutonChasseJoueur() const {
    Modele * m =  m_controleur->obtenirModele();
    m->reinitialiserTemps();
    m->obtenirJoueur()->definirEquipe(m->obtenirCampement()->obtenirEquipeChasse());
    return TypeEcran::ChasseJoueur;
}

TypeEcran ActionsBoutons::boutonRecolteJoueur() const {
    Modele * m =  m_controleur->obtenirModele();
    m->reinitialiserTemps();
    m->obtenirJoueur()->definirEquipe(m->obtenirCampement()->obtenirEquipeRecolte());
    m->obtenirJoueur()->obtenirEquipe()->ajouterPersonnage(m->obtenirJoueur()->obtenirPersonnageJoueur());
    return TypeEcran::RecolteJoueur;
}

TypeEcran ActionsBoutons::boutonCampementJoueur() const {
    Modele * m =  m_controleur->obtenirModele();
    m->reinitialiserTemps();
    m->obtenirJoueur()->definirEquipe(m->obtenirCampement()->obtenirEquipeCampement());
    m->obtenirJoueur()->obtenirEquipe()->ajouterPersonnage(m->obtenirJoueur()->obtenirPersonnageJoueur());
    return TypeEcran::RecolteJoueur;
}


//!
//! \brief Méthode lançant l'affichage de l'écran de l'histoire
//! @return TypeEcran retourne le nouveau type de l'écran
//! \author pgutierrez
//! \date 20/11/17
//! \version 1.0
//!
//! Si un bouton "NouvellePartie" est cliqué alors on retourne le nouveau type de l'écran
//!
TypeEcran ActionsBoutons::boutonNouvellePartie() const {
    return TypeEcran::PremiereJournee;
}

TypeEcran ActionsBoutons::boutonChoixNom() const {
    return TypeEcran::choixNom;
}

TypeEcran ActionsBoutons::boutonViderInventaire() {
    Modele * m = m_controleur->obtenirModele();
    Joueur * j = m->obtenirJoueur();
    if (j->obtenirInventaire()->obtenirNombreObjet()!=0) {
        std::vector<Objet*> objets = j->obtenirInventaire()->obtenirObjets();
        for (Objet* obj : objets) {
            m->obtenirCampement()->ajouterObjet(obj);
            j->obtenirInventaire()->supprimerObjet(obj);
        }
        j->mettreAChange();
        j->notifierTous();
    }
    return TypeEcran::Inventaire;
}

TypeEcran ActionsBoutons::boutonFinirQuete() {
    m_controleur->finJournee();
    return TypeEcran::RecapitulatifNuit;
}

TypeEcran ActionsBoutons::boutonChoixPersonnageCycle() {
    m_controleur->journeeSuivante();
    return TypeEcran::ChoixPersonnage;
}


TypeEcran ActionsBoutons::boutonChargement() {
    m_controleur->chargerSauvegarde();
    return TypeEcran::ChoixQuete;
}

TypeEcran ActionsBoutons::boutonRetourMenuPrincipal() {
    return TypeEcran::MenuPrincipal;
}

TypeEcran ActionsBoutons::boutonCampement() {
    m_controleur->obtenirModele()->obtenirTemps()->mettreEnPause();
    return TypeEcran::AccueilCampement;
}

TypeEcran ActionsBoutons::boutonViderInventaireCampement() {
    //CECI N'A RIEN A FAIRE DANS LA VUE, ON DOIT APPELER UNE FONCTION DU CONTROLEUR, QUI DOIT APPELER UNE FONCTION DU MODELE EFFECTUANT TOUT CELA
    if (m_controleur->obtenirModele()->obtenirJoueur()->obtenirInventaire()->obtenirNombreObjet()!=0) {
        std::vector<Objet*> objets = m_controleur->obtenirModele()->obtenirJoueur()->obtenirInventaire()->obtenirObjets();
        for (Objet* obj : objets) {
            m_controleur->obtenirModele()->obtenirCampement()->ajouterObjet(obj);
            m_controleur->obtenirModele()->obtenirJoueur()->obtenirInventaire()->supprimerObjet(obj);
        }
        m_controleur->obtenirModele()->obtenirJoueur()->mettreAChange();
        m_controleur->obtenirModele()->obtenirJoueur()->notifierTous();
    }
    return TypeEcran::AccueilCampement;
}

TypeEcran ActionsBoutons::boutonListeObjet() {
    return TypeEcran::ListeObjet;
}

//!
//! \brief Methode pour retourner au jeu depuis le campement
//! @return TypeEcran retourne le nouveau type de l'écran
//! \author mleothaud
//! \date 09/03/18
//! \version 1.0
//!
//! Note : temps de retard de la vue
//!
TypeEcran ActionsBoutons::boutonJeuPrincipalCampement() {
    m_controleur->obtenirModele()->obtenirCarte()->zoneActiveCampement();
    m_controleur->obtenirModele()->obtenirJoueur()->definirPosition(std::make_pair(10,10));
    return TypeEcran::JeuPrincipal;
}

TypeEcran ActionsBoutons::boutonEtatQuetePrincipale()
{
    return TypeEcran::QueteCampement;
}
