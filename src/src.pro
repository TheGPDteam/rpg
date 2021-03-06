TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS+=`sdl-config --libs` -lSDL_image -lSDL_ttf

INCLUDEPATH+=/usr/include/SDL/

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra

SOURCES += \
    modele/equipe.cpp \
    vue/vue.cpp \
    controleur/controleur.cpp \
    modele/modele.cpp \
    modele/statistique.cpp \
    modele/temps.cpp \
    modele/tuile.cpp \
    modele/vie.cpp \
    modele/vivre.cpp \
    modele/zone.cpp \
    modele/objet.cpp \
    modele/personnage.cpp \
    modele/quete.cpp \
    modele/arme.cpp \
    modele/campement.cpp \
    modele/carte.cpp \
    modele/combat.cpp \
    modele/competence.cpp \
    modele/humain.cpp \
    modele/inventaire.cpp \
    modele/joueur.cpp \
    main.cpp \
    modele/niveau.cpp \
    modele/zombie.cpp \
    vue/bouton.cpp \
    vue/chargementfeuilledesprite.cpp \
    vue/ecranmenuprincipal.cpp \
    vue/sprite.cpp \
    vue/textesdl.cpp \
    vue/actionsboutons.cpp \
    vue/ecrangeneral.cpp \
    vue/ecranjeuprincipal.cpp \
    vue/ecranquete.cpp \
    observateur.cpp \
    observable.cpp \
    vue/dictionnairedeboutons.cpp \
    save/sauvegarde.cpp \
    vue/ecranequipe.cpp \
    vue/ecraninventaire.cpp \
    vue/ecranchoixpersonnage.cpp \
    vue/ecranquetejoueur.cpp \
    vue/ecrannom.cpp \
    vue/saisir.cpp \
    vue/ecranpremierejournee.cpp \
    vue/ecranrecapitulatifnuit.cpp \
    modele/utilitaires.cpp \
    vue/ecranrepartitionjoueur.cpp \
    vue/ecranaccueilcampement.cpp \
    vue/ecranlisteobjets.cpp \
    vue/ecrancombat.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    controleur/controleur.h \
    modele/equipe.h \
    modele/modele.h \
    modele/statistique.h \
    modele/temps.h \
    modele/tuile.h \
    modele/vie.h \
    modele/vivre.h \
    modele/zone.h \
    modele/objet.h \
    modele/personnage.h \
    modele/quete.h \
    modele/arme.h \
    modele/campement.h \
    modele/carte.h \
    modele/combat.h \
    modele/competence.h \
    modele/humain.h \
    modele/inventaire.h \
    modele/joueur.h \
    modele/actioncombat.h \
    modele/niveau.h \
    modele/zombie.h \
    save/sauvegarde.h \
    vue/vue.h \
    vue/bouton.h \
    vue/chargementfeuilledesprite.h \
    vue/ecranmenuprincipal.h \
    vue/ecranquete.h \
    vue/sprite.h \
    vue/textesdl.h \
    vue/typebouton.h \
    vue/typeecran.h \
    vue/actionsboutons.h \
    vue/constantesbouton.h \
    vue/ecrangeneral.h \
    vue/ecranjeuprincipal.h \
    vue/dictionnairedeboutons.h \
    vue/ecranequipe.h \
    vue/ecraninventaire.h \
    vue/policetexte.h \
    vue/ecranchoixpersonnage.h \
    vue/ecranquetejoueur.h \
    vue/ecranquetejoueur.h \
    vue/ecranquetejoueur.h \
    vue/ecrannom.h \
    vue/saisir.h \
    direction.h \
    observateur.h \
    observable.h \
    vue/ecranpremierejournee.h \
    vue/ecranrecapitulatifnuit.h \
    vue/repartitionjoueur.h \
    modele/typeobjet.h \
    modele/utilitaires.h \
    vue/ecranrepartitionjoueur.h \
    modele/typequete.h \
    modele/typedefaite.h \
    vue/ecranaccueilcampement.h \
    vue/ecranlisteobjets.h \
    vue/ecrancombat.h

