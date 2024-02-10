
#include "headerTB.h"

void initialisation(tic * t)
{
    int i;
    for(i=0;i<9;i++)
    t-> tabsuivi[i]=0;
    t->image1=SDL_LoadBMP("fond.bmp");
    t->image2=IMG_Load("croix.png");
    t->image3=IMG_Load("cercle.png");
    t->joueur=1;
    t->tour=0;
    t->PIXELADE=TTF_OpenFont("PIXELADE.TTF",60);
    t->couleur.r=187;
    t->couleur.g=11;
    t->couleur.b=11;
    t->posMSG.x=0;
    t->posMSG.y=0;
}

void affichage(tic t,SDL_Surface *ecran ) 
{
    int i;
    SDL_BlitSurface(t.image1,NULL,ecran,NULL);
    for(i=0;i<9;i++){
    	t.pos.x=180*(i%3);
        t.pos.y=180*(i/3);
        	switch(t.tabsuivi[i])
        		{
        	    		case -1:
        	        		SDL_BlitSurface(t.image2,NULL,ecran,&t.pos);	
        	    		break;
        	    		case 1:
        	        		SDL_BlitSurface(t.image3,NULL,ecran,&t.pos);
        	    		break;
        		}
                    }  
}

void Resultat (tic t,SDL_Surface* ecran)
{
    char msg[20];
    affichage(t,ecran);
    switch(atilganer(t.tabsuivi))
    {
        case 0:
            strcpy(msg, "NUL");
        break;
        case 1:
            strcpy(msg, "Defaite");
        break;
        case -1:  
            strcpy(msg, "Victoire");
    }

     SDL_BlitSurface(TTF_RenderText_Solid(t.PIXELADE,msg,t.couleur),NULL,ecran,&t.posMSG);
     SDL_Flip(ecran);
     SDL_Delay(4000);
}

void liberationmemoire(tic t)
{
    SDL_FreeSurface(t.image1);
    SDL_FreeSurface(t.image2);
    SDL_FreeSurface(t.image3);
}

int atilganer(int tabsuivi[])
{
    int lignes_gagnantes[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i=0;i<8;++i)
        if(tabsuivi[lignes_gagnantes[i][0]]!=0&&
           tabsuivi[lignes_gagnantes[i][0]]==tabsuivi[lignes_gagnantes[i][1]]&&
           tabsuivi[lignes_gagnantes[i][0]]==tabsuivi[lignes_gagnantes[i][2]])
                return tabsuivi[lignes_gagnantes[i][2]];
    return 0;
}

void calcul_coup(int tabsuivi[])
{
    int i=0;
	while(i<9 && tabsuivi[i]!=0)
	{
		i++;
	}
	if(i<9)
	{
		tabsuivi[i]=1;
	}
}


