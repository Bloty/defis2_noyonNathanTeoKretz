#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "event.h"

//**********************************************************************//
//But : Récupérer la position de la souris
//Entrer: SDL_Event
//Sortie: les coordonnees de la souris
//Note:
//**********************************************************************//
void positionSouris(SDL_Event event, coordonnee *coordXY)
{
    coordXY->nX = event.motion.x;
    coordXY->nY = event.motion.y;
}

//**********************************************************************//
//But : Changer de scene avec un clique bouton
//Entrer: les coordonner de la sourie, le taille du bouton, la scene suivante
//Sortie: La scene suivante
//Note:
//**********************************************************************//
void changement_scene(coordonnee coordCliqueXY, SDL_Rect rectButton, int *scene, int sceneSuivante)
{
    if ((coordCliqueXY.nX>=rectButton.x) && (coordCliqueXY.nX<=rectButton.x+rectButton.w)&&(coordCliqueXY.nY>=rectButton.y) && (coordCliqueXY.nY<=rectButton.y+rectButton.h))
    {
        *scene = sceneSuivante;
    }
}

//**********************************************************************//
//But : Vérifier si on survole une zone avec la souris
//Entrer: les coordonner de la sourie, le taille de la zone
//Sortie: oui ou non on est au dessus d'une zone
//Note:
//**********************************************************************//
booleen survol_souris(coordonnee coordSourisXY, SDL_Rect rectButton)
{
    booleen boo=FALSE;

    if ((coordSourisXY.nX>=rectButton.x) && (coordSourisXY.nX<=rectButton.x+rectButton.w)&&(coordSourisXY.nY>=rectButton.y) && (coordSourisXY.nY<=rectButton.y+rectButton.h))
    {
        boo=TRUE;
    }
    return boo;
}

//**********************************************************************//
//But : Vérifier si on clique dans une zone avec la souris
//Entrer: les coordonner de la sourie, le taille de la zone
//Sortie: oui ou non on  clique dans la zone
//Note:
//**********************************************************************//
booleen clique_dans_boutton(coordonnee coordCliqueXY, SDL_Rect rectButton)
{
    booleen boo=FALSE;

    if ((coordCliqueXY.nX>=rectButton.x) && (coordCliqueXY.nX<=rectButton.x+rectButton.w) && (coordCliqueXY.nY>=rectButton.y) && (coordCliqueXY.nY<=rectButton.y+rectButton.h))
    {
        boo=TRUE;
    }
    return boo;
}

//**********************************************************************//
//But : Vérifier si un objet est bien dans une zone
//Entrer: Taille de l'objet, le taille de la zone
//Sortie: oui ou non l'objet est dans la zone
//Note:
//**********************************************************************//
 booleen verifEnigmeFin(SDL_Rect tailleCarre, SDL_Rect rectObjet)
 {
     booleen boo=FALSE;

    if ((rectObjet.x>=tailleCarre.x) && (rectObjet.x<=tailleCarre.x+tailleCarre.w) && (rectObjet.y>=tailleCarre.y) && (rectObjet.y<=tailleCarre.y+tailleCarre.h))
    {
        boo=TRUE;
    }
    return boo;
 }

void rezXYClique(coordonnee *coordCliqueXY)
{
    coordCliqueXY->nX=0;
    coordCliqueXY->nY=0;
}

void raf(SDL_Renderer *renderer)
{
    SDL_Delay(5);
    SDL_RenderClear(renderer); // Nettoyage
}

void delay(unsigned int framelimit)
{
    unsigned int ticks;

    ticks = SDL_GetTicks();

    if (framelimit<ticks)
        return;

    if (framelimit>ticks+16)
        SDL_Delay(16);
    else
        SDL_Delay(framelimit - ticks);
}
