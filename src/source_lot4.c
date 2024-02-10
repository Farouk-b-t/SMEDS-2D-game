#include"header.h"

void initialiserMinimap(minimap *m)
{
  m->imgmini=IMG_Load("v1.0/gfx/minimap/map_stg_2_minimap.png");
  m->img_bh=IMG_Load("v1.0/gfx/minimap/mini_Hero.png");
 m->pos_imgmini.x = 280;
 m->pos_imgmini.y = 70;


}

void afficher(minimap m, SDL_Surface *screen)
{

SDL_BlitSurface(m.imgmini, NULL, screen, &m.pos_imgmini);
SDL_BlitSurface(m.img_bh, NULL, screen, &m.pos_bh);

}
void Liberer (minimap *m)
{
SDL_FreeSurface((*m).imgmini);
SDL_FreeSurface((*m).img_bh);
}
void MAJMinimap(SDL_Rect posJoueur, minimap *m, int redimensionnement)
{

SDL_Rect posJoueurABS,camera;
camera.x=400;
camera.y=90;
posJoueurABS.x = posJoueur.x + camera.x;
posJoueurABS.y = posJoueur.y + camera.y;

m->pos_bh.x=((posJoueur.x * redimensionnement)/100)+280;
m->pos_bh.y=((posJoueur.y * redimensionnement)/100)+10;
}



SDL_Color GetPixel(SDL_Surface *Masque,int x,int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char*)Masque->pixels;
pPosition+=(Masque->pitch *y);
pPosition+=(Masque->format->BytesPerPixel *x);
memcpy(&col,pPosition,Masque->format->BytesPerPixel);
SDL_GetRGB(col,Masque->format,&color.r,&color.g,&color.b);
return(color);
}


int collision_pp_right(SDL_Surface *mask , SDL_Rect posjoueur )
{  SDL_Color col,colp;
SDL_Rect pos[5];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;

w=102;
h=200;

pos[0].x = posjoueur.x +w;
pos[0].y = posjoueur.y;
pos[1].x = posjoueur.x +w;
pos[1].y = posjoueur.y+ h/4;
pos[2].x = posjoueur.x +w;
pos[2].y = posjoueur.y+ h/2;
pos[3].x = posjoueur.x +w;
pos[3].y = posjoueur.y+ 3*h/4;
pos[4].x = posjoueur.x +w;
pos[4].y = posjoueur.y +h;
for (i =0;(i < 5)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y);
//printf("r:%d , g:%d , b:%d",colp.r,colp.g,colp.b);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;}
return (collision);
}

int collision_pp_left(SDL_Surface *mask, SDL_Rect posjoueur)
{
SDL_Color col,colp;
SDL_Rect pos[5];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=102;
h=200;
pos[0].x = posjoueur.x;
pos[0].y = posjoueur.y;
pos[1].x = posjoueur.x;
pos[1].y = posjoueur.y+(h/4);
pos[2].x = posjoueur.x;
pos[2].y = posjoueur.y+(h/2);
pos[3].x = posjoueur.x;
pos[3].y = posjoueur.y+(3*h/4);
pos[4].x = posjoueur.x;
pos[4].y = posjoueur.y+h;
for (i =0;(i < 5)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;}
return (collision);
}


int collision_pp_up(SDL_Surface *mask, SDL_Rect posjoueur)
{
SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=102;
h=200;


pos[0].x = posjoueur.x;
pos[0].y = posjoueur.y;
pos[1].x = posjoueur.x + w/2;
pos[1].y = posjoueur.y;
pos[2].x = posjoueur.x+w;
pos[2].y = posjoueur.y;
for (i =0;(i < 3)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;}
return (collision);
}

int collision_pp_down(SDL_Surface *mask, SDL_Rect posjoueur)
{
SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=102;
h=200;


pos[0].x = posjoueur.x;
pos[0].y = posjoueur.y+h;
pos[1].x = posjoueur.x+ w /2;
pos[1].y = posjoueur.y +h;
pos[2].x = posjoueur.x +w;
pos[2].y = posjoueur.y +h;
for (i =0;(i < 3)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;}
return (collision);
}


