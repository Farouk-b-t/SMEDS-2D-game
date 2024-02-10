#include"header.h"
void initEnnemi(character *e,int x,int y){
	char string[50];
	e->pos.x=x;
	e->pos.y=y;
	e->health=100;
	e->direction=1;
	e->frame=0;
	e->actuelimage.url=IMG_Load("v1.0/gfx/right/NPC/IDLE/1.png");
	for(int i=0;i<5;i++){
		sprintf(string,"v1.0/gfx/right/NPC/RUN/%d.png",i+1);
		e->RUN_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/NPC/RUN/%d.png",i+1);
		e->RUN_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<33;i++){
		sprintf(string,"v1.0/gfx/right/NPC/ATTACK/%d.png",i+1);
		e->ATTACK_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/NPC/ATTACK/%d.png",i+1);
		e->ATTACK_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<8;i++){
		sprintf(string,"v1.0/gfx/right/NPC/DEATH/%d.png",i+1);
		e->DEATH_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/NPC/DEATH/%d.png",i+1);
		e->DEATH_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<5;i++){
		sprintf(string,"v1.0/gfx/right/NPC/IDLE/%d.png",i+1);
		e->IDLE_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/NPC/IDLE/%d.png",i+1);
		e->IDLE_L[i].url=IMG_Load(string);
	}
}
void init_grimgor(character *e,int x,int y){
	char string[50];
	e->pos.x=x;
	e->pos.y=y;
	e->health=100;
	e->frame=0;
	e->actuelimage.url=IMG_Load("v1.0/gfx/right/grimgor/idle/1.png");
	for(int i=0;i<17;i++){
		sprintf(string,"v1.0/gfx/right/grimgor/run/%d.png",i+1);
		e->RUN_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/grimgor/run/%d.png",i+1);
		e->RUN_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<48;i++){
		sprintf(string,"v1.0/gfx/right/grimgor/attack/%d.png",i+1);
		e->ATTACK_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/grimgor/attack/%d.png",i+1);
		e->ATTACK_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<48;i++){
		sprintf(string,"v1.0/gfx/right/grimgor/death/%d.png",i+1);
		e->DEATH_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/grimgor/death/%d.png",i+1);
		e->DEATH_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<11;i++){
		sprintf(string,"v1.0/gfx/right/grimgor/hurt/%d.png",i+1);
		e->HIT_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/grimgor/hurt/%d.png",i+1);
		e->HIT_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<25;i++){
		sprintf(string,"v1.0/gfx/right/grimgor/idle/%d.png",i+1);
		e->IDLE_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/gfx/left/grimgor/idle/%d.png",i+1);
		e->IDLE_L[i].url=IMG_Load(string);
	}
}
void afficherEnnemi(character *e,SDL_Surface* screen,int x,int y){
	e->pos.x=x;
	e->pos.y=y;
	SDL_BlitSurface(e->actuelimage.url,NULL,screen,&(e->pos));
}
void initilize_img(image* img,char* path,int x,int y){
	img->name=path;
	img->url=IMG_Load(img->name);
	if(img->url==NULL){
		printf("Pas d'image img\n");
	}
	else{
		img->pos.x=x;
		img->pos.y=y;
	}
}
void free_image(image img){
	SDL_FreeSurface(img.url);
}
void afficher_image(SDL_Surface *surf,image img){
	SDL_BlitSurface(img.url,NULL,surf,&(img.pos));
}
//////////////////////////////
void boss_run(character * e){
	if (e->frame>=17) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=17){
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
void boss_attack(character * e){
	if (e->frame>=48) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=48){
	  	if (e->direction==1){
	  		e->actuelimage=e->ATTACK_L[e->frame];
	  	}
	  	else{
	  		if(e->direction==0){
	  			e->actuelimage=e->ATTACK_R[e->frame];
	  		}
		}
	}
	SDL_Delay(5);
}
void boss_stand_by(character * e){
	if (e->frame>=25) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=25){
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
void boss_death(character * e){
	if (e->frame>=48) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=48){
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
/////////////////////////////
void NPC_run(character * e){
	if (e->frame>=5) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=5){
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
void NPC_attack(character * e){
	if (e->frame>=33) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=33){
	  	if (e->direction==1){
	  		e->actuelimage=e->ATTACK_L[e->frame];
	  	}
	  	else{
	  		if(e->direction==0){
	  			e->actuelimage=e->ATTACK_R[e->frame];
	  		}
		}
	}
	SDL_Delay(5);
}
void Ennemy_stand_by(character * e){
	if (e->frame>=5) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=5){
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
void NPC_death(character * e){
	if (e->frame>=8) {
    		e->frame=0;
  	}
  	else{
  		e->frame++;
  	}
  	if(e->frame!=8){
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
void move(character * e,character dest, SDL_Surface* screen,int moving){
	if(moving==1){
		if(e->pos.x>dest.pos.x){
			e->direction=1;
			e->pos.x-=4;
			SDL_Delay(5);
		}
		else{
			e->direction=0;
			e->pos.x+=4;
			SDL_Delay(5);
		}
	}
}
int approach(character a,character b){
	if(a.pos.x==b.pos.x){
		return 1;
	}
	else{
		if(a.pos.x>b.pos.x && (a.pos.x<=(b.pos.x+b.actuelimage.url->w))){
			return 1;
		}
		else{
			if(a.pos.x<b.pos.x && (b.pos.x<=(a.pos.x+a.actuelimage.url->w))){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
}
int collisionBB(character a,character b){
	if((a.pos.x>=b.pos.x && a.pos.x<=(b.pos.x+250)) || (b.pos.x>=a.pos.x && b.pos.x<=(a.pos.x+250))){
		return 1;
	}
	else{
		return 0;
	}
}
void moveIA(character * e,character *h,SDL_Surface* screen,int *attack,int moving,int* on){
	int diff=e->pos.x-h->pos.x;
	if(e->pos.x>h->pos.x){
		if(e->pos.x-h->pos.x<400){
			(*attack)=1;
		}
		if((*attack)==0){
			printf("wait1\n");
			if(e->pos.x<=1000){
				e->direction=0;
			}
			if(e->pos.x>=1500){
				e->direction=1;
			}
			if(e->direction==0){
				e->pos.x+=5;
			}
			else{
				e->pos.x-=5;
			}
			NPC_run(e);
			SDL_Delay(12);
		}
		else{
			if(e->pos.x-h->pos.x>=100){
				printf("move1\n");
				move(e,*h,screen,moving);
				NPC_run(e);
			}
			else{
				(*on)=1;
				if((*on)==1){
					printf("attack1\n");
					NPC_attack(e);
					SDL_Delay(10);
					(*on)=0;
				}
				if(collisionBB(*h,*e)){
					damage(h,1);
				}
			}
		}
	}
	else{
		if(e->pos.x<h->pos.x){
			if(h->pos.x-e->pos.x<=100){
				(*on)=1;
				if((*on)==1){
					printf("attack2\n");
					NPC_attack(e);
					SDL_Delay(10);
					(*on)=0;
				}
			}
			else{
				move(e,*h,screen,moving);
				NPC_run(e);
			}
		}
	}
}
void moveIA_boss(character * e,character *h,SDL_Surface* screen,int *attack,int moving,int* on){
	int diff=e->pos.x-h->pos.x;
	if(e->pos.x>h->pos.x){
		if(e->pos.x-h->pos.x<400){
			(*attack)=1;
		}
		if((*attack)==0){
			printf("wait1\n");
			if(e->pos.x<=1000){
				e->direction=0;
			}
			if(e->pos.x>=1500){
				e->direction=1;
			}
			if(e->direction==0){
				e->pos.x+=5;
			}
			else{
				e->pos.x-=5;
			}
			boss_run(e);
			SDL_Delay(12);
		}
		else{
			if(e->pos.x-(h->pos.x+240)>=10){
				printf("move1\n");
				move(e,*h,screen,moving);
				boss_run(e);
			}
			else{
				(*on)=1;
				if((*on)==1){
					printf("attack1\n");
					boss_attack(e);
					SDL_Delay(10);
					(*on)=0;
				}
				if(collisionBB(*h,*e)){
					damage(h,1);
				}
			}
		}
	}
	else{
		if(e->pos.x<h->pos.x){
			if(h->pos.x-(e->pos.x+250)<=10){
				(*on)=1;
				if((*on)==1){
					printf("attack2\n");
					boss_attack(e);
					SDL_Delay(10);
					(*on)=0;
				}
			}
			else{
				move(e,*h,screen,moving);
				boss_run(e);
			}
		}
	}
}
