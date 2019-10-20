#include "spritepersonnage.h"

SpritePersonnage::SpritePersonnage(std::vector<SpriteAnime *> sprites)
    :
      m_sprites_animes{sprites},
      m_direction_joueur{Direction::Aucune}
{

}


void SpritePersonnage::afficher(SDL_Surface *surface){
    m_sprites_animes.at(m_direction_joueur)->afficher(surface);
}


void SpritePersonnage::deplacementJoueur(Direction direction){
    if (m_direction_joueur != direction){
        m_sprites_animes.at(m_direction_joueur)->reinitialiser();
        m_direction_joueur = direction;
    }
}


SpritePersonnage* SpritePersonnage::obtenirSpritesJoueur(){
    std::vector<SpriteAnime*> sprites_animes =
    {
        new SpriteAnime({new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{2*64,5*64,64,64}},
                         new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{3*64,5*64,64,64}}},
        NB_ETAPES),
        new SpriteAnime({new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{2*64,4*64,64,64}},
                         new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{3*64,4*64,64,64}}}
        , NB_ETAPES),
        new SpriteAnime({new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{0*64,5*64,64,64}},
                         new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{1*64,5*64,64,64}}},
        NB_ETAPES),
        new SpriteAnime({new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{0*64,6*64,64,64}},
                         new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{1*64,6*64,64,64}}},
        NB_ETAPES),
        new SpriteAnime({new Sprite{SPRITES_PRINCIPAUX, SDL_Rect{320,320,64,64}, SDL_Rect{4*64,4*64,64,64}}},
        NB_ETAPES)

    };
    return new SpritePersonnage(sprites_animes);
}


SpritePersonnage::~SpritePersonnage(){
    for (SpriteAnime* sprite_anime : m_sprites_animes){
        delete sprite_anime;
    }
}