void afficher_temps(SDL_Surface* screen, int temps) {
    int heures = temps / 3600000;  
    int minutes = (temps % 3600000) / 60000; 
    int secondes = (temps % 60000) / 1000; 

   
    TTF_Font* police = TTF_OpenFont("v1.0/font/PIXELADE.TTF", 60);
    if (police == NULL) {
        fprintf(stderr, "Erreur : impossible de charger la police : %s\n", TTF_GetError());
        return;
    }

    
    char temps_str[32];
    snprintf(temps_str, 32, "%02d:%02d",minutes, secondes); 
    SDL_Color couleur = { 220, 178, 51, 0 }; 
    SDL_Surface* texte = TTF_RenderText_Blended(police, temps_str, couleur);
    if (texte == NULL) {
        fprintf(stderr, "Erreur : impossible de créer la surface de texte : %s\n", TTF_GetError());
        TTF_CloseFont(police);
        return;
    }

    

    
    SDL_Rect position = { 1620, 10, 0, 0 };
    SDL_BlitSurface(texte, NULL, screen, &position);

    
 
    TTF_CloseFont(police);
}




void animer_Enigme_point(img_animation images[]) {
    images[0].filename = "v1.0/gfx/animation_Enigme_point/1.png";
    images[1].filename = "v1.0/gfx/animation_Enigme_point/2.png";
    images[2].filename = "v1.0/gfx/animation_Enigme_point/3.png";
    images[3].filename = "v1.0/gfx/animation_Enigme_point/4.png";
    images[4].filename = "v1.0/gfx/animation_Enigme_point/5.png";
    images[5].filename = "v1.0/gfx/animation_Enigme_point/6.png";
    images[6].filename = "v1.0/gfx/animation_Enigme_point/7.png";
    images[7].filename = "v1.0/gfx/animation_Enigme_point/8.png";
    images[8].filename = "v1.0/gfx/animation_Enigme_point/9.png";
    images[9].filename = "v1.0/gfx/animation_Enigme_point/10.png";
    images[10].filename = "v1.0/gfx/animation_Enigme_point/11.png";
    images[11].filename = "v1.0/gfx/animation_Enigme_point/12.png";
    images[12].filename = "v1.0/gfx/animation_Enigme_point/13.png";
    images[13].filename = "v1.0/gfx/animation_Enigme_point/14.png";
       

    for (int i = 0; i < 13; i++) {
        images[i].surface = IMG_Load(images[i].filename);
        if (images[i].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", images[i].filename, SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
}

void free_images_animer_Enigme_point(img_animation images[]) {
    for (int i = 0; i < 13; i++) {
        SDL_FreeSurface(images[i].surface);
    }
}


void animer_mini_Enigme_point(img_animation images[]) {
    images[0].filename = "v1.0/gfx/animation_mini_Enigme_point/1.png";
    images[1].filename = "v1.0/gfx/animation_mini_Enigme_point/2.png";
    images[2].filename = "v1.0/gfx/animation_mini_Enigme_point/3.png";
    images[3].filename = "v1.0/gfx/animation_mini_Enigme_point/4.png";
    images[4].filename = "v1.0/gfx/animation_mini_Enigme_point/5.png";
    images[5].filename = "v1.0/gfx/animation_mini_Enigme_point/6.png";
    images[6].filename = "v1.0/gfx/animation_mini_Enigme_point/7.png";
    images[7].filename = "v1.0/gfx/animation_mini_Enigme_point/8.png";
    images[8].filename = "v1.0/gfx/animation_mini_Enigme_point/9.png";
    images[9].filename = "v1.0/gfx/animation_mini_Enigme_point/10.png";
    images[10].filename = "v1.0/gfx/animation_mini_Enigme_point/11.png";
    images[11].filename = "v1.0/gfx/animation_mini_Enigme_point/12.png";
    images[12].filename = "v1.0/gfx/animation_mini_Enigme_point/13.png";
    images[13].filename = "v1.0/gfx/animation_mini_Enigme_point/14.png";
       

    for (int i = 0; i < 13; i++) {
        images[i].surface = IMG_Load(images[i].filename);
        if (images[i].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", images[i].filename, SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
}

void free_images_animer_mini_Enigme_point(img_animation images[]) {
    for (int i = 0; i < 13; i++) {
        SDL_FreeSurface(images[i].surface);
    }
}


