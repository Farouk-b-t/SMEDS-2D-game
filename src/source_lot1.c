#include"header.h"
void init_vie(vie* v,int x,int y)
{
int i;
	char string[30];
	v->pos.x=x;
	v->pos.y=y;
	for(int i=0;i<4;i++){
		sprintf(string,"v1.0/gfx/vie/%d.png",i);
		v->vies[i].url=IMG_Load(string);
	}
}
void afficher_vies(SDL_Surface *surf,vie* v,int x,int y,int num)
{
	v->pos.x=x;
	v->pos.y=y;
	if(num<0){
		num=0;
	}
	SDL_BlitSurface(v->vies[num].url,NULL,surf,&(v->pos));
}
void damage(character *h,int collision){
	if(collision==1){
		h->vie--;
	}
}
void init_character(character* e,int x,int y)
{
	char string[50];
	e->pos.x=x;
	e->pos.y=y;
	e->health=100;
	e->frame=0;
	e->SI.score=0;
	e->vie=3;
	e->actuelimage.url=IMG_Load("v1.0/gfx/right/HERO/IDLE/1.png");
	for(int i=0;i<8;i++){
		sprintf(string,"v1.0/gfx/right/HERO/RUN/%d.png",i+1);
		e->RUN_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/HERO/RUN/%d.png",i+1);
		e->RUN_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<28;i++){
		sprintf(string,"v1.0/gfx/right/HERO/ATTACK/%d.png",i+1);
		e->ATTACK_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/HERO/ATTACK/%d.png",i+1);
		e->ATTACK_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<18;i++){
		sprintf(string,"v1.0/gfx/right/HERO/DEATH/%d.png",i+1);
		e->DEATH_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/HERO/DEATH/%d.png",i+1);
		e->DEATH_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<7;i++){
		sprintf(string,"v1.0/gfx/right/HERO/JUMP/%d.png",i+1);
		e->JUMP_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/HERO/JUMP/%d.png",i+1);
		e->JUMP_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<24;i++){
		sprintf(string,"v1.0/gfx/right/HERO/IDLE/%d.png",i+1);
		e->IDLE_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/HERO/IDLE/%d.png",i+1);
		e->IDLE_L[i].url=IMG_Load(string);
	}
	(*e).vitesse=10;
	(*e).acceleration=0;
	(*e).up=0;
}
void afficher_character(SDL_Surface *surf,character *ch,int x,int y)
{
	ch->pos.x=x;
	ch->pos.y=y;
	ch->pos.w=ch->actuelimage.url->w;
	ch->pos.h=ch->actuelimage.url->h;
	SDL_BlitSurface(ch->actuelimage.url,NULL,surf,&(ch->pos));
}

void free_character(character ch)
{
	SDL_FreeSurface(ch.url);
}
void free_vie(vie v,int num)
{
	SDL_FreeSurface(v.vies[num].url);
}
void jump(character *ch)
{
const int seuil=400;

if (ch->up==1 && ch->pos.y > (500 -seuil) )// si saut est activee et limite n est pas atteinte
{
   ch->pos.y=ch->pos.y-80; //deplacement vers le haut
   //anim_character_jump(ch);
   hero_jump(ch);
  }
  else if (ch->up==1 && ch->pos.y <=  500-seuil  )//seuil atteint 
  {
  ch->up=-1; //etat en descente
  hero_jump(ch);
  }
  else if (ch->up==-1 && ch->pos.y<500) 
  {
  ch->pos.y= ch->pos.y+80;
  hero_jump(ch);
  }
  else //ch->pos_hero.y==posinit
  {
  ch->up=0; //saut desactivee
  }
}
void mini_jump(SDL_Rect* pos,int *up)
{
const int seuil=400;

if ((*up)==1 && pos->y > (400 -seuil) )// si saut est activee et limite n est pas atteinte
{
   pos->y=pos->y-80; //deplacement vers le haut
   //anim_character_jump(ch);
  }
  else if ((*up)==1 && pos->y <=  400-seuil  )//seuil atteint 
  {
  (*up)=-1; //etat en descente
  }
  else if ((*up)==-1 && pos->y<400) 
  {
  pos->y=pos->y+80;
  }
  else //ch->pos_hero.y==posinit
  {
  (*up)=0; //saut desactivee
  }
}
void hero_run(character * e){
	if (e->frame>=8) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=8){
	  	if (e->direction==1){
	  		e->actuelimage=e->RUN_L[e->frame];
	  	}
	  	else{
	  		if(e->direction==0){
	  			e->actuelimage=e->RUN_R[e->frame];
	  		}
		}
	}
}
void hero_jump(character * e){
	if (e->frame>=7) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=7){
	  	if (e->direction==1){
	  		e->actuelimage=e->JUMP_L[e->frame];
	  	}
	  	else{
	  		if(e->direction==0){
	  			e->actuelimage=e->JUMP_R[e->frame];
	  		}
		}
	}
}
void hero_attack(character * e){
	if (e->frame>=28) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=28){
	  	if (e->direction==1){
	  		e->actuelimage=e->ATTACK_L[e->frame];
	  	}
	  	else{
	  		if(e->direction==0){
	  			e->actuelimage=e->ATTACK_R[e->frame];
	  		}
		}
		SDL_Delay(10);
	}
}
void hero_stand_by(character * e){
	if (e->frame>=24) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=24){
	  	if (e->direction==1){
	  		e->actuelimage=e->IDLE_L[e->frame];
	  	}
	  	else{
	  		if(e->direction==0){
	  			e->actuelimage=e->IDLE_R[e->frame];
	  		}
		}
	}
}
void hero_death(character * e){
	if (e->frame>=18) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=18){
	  	if (e->direction==1){
	  		e->actuelimage=e->DEATH_L[e->frame];
	  	}
	  	else{
	  		if(e->direction==0){
	  			e->actuelimage=e->DEATH_R[e->frame];
	  		}
		}
	}
}
