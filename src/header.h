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
int score;
int temps;
char playername[20];
}ScoreInfo;
typedef struct{
	char *name;
	SDL_Surface *url;
	SDL_Rect pos;
}image;
typedef struct{
	int vie;
	char *name;
	SDL_Surface *url;
	SDL_Rect pos;
	float vitesse ;
	float acceleration;
	int up; 
	int health;
	ScoreInfo SI;
	int frame;
	int direction;
	image RUN_R[17];
	image RUN_L[17];
	image ATTACK_R[48];
	image ATTACK_L[48];
	image DEATH_R[18];
	image DEATH_L[18];
	image HIT_R[11];
	image HIT_L[11];
	image IDLE_R[30];
	image IDLE_L[30];
	image JUMP_R[7];
	image JUMP_L[7];
	image actuelimage;
}character;
typedef struct{
	SDL_Surface* url;
	SDL_Rect pos;
	char* name;
}background;
typedef struct 
{
	int vie;
	image vies[3];
	SDL_Rect pos;
}vie;
typedef struct {
    char *path;
    SDL_Rect pos;
    SDL_Surface *surface;
}Image;
typedef struct{
	SDL_Surface *txt;
	SDL_Rect pos;
	SDL_Color color;
	TTF_Font *font;
}texte;
typedef struct {
	int frame;
	image img[20];
	image actuel;
	SDL_Rect pos;
}object;
typedef struct{
	SDL_Surface *imgmini;
	SDL_Rect pos_imgmini;
	SDL_Surface *img_bh;
	SDL_Rect pos_bh;
}minimap;
typedef struct {
    char *filename;
    SDL_Surface *surface;
} img_animation;
typedef struct {
    char *filename;
    SDL_Surface *surface;
} menu_animation;
//liberer:
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
/////////////////////////
void load_images(menu_animation images[]);
void free_images(menu_animation images[]);
/////////////lot3
void initEnnemi(character *e,int x,int y);
void afficherEnnemi(character *e,SDL_Surface* screen,int x,int y);
void NPC_run(character * e);
void NPC_attack(character * e);
void Ennemy_stand_by(character * e);
void NPC_death(character * e);
void move(character * e,character dest,SDL_Surface* screen,int moving);
int approach(character a,character b);
int collisionBB(character a,character b);
void hero_run(character * e);
void hero_jump(character * e);
void hero_attack(character * e);
void hero_stand_by(character * e);
void hero_death(character * e);
void moveIA(character * e,character * h,SDL_Surface* screen,int *attack,int moving,int *on);
void init_grimgor(character *e,int x,int y);
void boss_run(character * e);
void boss_attack(character * e);
void boss_stand_by(character * e);
void boss_death(character * e);
void moveIA_boss(character * e,character * h,SDL_Surface* screen,int *attack,int moving,int *on);
/////////////////////////////////////////////
void load_images_right(menu_animation images[]);
void load_images_left(menu_animation images[]);
void free_images(menu_animation images[]);
/////////////////////////////////////////////
void afficher_image(SDL_Surface *surf,image img);
void initilize_img(image* img,char* path,int x,int y);
///////////////////lot2
void initBack(background* b,char* path);
void afficherBack(background b, SDL_Surface* screen,int x,int y);
void scrolling(background* b,int up,int down,int r,int l,int x,int y);
void scrolling_caractere (background b,character* c,int up,int down,int r,int l,int *moving);
void animerBack(background* b);
void saveScore(ScoreInfo s,char* filename);
void bestScore(char* filename,ScoreInfo t[]);
int compareScores(const void* a, const void* b);
void free_bg(background b);
////////////////////////////////////////////////////
void init_character(character* ch,int x,int y);
void afficher_character(SDL_Surface *surf,character *ch,int x,int y);
void free_character(character ch);
///////////////////////////////////////
void initilize_img(image* img,char* path,int x,int y);
void afficher_image(SDL_Surface *surf,image img);
void free_image(image img);
////////////////////////////////////////////////////
void initialiser_text(texte* text,char* font,float size,int r,int g,int b,int x,int y);
void afficher_text(SDL_Surface* screen,texte text,char* message);
void free_text(texte text);
void load_animation(char* path,int n,image* images);
void animate_images(SDL_Surface* screen, image* images, int num_images, int image_delay);
void liberer_music(Mix_Music *music);
void musiquebref_click(Mix_Chunk *music,int volume);
void musiquebref_drag(Mix_Chunk *music,int volume);
/////////////////////////////////////////////////////////////////
void init_vie(vie* v,int x,int y);
void afficher_vies(SDL_Surface *surf,vie* v,int x,int y,int num);
void free_vie(vie v,int num);
void jump(character *ch);
void damage(character *h,int collision);
////////////////////////////////////////////////
void init_object(object *o,int x,int y);
void afficher_lampe(object *o,SDL_Surface* screen,int x,int y);
void animation_bg(object * o);
void free_object(object o);
////////////////////////////////////////////////////lot4:
void initialiserMinimap(minimap *m);
void mini_jump(SDL_Rect* pos,int *up);
void MAJMinimap(SDL_Rect posJoueur, minimap *m, int redimensionnement);
void afficher(minimap m,SDL_Surface *screen);
void Liberer(minimap *m);
void afficher_temps(SDL_Surface* screen, int temps);
void time_enigme(SDL_Surface* screen, int temps);
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);
int collision_pp_right(SDL_Surface *mask , SDL_Rect posjoueur );
int collision_pp_left(SDL_Surface *mask , SDL_Rect posjoueur );
int collision_pp_up(SDL_Surface *mask , SDL_Rect posjoueur );
int collision_pp_down(SDL_Surface *mask , SDL_Rect posjoueur );
void animer_Enigme_point(img_animation images[]) ;
void free_images_animer_Enigme_point(img_animation images[]);
void animer_mini_Enigme_point(img_animation images[]);
void free_images_animer_mini_Enigme_point(img_animation images[]) ;
///////////////////////////////////////////////////
void load_game(char nomFich[], int* x, int* y, Sint16* bx, Sint16* by, Sint16* ex, Sint16* ey, int* score);
void save_game(char nomFich[], int x, int y, int bx, int by, int ex, int ey, int score);
void buttons_fleche( SDL_Event* event, int* entre_r, int* entre_l, int* entre_q, int* end);
///////////////////////////////////////////////////
void load_game(char nomFich[], int* x, int* y, Sint16* bx, Sint16* by, Sint16* ex, Sint16* ey, int* score);
void save_game(char nomFich[], int x, int y, int bx, int by, int ex, int ey, int score);
void buttons_fleche( SDL_Event* event, int* entre_r, int* entre_l, int* entre_q, int* end);
