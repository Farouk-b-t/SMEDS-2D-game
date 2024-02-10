#include "header.h"



void save_game(char nomFich[], int x, int y, int bx, int by, int ex, int ey, int score)
{
	FILE * f;
	f=fopen(nomFich, "w");
	if (f == NULL)
	{ printf("FAILED TO OPEN THE FILE. \n"); }
	else{
	fprintf(f," %d %d %d %d %d %d %d",x,y,bx,by,ex,ey,score);
	}
	fclose(f);
	
}

void load_game(char nomFich[], int* x, int* y, Sint16* bx, Sint16* by, Sint16* ex, Sint16* ey, int* score)
{
	FILE * f;
	f=fopen(nomFich, "r");
	if (f == NULL)
	{ printf("FAILED TO OPEN THE FILE. \n"); }
	else{
	fscanf(f," %d %d %hd %hd %hd %hd %d",x,y,bx,by,ex,ey,score);
	}
	fclose(f);
	
}
