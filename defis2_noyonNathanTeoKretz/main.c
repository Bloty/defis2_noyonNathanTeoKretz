#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "init_chargement.h"
#include "event.h"


int main(int argc, char **argv)
{
    unsigned int framelimit = (SDL_GetTicks()+16);
    //La fenêtre
    SDL_Window *fenetre=NULL;
    SDL_Renderer *renderer=NULL;

    //image
        //general
    SDL_Texture *balle = NULL;
    SDL_Texture *portes = NULL;
    SDL_Texture *flecheGauche = NULL;
    SDL_Texture *flecheDroite = NULL;
    SDL_Texture *croix = NULL;
    SDL_Texture *coffre = NULL;
    SDL_Texture *enigmeFin = NULL;
    SDL_Texture *JoyauxRouge = NULL;
    SDL_Texture *JoyauxVert = NULL;
    SDL_Texture *JoyauxBleu = NULL;
    SDL_Texture *JoyauxJaune = NULL;
    SDL_Texture *merci = NULL;
        //salle1
    SDL_Texture *salle1 = NULL;
    SDL_Texture *salle1Gauche = NULL;
    SDL_Texture *salle1Droite = NULL;
    SDL_Texture *salle1Porte = NULL;
        //salle2
    SDL_Texture *salle2 = NULL;
    SDL_Texture *salle2Gauche = NULL;
    SDL_Texture *salle2Droite = NULL;
    SDL_Texture *salle2Porte = NULL;
        //salle3
    SDL_Texture *salle3 = NULL;
    SDL_Texture *salle3Gauche = NULL;
    SDL_Texture *salle3Droite = NULL;
    SDL_Texture *salle3Porte = NULL;
        //salle4
    SDL_Texture *salle4 = NULL;
    SDL_Texture *salle4Gauche = NULL;
    SDL_Texture *salle4Droite = NULL;
    SDL_Texture *salle4Porte = NULL;


    //position et taille de l'image
    SDL_Rect rectBalle = tailleRect(0, 0, 20, 20);
    SDL_Rect tailleJoyauxRouge = tailleRect(380, 192, 100, 100);
    SDL_Rect tailleJoyauxRougeInventaire = tailleRect(5, 5, 30, 30);
    SDL_Rect tailleJoyauxVert = tailleRect(380, 192, 100, 100);
    SDL_Rect tailleJoyauxVertInventaire = tailleRect(35, 5, 30, 30);
    SDL_Rect tailleJoyauxBleu = tailleRect(380, 192, 100, 100);
    SDL_Rect tailleJoyauxBleuInventaire = tailleRect(65, 5, 30, 30);
    SDL_Rect tailleJoyauxJaune = tailleRect(380, 192, 100, 100);
    SDL_Rect tailleJoyauxJauneInventaire = tailleRect(95, 5, 30, 30);



    //police
    TTF_Font *arial = NULL;
    TTF_Font *arialPetit = NULL;

    SDL_Texture *txtStart = NULL;
    SDL_Texture *txtStartSurvol = NULL;
    SDL_Texture *txtCestFermer = NULL;
    SDL_Rect textRect, textRectFerme;

    //var
    coordonnee coordXYClique;
    coordonnee coordXYCliqueEnfoncer;
    coordonnee coordXYSurvol;
    couleurJoyaux joyauxSelect = AUCUNE;
    int scene=0, mur=1;
    booleen boolJoyauxRouge = FALSE;
    booleen boolJoyauxVert = FALSE;
    booleen boolJoyauxBleu = FALSE;
    booleen boolJoyauxJaune = FALSE;
    carreEnigmeFin tailleEnigmeFin;
    tailleEnigmeFin.carre1 = tailleRect(46, 158, 165, 152);
    tailleEnigmeFin.carre2 = tailleRect(245, 158, 165, 152);
    tailleEnigmeFin.carre3 = tailleRect(443, 158, 165, 152);
    tailleEnigmeFin.carre4 = tailleRect(640, 158, 165, 152);

    //var jeu
    SDL_Rect tailleFlechGauche = tailleRect(5, 200, 30, 30);
    SDL_Rect tailleFlechDroite = tailleRect(819, 200, 30, 30);
    SDL_Rect tailleCroix = tailleRect(819, 0, 20, 20);

    SDL_Rect taillecoffre = tailleRect(337, 192, 165, 130);
    SDL_Rect taillePorte1 = tailleRect(15, 151, 155, 480);
    SDL_Rect taillePorte2 = tailleRect(188, 151, 155, 480);
    SDL_Rect taillePorte3 = tailleRect(528, 151, 155, 480);
    SDL_Rect taillePorte4 = tailleRect(695, 151, 155, 480);
    SDL_Rect taillePorteSortie = tailleRect(355, 151, 155, 480);


    // Initialisation de la SDL
    if(0 != init(&fenetre, &renderer, 854, 480))
    {
        SDL_Quit();
        return -1;
    }

    // chargement des images
    portes = loadImage("image/portes.png", renderer);
    balle = loadImage("image/rond_rouge.png", renderer);
    flecheGauche = loadImage("image/fleche_gauche.png", renderer);
    flecheDroite = loadImage("image/fleche_droite.png", renderer);
    croix = loadImage("image/croix.png", renderer);
    coffre = loadImage("image/coffre.png", renderer);
    enigmeFin = loadImage("image/enigme_fin.png", renderer);
    JoyauxRouge = loadImage("image/joyaux_rouge.png", renderer);
    JoyauxVert = loadImage("image/joyaux_vert.png", renderer);
    JoyauxBleu = loadImage("image/joyaux_bleu.png", renderer);
    JoyauxJaune = loadImage("image/joyaux_jaune.png", renderer);
    merci = loadImage("image/merci.png", renderer);
        //salle1
    salle1 = loadImage("image/salle1/salle1.png", renderer);
    salle1Gauche = loadImage("image/salle1/salle1_gauche.png", renderer);
    salle1Droite = loadImage("image/salle1/salle1_droite.png", renderer);
    salle1Porte = loadImage("image/salle1/salle1_porte.png", renderer);
        //salle2
    salle2 = loadImage("image/salle2/salle2.png", renderer);
    salle2Gauche = loadImage("image/salle2/salle2_gauche.png", renderer);
    salle2Droite = loadImage("image/salle2/salle2_droite.png", renderer);
    salle2Porte = loadImage("image/salle2/salle2_porte.png", renderer);
        //salle3
    salle3 = loadImage("image/salle3/salle3.png", renderer);
    salle3Gauche = loadImage("image/salle3/salle3_gauche.png", renderer);
    salle3Droite = loadImage("image/salle3/salle3_droite.png", renderer);
    salle3Porte = loadImage("image/salle3/salle3_porte.png", renderer);
        //salle4
    salle4 = loadImage("image/salle4/salle4.png", renderer);
    salle4Gauche = loadImage("image/salle4/salle4_gauche.png", renderer);
    salle4Droite = loadImage("image/salle4/salle4_droite.png", renderer);
    salle4Porte = loadImage("image/salle4/salle4_porte.png", renderer);

    //chargement des police
    arial = loadFont("arialbd.ttf",50);
    arialPetit = loadFont("arialbd.ttf",15);

    txtStart = ecrire(arial,"START", 255, 255, 255, 100, 100 , renderer, &textRect);
    txtStartSurvol = ecrire(arial,"START", 255, 0, 0, 100, 100 , renderer, &textRect);



    if (fenetre)
    {
        char cont = 1; // Détermine si on continue la boucle principale
        SDL_Event event;

        //boucle de jeu________________________________________________________________________________
        while(cont != 0)
        {
            //event
            while (SDL_PollEvent(&event))
            {
                switch (event.type) //Quel événement?
                {
                    case SDL_QUIT: // Clic sur la croix
                        cont=0;
                        break;

                    case SDL_MOUSEBUTTONUP:
                        positionSouris(event, &coordXYClique);
                        joyauxSelect = AUCUNE;
                        break;

                    case SDL_MOUSEBUTTONDOWN:
                        positionSouris(event, &coordXYCliqueEnfoncer);
                        break;

                    case SDL_MOUSEMOTION:
                        positionSouris(event, &coordXYSurvol);
                        break;
                }
            }


            switch(scene)
            {
            case 0://menu----------------------------------------------------------------------------------------------------------------------
                if(survol_souris(coordXYSurvol, textRect) == TRUE)
                {
                    SDL_RenderCopy(renderer,txtStartSurvol,NULL,&textRect);
                }
                else
                {
                    SDL_RenderCopy(renderer,txtStart,NULL,&textRect);
                }

                changement_scene(coordXYClique, textRect, &scene, 1);
                break;


            case 1://Couloire------------------------------------------------------------------------------------------------------------------
                mur = 1;
                //scene1
                SDL_RenderCopy(renderer,portes,NULL,NULL);//on dessine la texture image sur le rendu

                if((survol_souris(coordXYSurvol, taillePorte1) == TRUE) || ((survol_souris(coordXYSurvol, taillePorte2) == TRUE)) || ((survol_souris(coordXYSurvol, taillePorte3) == TRUE)) || ((survol_souris(coordXYSurvol, taillePorte4) == TRUE))|| ((survol_souris(coordXYSurvol, taillePorteSortie) == TRUE)))
                {
                    rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                    SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                }

                if((clique_dans_boutton(coordXYClique, taillePorteSortie) == TRUE) && ((boolJoyauxBleu==FALSE) || (boolJoyauxJaune==FALSE) || (boolJoyauxRouge==FALSE) || (boolJoyauxVert==FALSE)))
                {
                    txtCestFermer = ecrire(arialPetit,"C'est fermer", 0, 0, 0, coordXYClique.nX, coordXYClique.nY, renderer, &textRectFerme);
                }
                else
                {
                    changement_scene(coordXYClique, taillePorteSortie, &scene, 6);
                }

                if(survol_souris(coordXYSurvol, taillePorteSortie) == TRUE)
                {
                   SDL_RenderCopy(renderer,txtCestFermer,NULL,&textRectFerme);
                }
                else
                {
                    txtCestFermer = ecrire(arialPetit,"", 0, 0, 0, coordXYClique.nX, coordXYClique.nY, renderer, &textRectFerme);
                }

                changement_scene(coordXYClique, taillePorte1, &scene, 2);
                changement_scene(coordXYClique, taillePorte2, &scene, 3);
                changement_scene(coordXYClique, taillePorte3, &scene, 4);
                changement_scene(coordXYClique, taillePorte4, &scene, 5);
                break;


            case 2://salle 1----------------------------------------------------------------------------------------------------------------------
                //scene2
                switch(mur)
                {
                case 1:
                    //mur1
                    SDL_RenderCopy(renderer,salle1,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE) || (survol_souris(coordXYSurvol, taillecoffre)))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 2);
                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 3);
                    changement_scene(coordXYClique, taillecoffre, &mur, 5);

                    break;

                case 2:
                    //mur gauche
                    SDL_RenderCopy(renderer,salle1Gauche,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 4);
                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 1);

                    break;

                case 3:
                    //mur droite
                    SDL_RenderCopy(renderer,salle1Droite,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 4);
                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 1);

                    break;

                case 4:
                    //mur porte
                    SDL_RenderCopy(renderer,salle1Porte,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE) || (survol_souris(coordXYSurvol, taillePorteSortie) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 2);
                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 3);
                    changement_scene(coordXYClique, taillePorteSortie, &scene, 1);

                    break;

                case 5://coffre
                    SDL_RenderCopy(renderer,coffre,NULL,NULL);
                    SDL_RenderCopy(renderer,croix,NULL,&tailleCroix);

                    if(boolJoyauxRouge==FALSE)
                    {
                        SDL_RenderCopy(renderer,JoyauxRouge,NULL,&tailleJoyauxRouge);
                    }

                    if((clique_dans_boutton(coordXYClique,tailleJoyauxRouge)) && (boolJoyauxRouge==FALSE))
                    {
                        boolJoyauxRouge=TRUE;
                    }

                    if((survol_souris(coordXYSurvol, tailleCroix)) == TRUE || ((survol_souris(coordXYSurvol, tailleJoyauxRouge)) && (boolJoyauxRouge==FALSE)))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleCroix, &mur, 1);
                    break;
                }
                break;

            case 3://salle2-----------------------------------------------------------------------------------------------------------------------
                 //scene3
                switch(mur)
                {
                case 1:
                    //mur1
                    SDL_RenderCopy(renderer,salle2,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE) || (survol_souris(coordXYSurvol, taillecoffre)))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 2);
                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 3);
                    changement_scene(coordXYClique, taillecoffre, &mur, 5);

                    break;

                case 2:
                    //mur gauche
                    SDL_RenderCopy(renderer,salle2Gauche,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 4);
                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 1);

                    break;

                case 3:
                    //mur droite
                    SDL_RenderCopy(renderer,salle2Droite,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 4);
                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 1);

                    break;

                case 4:
                    //mur porte
                    SDL_RenderCopy(renderer,salle2Porte,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE) || (survol_souris(coordXYSurvol, taillePorteSortie) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 2);
                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 3);
                    changement_scene(coordXYClique, taillePorteSortie, &scene, 1);

                    break;

                case 5://coffre
                    SDL_RenderCopy(renderer,coffre,NULL,NULL);
                    SDL_RenderCopy(renderer,croix,NULL,&tailleCroix);

                    if(boolJoyauxVert==FALSE)
                    {
                        SDL_RenderCopy(renderer,JoyauxVert,NULL,&tailleJoyauxVert);
                    }

                    if((clique_dans_boutton(coordXYClique,tailleJoyauxVert)) && (boolJoyauxVert==FALSE))
                    {
                        boolJoyauxVert=TRUE;
                    }

                    if((survol_souris(coordXYSurvol, tailleCroix)) == TRUE || ((survol_souris(coordXYSurvol, tailleJoyauxVert)) && (boolJoyauxVert==FALSE)))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleCroix, &mur, 1);
                    break;
                }
                break;

            case 4://salle3-----------------------------------------------------------------------------------------------------------------------
                //scene4
                switch(mur)
                {
                case 1:
                    //mur1
                    SDL_RenderCopy(renderer,salle3,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE) || (survol_souris(coordXYSurvol, taillecoffre)))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 2);
                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 3);
                    changement_scene(coordXYClique, taillecoffre, &mur, 5);

                    break;

                case 2:
                    //mur gauche
                    SDL_RenderCopy(renderer,salle3Gauche,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 4);
                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 1);

                    break;

                case 3:
                    //mur droite
                    SDL_RenderCopy(renderer,salle3Droite,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 4);
                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 1);

                    break;

                case 4:
                    //mur porte
                    SDL_RenderCopy(renderer,salle3Porte,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE) || (survol_souris(coordXYSurvol, taillePorteSortie) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 2);
                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 3);
                    changement_scene(coordXYClique, taillePorteSortie, &scene, 1);

                    break;

                case 5://coffre
                    SDL_RenderCopy(renderer,coffre,NULL,NULL);
                    SDL_RenderCopy(renderer,croix,NULL,&tailleCroix);

                    if(boolJoyauxBleu==FALSE)
                    {
                        SDL_RenderCopy(renderer,JoyauxBleu,NULL,&tailleJoyauxBleu);
                    }

                    if((clique_dans_boutton(coordXYClique,tailleJoyauxBleu)) && (boolJoyauxBleu==FALSE))
                    {
                        boolJoyauxBleu=TRUE;
                    }

                    if((survol_souris(coordXYSurvol, tailleCroix)) == TRUE || ((survol_souris(coordXYSurvol, tailleJoyauxBleu)) && (boolJoyauxBleu==FALSE)))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleCroix, &mur, 1);
                    break;
                }
                break;

            case 5://salle4-----------------------------------------------------------------------------------------------------------------------
                //scene5
                switch(mur)
                {
                case 1:
                    //mur1
                    SDL_RenderCopy(renderer,salle4,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE) || (survol_souris(coordXYSurvol, taillecoffre)))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 2);
                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 3);
                    changement_scene(coordXYClique, taillecoffre, &mur, 5);

                    break;

                case 2:
                    //mur gauche
                    SDL_RenderCopy(renderer,salle4Gauche,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 4);
                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 1);

                    break;

                case 3:
                    //mur droite
                    SDL_RenderCopy(renderer,salle4Droite,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 4);
                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 1);

                    break;

                case 4:
                    //mur porte
                    SDL_RenderCopy(renderer,salle4Porte,NULL,NULL);//on dessine la texture image sur le rendu
                    SDL_RenderCopy(renderer,flecheDroite,NULL,&tailleFlechDroite);//fleche
                    SDL_RenderCopy(renderer,flecheGauche,NULL,&tailleFlechGauche);//fleche

                    if((survol_souris(coordXYSurvol, tailleFlechGauche) == TRUE) || (survol_souris(coordXYSurvol, tailleFlechDroite) == TRUE) || (survol_souris(coordXYSurvol, taillePorteSortie) == TRUE))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleFlechDroite, &mur, 2);
                    changement_scene(coordXYClique, tailleFlechGauche, &mur, 3);
                    changement_scene(coordXYClique, taillePorteSortie, &scene, 1);

                    break;

                case 5://coffre
                    SDL_RenderCopy(renderer,coffre,NULL,NULL);
                    SDL_RenderCopy(renderer,croix,NULL,&tailleCroix);

                    if(boolJoyauxJaune==FALSE)
                    {
                        SDL_RenderCopy(renderer,JoyauxJaune,NULL,&tailleJoyauxJaune);
                    }

                    if((clique_dans_boutton(coordXYClique,tailleJoyauxJaune)) && (boolJoyauxJaune==FALSE))
                    {
                        boolJoyauxJaune=TRUE;
                    }

                    if((survol_souris(coordXYSurvol, tailleCroix)) == TRUE || ((survol_souris(coordXYSurvol, tailleJoyauxJaune)) && (boolJoyauxJaune==FALSE)))
                    {
                        rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                        SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                    }

                    changement_scene(coordXYClique, tailleCroix, &mur, 1);
                    break;
                }
                break;

            case 6://enigme de fin
                SDL_RenderCopy(renderer,enigmeFin,NULL,NULL);
                SDL_RenderCopy(renderer,croix,NULL,&tailleCroix);

                if((survol_souris(coordXYSurvol, tailleCroix)) || (survol_souris(coordXYSurvol, tailleJoyauxBleuInventaire)) || (survol_souris(coordXYSurvol, tailleJoyauxRougeInventaire)) || (survol_souris(coordXYSurvol, tailleJoyauxJauneInventaire)) || (survol_souris(coordXYSurvol, tailleJoyauxVertInventaire)))
                {
                    rectBalle=tailleRect(coordXYSurvol.nX-5,coordXYSurvol.nY-5,10,10);
                    SDL_RenderCopy(renderer,balle,NULL,&rectBalle);
                }

                if(clique_dans_boutton(coordXYClique, tailleCroix))
                {
                    tailleJoyauxRougeInventaire = tailleRect(5, 5, 30, 30);
                    tailleJoyauxVertInventaire = tailleRect(35, 5, 30, 30);
                    tailleJoyauxBleuInventaire = tailleRect(65, 5, 30, 30);
                    tailleJoyauxJauneInventaire = tailleRect(95, 5, 30, 30);
                }
                changement_scene(coordXYClique, tailleCroix, &scene, 1);

                if(clique_dans_boutton(coordXYCliqueEnfoncer, tailleJoyauxRougeInventaire))
                {
                    joyauxSelect = ROUGE;
                }
                if(clique_dans_boutton(coordXYCliqueEnfoncer, tailleJoyauxBleuInventaire))
                {
                    joyauxSelect = BLEU;
                }
                if(clique_dans_boutton(coordXYCliqueEnfoncer, tailleJoyauxVertInventaire))
                {
                    joyauxSelect = VERT;
                }
                if(clique_dans_boutton(coordXYCliqueEnfoncer, tailleJoyauxJauneInventaire))
                {
                    joyauxSelect = JAUNE;
                }

                if(joyauxSelect == ROUGE)
                {
                    tailleJoyauxRougeInventaire=tailleRect(coordXYSurvol.nX-50, coordXYSurvol.nY-50, 100, 100);
                }
                if(joyauxSelect == BLEU)
                {
                    tailleJoyauxBleuInventaire=tailleRect(coordXYSurvol.nX-50, coordXYSurvol.nY-50, 100, 100);
                }

                if(joyauxSelect == VERT)
                {
                    tailleJoyauxVertInventaire=tailleRect(coordXYSurvol.nX-50, coordXYSurvol.nY-50, 100, 100);
                }

                if(joyauxSelect == JAUNE)
                {
                    tailleJoyauxJauneInventaire=tailleRect(coordXYSurvol.nX-50, coordXYSurvol.nY-50, 100, 100);
                }

                if((verifEnigmeFin(tailleEnigmeFin.carre1, tailleJoyauxBleuInventaire)) && (verifEnigmeFin(tailleEnigmeFin.carre2, tailleJoyauxJauneInventaire)) && (verifEnigmeFin(tailleEnigmeFin.carre3, tailleJoyauxRougeInventaire)) && (verifEnigmeFin(tailleEnigmeFin.carre4, tailleJoyauxVertInventaire)))
                {
                    boolJoyauxBleu = FALSE;
                    boolJoyauxRouge = FALSE;
                    boolJoyauxJaune = FALSE;
                    boolJoyauxVert = FALSE;

                    scene = 7;
                }

                break;

            case 7:
                SDL_RenderCopy(renderer,merci,NULL,NULL);
                break;
            }

            //inventaire
            if(boolJoyauxRouge)
            {
                SDL_RenderCopy(renderer,JoyauxRouge,NULL,&tailleJoyauxRougeInventaire);
            }
            if(boolJoyauxVert)
            {
                SDL_RenderCopy(renderer,JoyauxVert,NULL,&tailleJoyauxVertInventaire);
            }
            if(boolJoyauxBleu)
            {
                SDL_RenderCopy(renderer,JoyauxBleu,NULL,&tailleJoyauxBleuInventaire);
            }
            if(boolJoyauxJaune)
            {
                SDL_RenderCopy(renderer,JoyauxJaune,NULL,&tailleJoyauxJauneInventaire);
            }

            rezXYClique(&coordXYClique);
            SDL_RenderPresent(renderer);// on met à jour le rendu
            delay(framelimit);
            raf(renderer);
        }//____________________________________________________________________________________________
    }

    // On quitte la SDL
    SDL_DestroyTexture(balle);
    SDL_DestroyTexture(portes);
    SDL_DestroyTexture(txtStart);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return 0;
}
