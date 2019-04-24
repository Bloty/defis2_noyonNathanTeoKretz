#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "init_chargement.h"

//**********************************************************************//
//But : Initialiser le SDL, la SDL_image, la SDL_ttf et crée la fenêtre
//Entrer : Une variable de type SDL_Window, une variable de type SDL_Renderer et la largeur et la longeur de la fenêtre.
//Sortie : La fenêtre crée.
//Note :
//**********************************************************************//SDL_Window
int init(SDL_Window **fenetre, SDL_Renderer **renderer, int w, int h)
{
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }

    *fenetre = SDL_CreateWindow("c'est un super jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if(fenetre == NULL)
    {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        return -1;
    }

    *renderer = SDL_CreateRenderer(*fenetre, 0, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        fprintf(stderr,"Erreur de création du renderer: %s\n",SDL_GetError());
        return -1;
    }

    if(TTF_Init() == -1)
    {
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    return -1;
    }

    return 0;
}

//**********************************************************************//
//But : Change la taille et les coordonnees des objet
//Entrer: Un point d'origne en X et Y, une longeur de la fenêtre.
//Sortie: le SDL_Rect changer
//Note:
//**********************************************************************//
SDL_Rect tailleRect(int nX, int nY, int nW, int nH)
{
    SDL_Rect rect;

    rect.x = nX;
    rect.y = nY;
    rect.w = nW;
    rect.h = nH;

    return rect;
}

//**********************************************************************//
//But : Charger une image dans une SDL_Texture
//Entrer: Le chemain de l'image et le rendu
//Sortie: La SDL_Texture
//Note:
//**********************************************************************//
SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = IMG_Load(path);

    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);

    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}

//**********************************************************************//
//But : Charger une police
//Entrer: le chemain de la police et sa taille en pixel.
//Sortie: la TTF_Font
//Note:
//**********************************************************************//
TTF_Font *loadFont(const char path[], int taille)
{
    TTF_Font *font = NULL;

    font = TTF_OpenFont(path,taille);
    if (font==NULL)
    {
        fprintf(stderr, "Erreur TTF_OpenFont : %s", SDL_GetError());
        return NULL;
    }

    return font;
}

//**********************************************************************//
//But : Entrer une chaine de caractaire dans une SDL_Texture, choisir la couleur, et sa position
//Entrer: chaine de caractaire, la couleur en rgb, les coordonnees
//Sortie: SDL_Texture et la largeur et la longeur de la chaine en pixel
//Note:
//**********************************************************************//
SDL_Texture *ecrire (TTF_Font *font, const char chaine[], int r, int g, int b, int x, int y , SDL_Renderer *renderer, SDL_Rect *textRect)
{
    SDL_Surface *message= NULL;
    SDL_Texture *text = NULL;
    SDL_Color textColor = {r, g, b};
    int w=0, h=0;

    message = TTF_RenderText_Solid(font,chaine,textColor);
    text = SDL_CreateTextureFromSurface(renderer,message);
    SDL_QueryTexture(text,NULL,NULL,&w,&h);
    textRect->x = x;
    textRect->y = y;
    textRect->w = w;
    textRect->h = h;

    return text;
}
