#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#define SCREEN_W 1920
#define SCREEN_H 1080
typedef struct
{
int joueur;
SDL_Surface * image1,*image2,*image3;
int tabsuivi[9];
SDL_Rect pos;
int tour;
TTF_Font *PIXELADE;
SDL_Color couleur;
SDL_Rect posMSG;
}tic;

void initialisation(tic *t);
void affichage(tic t,SDL_Surface *ecran ) ;
int atilganer(int tabsuivi[]);
void calcul_coup(int tabsuivi[]);
void Resultat (tic t,SDL_Surface* ecran);
void liberationmemoire(tic t);


