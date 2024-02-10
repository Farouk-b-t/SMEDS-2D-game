#include"header.h"
void initBack(background* b,char* path){
	b->name=path;
	b->url=IMG_Load(b->name);
	if(b->url==NULL){
		printf("Pas d'image back\n");
	}
	b->pos.x=0;
	b->pos.y=0;
	b->pos.w=b->url->w;
	b->pos.h=b->url->h;
}
void afficherBack(background b, SDL_Surface* screen,int x,int y){
	b.pos.x=x;
	b.pos.y=y;
	SDL_BlitSurface(b.url,NULL,screen,&(b.pos));
}
void free_bg(background b){
	SDL_FreeSurface(b.url);
}
void initialiser_text(texte* text,char* font,float size,int r,int g,int b,int x,int y){
	text->font=TTF_OpenFont(font,size);
	text->color.r=r;
	text->color.g=g;
	text->color.b=b;
	text->pos.x=x;
	text->pos.y=y;
}
void afficher_text(SDL_Surface* screen,texte text,char* message){
	text.txt=TTF_RenderText_Blended(text.font,message,text.color);
	SDL_BlitSurface(text.txt,NULL,screen,&text.pos);
}
void free_text(texte text){
	TTF_CloseFont(text.font);
}
void scrolling(background* b,int up,int down,int r,int l,int x,int y){
	if(r==1){
		if((b->pos.x)>-11311){
			b->pos.x-=x;
		}
	}
	if(l==1){
		if((b->pos.x+x)<0){
			b->pos.x+=x;
		}
	}
	if(up==1){
		if((b->pos.y+y)<0){
			b->pos.y+=y;
		}
	}
	if(down==1){
		if((b->pos.y)>-50){
			b->pos.y-=y;
		}
	}
}
void scrolling_caractere(background b,character *c,int up,int down,int r,int l,int *moving){
	if(r==1){
		if((c->pos.x+c->actuelimage.url->w)<1400){
			c->pos.x+=20;
			(*moving)=1;
		}
		else{
			if(b.pos.x<=-11311 && (c->pos.x+c->actuelimage.url->w)<=1885){
				c->pos.x+=5;
				(*moving)=1;
			}
			else{
				(*moving)=0;
			}
		}
	}
	if(l==1){
		if(c->pos.x>=200){
			c->pos.x-=20;
			(*moving)=1;
		}
		else{
			if(b.pos.x>=-20 && c->pos.x>=-70){
				c->pos.x-=5;
				(*moving)=1;
			}
			else{
				(*moving)=0;
			}
		}
	}
	if(up==1){
		if(c->pos.y>0){
			c->pos.y-=5;
		}
	}
	if(down==1){
		if(c->pos.y<600){
			c->pos.y+=5;
		}
	}
}
void saveScore(ScoreInfo s,char* filename){
	FILE* f=fopen(filename,"a");
	if(f==NULL){
		printf("Espace memoire insuffisant!!\n");
	}
	else{
		fprintf(f,"Nom:%s | Score:%d | Temps:%d \n",s.playername,s.score,s.temps);
		fclose(f);
	}
}
int compareScores(const void* a, const void* b) {
    // Compare scores in descending order
    const ScoreInfo* scoreA = (const ScoreInfo*)a;
    const ScoreInfo* scoreB = (const ScoreInfo*)b;
    return scoreB->score - scoreA->score;
}

void bestScore(char* filename, ScoreInfo* t) {
    char st[strlen(filename)+4];
    strcpy(st, strcat(filename, ".txt"));
    FILE* f = fopen(filename, "r");
    int score, temps;
    char name[20];
    int i = 0;

    if (f == NULL) {
        printf("Espace memoire insuffisant!!\n");
        return;  // Return if file cannot be opened
    }

    while (!(feof(f))) {
        t = (ScoreInfo*)realloc(t, (i+1) * sizeof(ScoreInfo));
        fscanf(f, "Nom:%s | Score:%d | Temps:%d \n", (t+i)->playername, &(t+i)->score, &(t+i)->temps);
        i++;
    }
    fclose(f);

    // Sort scores in descending order
    qsort(t, i, sizeof(ScoreInfo), compareScores);

    // Display the three best scores
    printf("Three best scores:\n");
    int numScoresToDisplay = (i < 3) ? i : 3;
    for (int j = 0; j < numScoresToDisplay; j++) {
        printf("Nom:%s | Score:%d | Temps:%d\n", (t+j)->playername, (t+j)->score, (t+j)->temps);
    }
}
//////////////////////////////////////////////////
//animation bg
void init_object(object *o,int x,int y){
	char string[30];
	o->frame=0;
	o->pos.x=x;
	o->pos.y=y;
	for(int i=0;i<20;i++){
		sprintf(string,"v1.0/gfx/light/%d.png",i+1);
		o->img[i].url=IMG_Load(string);
		if (o->img[i].url==NULL){
			printf("pas d'image");
		}
	}
}
void afficher_lampe(object *o,SDL_Surface* screen,int x,int y){
	o->pos.x=x;
	o->pos.y=y;
	SDL_BlitSurface(o->actuel.url,NULL,screen,&(o->pos));
}
void animation_bg(object * o){
	if (o->frame>20) {
    		o->frame=0;
  	}
  	else{
  		o->frame++;
  	}
  	o->actuel=o->img[o->frame];
}
void free_object(object o){
	for(int i=0;i<20;i++){
		SDL_FreeSurface(o.img[i].url);
	}
}
//tache blanche
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
