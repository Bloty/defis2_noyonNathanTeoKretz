#ifndef INIT_CHARGEMENT_H_INCLUDED
#define INIT_CHARGEMENT_H_INCLUDED
#pragma once

//proto
extern int init(SDL_Window **fenetre, SDL_Renderer **renderer, int w, int h);
extern SDL_Rect tailleRect(int nX, int nY, int nW, int nH);
extern SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer);
extern TTF_Font *loadFont(const char path[],int taille);
extern SDL_Texture *ecrire (TTF_Font *font, const char phrase[], int r, int g, int b, int x, int y , SDL_Renderer *renderer, SDL_Rect *textRect);

#endif // INIT_CHARGEMENT_H_INCLUDED
