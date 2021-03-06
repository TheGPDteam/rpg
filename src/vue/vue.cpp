#include "vue.h"


//!
//! \brief Constructeur paramétré d'une vue
//! \author pgutierrez
//! \date 11/11/16
//! \version 0.3
//!
//! Initialise la vue (elle démarreras toujours sur l'écran du menu princiapal)
//!

Vue::Vue() : m_typeEcran(TypeEcran::MenuPrincipal), m_cliqueSouris(false), m_coordSouris(0,0), m_quitterJeu(false)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    m_fenetrePrincipale = SDL_SetVideoMode(WIDTH_FENETRE_PRINCIPALE, HEIGHT_FENETRE_PRINCIPALE, BPP, SDL_HWSURFACE);
    SDL_WM_SetCaption("Projet RPG", NULL);

    m_typeEcran = TypeEcran::MenuPrincipal;

//    //Les nouveaux écrans avec sprites doivent être déclarés après avoir initialisé la fenêtre
//    m_menuPrincipal = new EcranMenuPrincipal();
//    m_ecranEquipe = new EcranEquipe();
//    m_ecranInventaire = new EcranInventaire();
//    m_ecranChoixPersonnage = new EcranChoixPersonnage();
//    m_ecranQueteJoueur = new EcranQueteJoueur();
//    m_ecranNom = new EcranNom();
//    m_ecranPremiereJournee = new EcranPremiereJournee();
//    m_ecranRecapitulatifNuit = new EcranRecapitulatifNuit();

    m_cliqueSouris = false;
    m_coordSouris = {0,0};
    m_quitterJeu = false;
}

//!
//! \brief Initialise le controleur de la vue
//! \author mleothaud, fvain
//! @param controleur controleur de l'architecture du modèle MVC
//! \date 15/11/16
//! \version 1.0
//!
//! Initialise le controleur de la vue en fonction du controleur en paramètre
//!

void Vue::definirControleur(Controleur *controleur)
{
    m_controleur=controleur;
    m_jeuPrincipal = new EcranJeuPrincipal(m_controleur);
    m_ecranChoixQuete = new EcranQuete(m_controleur);
    m_menuPrincipal = new EcranMenuPrincipal(m_controleur);
    m_ecranEquipe = new EcranEquipe(m_controleur);
    m_ecranInventaire = new EcranInventaire(m_controleur);
    m_ecranChoixPersonnage = new EcranChoixPersonnage(m_controleur);
    m_ecranQueteJoueur = new EcranQueteJoueur(m_controleur);
    m_ecranNom = new EcranNom(m_controleur);
    m_ecranPremiereJournee = new EcranPremiereJournee(m_controleur);
    m_ecranRecapitulatifNuit = new EcranRecapitulatifNuit(m_controleur);
    m_ecranAccueilCampement = new EcranAccueilCampement(m_controleur);
    m_ecranListeObjet = new EcranListeObjet(m_controleur);

    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_jeuPrincipal);
    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_ecranInventaire);
    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_ecranEquipe);
    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_ecranChoixPersonnage);
    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_ecranChoixQuete);
    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_ecranQueteJoueur);
    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_ecranRecapitulatifNuit);
    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_ecranPremiereJournee);
    m_controleur->obtenirModele()->obtenirJoueur()->ajouterObservateur(*m_ecranAccueilCampement);
    m_jeuPrincipal->definirCarte(m_controleur->obtenirModele()->obtenirCarte());

    m_ecranInventaire->definirEtatQuantite(m_controleur->obtenirModele()->obtenirJoueur()->obtenirInventaireJoueur()->obtenirNombreObjet());
    m_ecranInventaire->definirObjetPourAffichage(m_controleur->obtenirModele()->obtenirJoueur()->obtenirInventaireJoueur()->obtenirObjets());

    m_controleur->obtenirModele()->obtenirJoueur()->mettreAChange();
    m_controleur->obtenirModele()->obtenirJoueur()->notifierTous();
    // m_ecranChoix ?
}


//!
//! \brief Affiche la vue
//! \author pgutierrez
//! \date 11/11/16
//! \version 0.2
//!
//! Affiche la vue en fonction de son type d'écran (correspondant à m_typeEcran)
//!

