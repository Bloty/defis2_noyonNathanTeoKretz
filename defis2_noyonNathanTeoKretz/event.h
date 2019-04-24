#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED
#pragma once

typedef struct coordonnee
{
    int nX;
    int nY;
}coordonnee;

typedef struct carreEnigmeFin
{
   SDL_Rect carre1;
   SDL_Rect carre2;
   SDL_Rect carre3;
   SDL_Rect carre4;

}carreEnigmeFin;

typedef enum booleen
{
    FALSE,TRUE
}booleen;

typedef enum couleurJoyaux
{
    ROUGE, BLEU, VERT, JAUNE, AUCUNE
}couleurJoyaux;

extern void positionSouris(SDL_Event event, coordonnee *coordXY);
extern void changement_scene(coordonnee coordCliqueXY, SDL_Rect rectButton, int *scene,  int sceneSuivante);
extern booleen survol_souris(coordonnee coordSourisXY, SDL_Rect rectButton);
extern booleen clique_dans_boutton(coordonnee coordCliqueXY, SDL_Rect rectButton);
extern booleen verifEnigmeFin(SDL_Rect tailleCarre, SDL_Rect rectObjet);
extern void rezXYClique(coordonnee *coordCliqueXY);
extern void raf(SDL_Renderer *renderer);
extern void delay(unsigned int framelimit);

#endif // EVENT_H_INCLUDED
