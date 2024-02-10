
#include "headerTB.h"
int main()
{
    tic t;
    int coup=1;
    SDL_Surface* screen;
    TTF_Init();
    SDL_Event event;
    int continuer=1;
    int a,b;
    
    
    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    initialisation(&t);
    while(continuer)
    {    
	affichage(t,screen); 
	SDL_Flip(screen);
	if( t.tour<9 &&atilganer(t.tabsuivi)==0)
	{
		if((t.tour)%2==0)
            	{
 			calcul_coup(t.tabsuivi);
 			t.tour++;
		}
          else
          {
        	SDL_WaitEvent(&event);
        	switch(event.type)
        	{
       			case SDL_QUIT:
            			continuer=0;
            		break;
        		case SDL_MOUSEBUTTONUP:
		        	if (event.button.button == SDL_BUTTON_LEFT)
                		{
				    a=event.button.x/180;
				    b=event.button.y/180;
				    coup=3*b+a;
				    t.tour++;
   				    t.tabsuivi[coup]=-1;
                                }
            		break;
                }
          }
         }
         else
         { 
 		Resultat(t,screen);
 		continuer=0;   
	 }
      }
    SDL_Quit();
    TTF_Quit();
    liberationmemoire(t);
return 0;
}