void Vue::affichageVue()
{
    switch(m_typeEcran)
    {
    case TypeEcran::MenuPrincipal:{
        afficherEcran(m_menuPrincipal);
        break;
    }
    case TypeEcran::ChasseJoueur:{
        //Arme* a = new Arme(22,"AK","mitrailleur portatif consus durant cette guerre par les Russes pour prendre l'avantages sur ces sales Nazis");
        //Quete q("Chasse","Chasse les zombies",10,100,a);
        //m_controleur->obtenirModele()->obtenirJoueur()->nouvelleQuete(q);
        changerEcran(TypeEcran::JeuPrincipal);
        break;
    }
    case TypeEcran::RecolteJoueur:{
        //Vivre* v = new Vivre("steak","steak",15);
//        Quete q("Récolte","fais à manger!",10,100,v);
//        m_controleur->obtenirModele()->obtenirJoueur()->nouvelleQuete(q);
        changerEcran(TypeEcran::JeuPrincipal);
        break;
    }
    case TypeEcran::JeuPrincipal:{
        afficherEcran(m_jeuPrincipal);
        break;
    }
    case TypeEcran::Equipe:{
        afficherEcran(m_ecranEquipe);
        break;
    }
    case TypeEcran::Inventaire:{
        afficherEcran(m_ecranInventaire);
        break;
    }
    case TypeEcran::ChoixPersonnage:{
        afficherEcran(m_ecranChoixPersonnage);
        break;
    }
    case TypeEcran::ChoixQuete:{
        afficherEcran(m_ecranChoixQuete);
        break;
    }
    case TypeEcran::PopUpJoueur:{
        afficherEcran(m_ecranQueteJoueur);
        break;
    }
    case TypeEcran::choixNom:{
        afficherEcran(m_ecranNom);
        break;
    }
    case TypeEcran::PremiereJournee:
    {
        afficherEcran(m_ecranPremiereJournee);
        break;
    }
    case TypeEcran::RecapitulatifNuit:
    {
        m_controleur->sauvegarderModele();
        afficherEcran(m_ecranRecapitulatifNuit);
        break;
    }
    case  TypeEcran::Quitter:
    {
        m_quitterJeu = true;
        break;
    }
    case TypeEcran::AccueilCampement:
    {
        afficherEcran(m_ecranAccueilCampement);
        break;
    }
    case TypeEcran::ListeObjet:
    {
        afficherEcran(m_ecranListeObjet);
        break;
    }
    default:{
        std::cout << "Erreur d'initialisation du type d'affichage !" << std::endl;
        break;
    }
    }

    if(!m_quitterJeu) // Sans cette condition segfault à cause du SDL_Quit() de gestionEvenementJoueur
    {
        SDL_Flip(m_fenetrePrincipale);
#ifndef EMSCRIPTEN
        SDL_Delay(DELAI);
#endif
    }
}



//!_FL
//! \author pgutierrez
//! @param ecran affiche l'écran en paramètre
//! \date 23/11/16
//! \version 1.1
//!
//! Affiche tout le contenu de l'écran placé en paramètre et vérifie si il n,'y a pas un clique souris
//!

void Vue::afficherEcran(EcranGeneral* ecran_courant)
{
    if(ecran_courant != nullptr)
    {
        ecran_courant->afficherEcran(m_coordSouris, m_fenetrePrincipale);
        ecran_courant->gestionDesEvenements(m_controleur, m_quitterJeu, m_cliqueSouris, m_coordSouris);

        if(m_cliqueSouris)
        {
            m_typeEcran = ecran_courant->verificationCliqueSourisSurBouton(m_coordSouris, m_typeEcran);
            m_cliqueSouris = false;
        }
    }
}



//!
//! \brief Accesseur m_quitterJeu
//! \return bool
//! \author pgutierrez
//! \date 21/11/16
//! \version 1.0
//!
//! Retourne la valeur de m_quitterJeu
//!

bool Vue::getFermerJeu()
{
    return m_quitterJeu;
}



//!
//! \brief Destructeur de la vue
//! \author pgutierrez
//! \date 11/11/16
//! \version 0.1
//!
//! Détruit l'écran du menu princiapal si il était initialisé
//!

Vue::~Vue()
{

    if(m_menuPrincipal != nullptr)
    {
        delete m_menuPrincipal;
        m_menuPrincipal = nullptr;
    }

    if(m_jeuPrincipal != nullptr)
    {
        delete m_jeuPrincipal;
        m_jeuPrincipal = nullptr;
    }

    if(m_ecranEquipe != nullptr)
    {
        delete m_ecranEquipe;
        m_ecranEquipe = nullptr;
    }

    if(m_ecranInventaire != nullptr)
    {
        delete m_ecranInventaire;
        m_ecranInventaire = nullptr;
    }

    if(m_ecranChoixQuete != nullptr)
    {
        delete m_ecranChoixQuete;
        m_ecranChoixQuete = nullptr;
    }

    if(m_ecranChoixPersonnage != nullptr)
    {
        delete m_ecranChoixPersonnage;
        m_ecranChoixPersonnage = nullptr;
    }

    if(m_ecranNom != nullptr)
    {
        delete m_ecranNom;
        m_ecranNom = nullptr;
    }

    if(m_ecranQueteJoueur)
    {
        delete m_ecranQueteJoueur;
        m_ecranQueteJoueur = nullptr;
    }

    if (m_ecranRecapitulatifNuit)
    {
        delete m_ecranRecapitulatifNuit;
        m_ecranRecapitulatifNuit = nullptr;
    }

    if (m_ecranPremiereJournee != nullptr)
    {
        delete m_ecranPremiereJournee;
        m_ecranPremiereJournee = nullptr;
    }

    if (m_ecranAccueilCampement != nullptr)
    {
        delete m_ecranAccueilCampement;
        m_ecranAccueilCampement = nullptr;
    }

    SDL_FreeSurface(m_fenetrePrincipale);
    TTF_Quit();
    SDL_Quit();
}

//!
//! \brief Vue::changerEcran
//! \param nouvelEcran
//!
void Vue::changerEcran(TypeEcran nouvelEcran){
    m_typeEcran = nouvelEcran;
}

SDL_Surface* Vue::obtenirFenetrePrincipale(){
    return m_fenetrePrincipale;

}
