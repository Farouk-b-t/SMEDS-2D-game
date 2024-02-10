#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#define SCREEN_W 1920
#define SCREEN_H 1080
typedef struct{
	char *name;
	SDL_Surface *url;
	SDL_Rect pos;
}image;
typedef struct{
	SDL_Surface *txt;
	SDL_Rect pos;
	SDL_Color color;
	TTF_Font *font;
}texte;
//animation:
typedef struct {
    char *filename;
    SDL_Surface *surface;
} menu_animation;
void load_images(menu_animation images[]);
void free_images(menu_animation images[]);
     ////
void initilize_img(image* img,char* path,int x,int y);
//afficher une image:
void afficher_image(SDL_Surface *surf,image img);
//liberer:
void free_image(image img);
//intro music:
void intro(Mix_Music *music);
//liberer:
void liberer_music(Mix_Music *music);
// musique bref:
void musiquebref_click(Mix_Chunk *music,int volume);
void musiquebref_drag(Mix_Chunk *music,int volume);
//liberer:
void liberer_musiquebref(Mix_Chunk *music);
void initialiser_text(texte* text,char* font,float size,int r,int g,int b,int x,int y);
void afficher_text(SDL_Surface* screen,texte text,char* message);
void free_text(texte text);
