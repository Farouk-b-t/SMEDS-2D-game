#include"menu.h"
void main(){
     //animation:  
     int running = 1;
     int current_image = 0;
     int num_images = 9;
     Image images[9];
	int boucle=1,bck=0,drag1=0,drag2=0,drag3=0;
	int wind=1,ctrl=0,entre_p=0,entre_s=0,entre_e=0;
	int music_bar=2,sfx_bar=2;
	int sfxv=2;
	SDL_Surface *screen;
	SDL_Event event;
	Mix_Chunk *drg;
	Mix_Chunk *clk;
	image bg,b1,nb1,b2,nb2,b3,nb3,m00,m25,m50,m75,m100,mp1,mp2,mm1,mm2,sfx00,sfx25,sfx50,sfx75,sfx100,sfxp1,sfxp2,sfxm1,sfxm2,frame,wd1,wd2,fs1,fs2,key1,key2,ctrl1,ctrl2,bk1,bk2;
	Mix_Music *music;
	texte settings,volume,screenmode,controls;
	TTF_Init();
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1){
		printf("Coundn't initialise\n");
	}
	else{
		screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
		initialiser_text(&settings,"font/Gamejot.ttf",75,255,255,255,835,71);
		initialiser_text(&volume,"font/Corbel Bold.ttf",50,83,67,142,870,201);
		initialiser_text(&screenmode,"font/Corbel Bold.ttf",50,83,67,142,815,486);
		initialiser_text(&controls,"font/Corbel Bold.ttf",50,83,67,142,860,653);
		intro(music);
		initilize_img(&bg,"gfx/background/bg.png",0,0);
		//main menu:
		initilize_img(&b1,"gfx/buttons/play/PLAY_1.png",820,350);
		initilize_img(&b2,"gfx/buttons/settings/SETTINGS_1.png",700,500);
		initilize_img(&b3,"gfx/buttons/exit/EXIT_1.png",840,650);
		initilize_img(&nb1,"gfx/buttons/play/PLAY_2.png",820,350);
		initilize_img(&nb2,"gfx/buttons/settings/SETTINGS_2.png",700,500);
		initilize_img(&nb3,"gfx/buttons/exit/EXIT_2.png",840,650);
		//settings menu:
		initilize_img(&m00,"gfx/settings/volume/music_level/music00.png",789,271);
		initilize_img(&m25,"gfx/settings/volume/music_level/music25.png",789,271);
		initilize_img(&m50,"gfx/settings/volume/music_level/music50.png",789,271);
		initilize_img(&m75,"gfx/settings/volume/music_level/music75.png",789,271);
		initilize_img(&m100,"gfx/settings/volume/music_level/music100.png",789,271);
		
		initilize_img(&mp1,"gfx/settings/volume/btn_music/pls/bouton_plus.png",1153,271);
		initilize_img(&mp2,"gfx/settings/volume/btn_music/pls/bouton_plus_down.png",1153,271);
		initilize_img(&mm1,"gfx/settings/volume/btn_music/mns/bouton_moins.png",710,272);
		initilize_img(&mm2,"gfx/settings/volume/btn_music/mns/bouton_moins_down.png",710,272);
		
		initilize_img(&sfx00,"gfx/settings/volume/sfx_level/sfx00.png",788,378);
		initilize_img(&sfx25,"gfx/settings/volume/sfx_level/sfx25.png",788,378);
		initilize_img(&sfx50,"gfx/settings/volume/sfx_level/sfx50.png",788,378);
		initilize_img(&sfx75,"gfx/settings/volume/sfx_level/sfx75.png",788,378);
		initilize_img(&sfx100,"gfx/settings/volume/sfx_level/sfx100.png",788,378);
		
		initilize_img(&sfxp1,"gfx/settings/volume/btn_sfx/pls/bouton_plus.png",1153,379);
		initilize_img(&sfxp2,"gfx/settings/volume/btn_sfx/pls/bouton_plus_down.png",1153,379);
		initilize_img(&sfxm1,"gfx/settings/volume/btn_sfx/mns/bouton_moins.png",709,379);
		initilize_img(&sfxm2,"gfx/settings/volume/btn_sfx/mns/bouton_moins_down.png",709,379);
		initilize_img(&frame,"gfx/settings/frame/frame.png",628,141);
		initilize_img(&wd1,"gfx/settings/screenmodes/wd/windowed.png",707,556);
		initilize_img(&fs1,"gfx/settings/screenmodes/fs/fullscreen.png",989,556);
		initilize_img(&key1,"gfx/settings/controls/keyboard/keyboard.png",989,723);
		initilize_img(&ctrl1,"gfx/settings/controls/controller/controller.png",707,723);
		initilize_img(&wd2,"gfx/settings/screenmodes/wd/windowed_active.png",707,556);
		initilize_img(&fs2,"gfx/settings/screenmodes/fs/fullscreen_active.png",989,556);
		initilize_img(&key2,"gfx/settings/controls/keyboard/keyboard_active.png",989,723);
		initilize_img(&ctrl2,"gfx/settings/controls/controller/controller_active.png",707,723);
		initilize_img(&bk1,"gfx/settings/back/back1.png",923,830);
		initilize_img(&bk2,"gfx/settings/back/back2.png",923,830);
		load_images(images);
		while(boucle){
		//animation
			  // Affichage de l'image courante:
                     SDL_BlitSurface(images[current_image].surface, NULL, screen, NULL);
                    

                         // Passage à l'image suivante:
                     current_image++;
                     if (current_image >= num_images) {
                         current_image = 0;
                            }

                         // Attente de 50 ms:
                     SDL_Delay(50);
                 //fin animation
			if((event.motion.x<=1205 && event.motion.x>=735 && event.motion.y<=565 && event.motion.y>=500 && (event.button.button==SDL_BUTTON_LEFT))||(entre_s==1 && event.key.keysym.sym==SDLK_RETURN)){
				//frame:
				afficher_image(screen,frame);
				//settings(texte):
				afficher_text(screen,settings,"Settings");
				//volume(texte):
				afficher_text(screen,volume,"Volume");
				//screen mode(texte):
				afficher_text(screen,screenmode,"Screen Mode");
				//controls(texte)
				afficher_text(screen,controls,"Controls");
				bck=0;
				while(bck==0){
					//music:
					//+music:
					if(event.motion.x<=1257 && event.motion.x>=1153 && event.motion.y<=325 && event.motion.y>=271 && (event.button.button==SDL_BUTTON_LEFT)&& (event.type==SDL_MOUSEBUTTONDOWN)){
						afficher_image(screen,mp2);
						musiquebref_click(clk,sfxv);
						//liberer_musiquebref(clk);
						music_bar++;
						if(music_bar>4){
							music_bar=4;
						}
					}
					else{
						afficher_image(screen,mp1);
					}
					//_music:
					if(event.motion.x<=765 && event.motion.x>=710 && event.motion.y<=326 && event.motion.y>=272 && event.type==SDL_MOUSEBUTTONDOWN){
						musiquebref_click(clk,sfxv);
						//liberer_musiquebref(clk);
						afficher_image(screen,mm2);
						if(event.button.button==SDL_BUTTON_LEFT){
							music_bar--;
						}
						if(music_bar<0){
							music_bar=0;
						}
					}
					else{
						afficher_image(screen,mm1);
					}
					switch(music_bar){
						case 0:{
							afficher_image(screen,m00);
							break;
						}
						case 1:{
							afficher_image(screen,m25);
							break;
						}
						case 2:{
							afficher_image(screen,m50);
							break;
						}
						case 3:{
							afficher_image(screen,m75);
							break;
						}
						case 4:{
							afficher_image(screen,m100);
							break;
						}
					}
					Mix_VolumeMusic(music_bar*25);
					//+sfx:
					if(event.motion.x<=1205 && event.motion.x>=1153 && event.motion.y<=434 && event.motion.y>=379 && (event.button.button==SDL_BUTTON_LEFT)&& (event.type==SDL_MOUSEBUTTONDOWN)){
						afficher_image(screen,sfxp2);
						musiquebref_click(clk,sfxv);
						//liberer_musiquebref(clk);
						sfx_bar++;
						if(sfx_bar>4){
							sfx_bar=4;
						}
					}
					else{
						afficher_image(screen,sfxp1);
					}
					//_sfx:
					if(event.motion.x<=761 && event.motion.x>=709 && event.motion.y<=434 && event.motion.y>=379 && event.type==SDL_MOUSEBUTTONDOWN){
						musiquebref_click(clk,sfxv);
						//liberer_musiquebref(clk);
						afficher_image(screen,sfxm2);
							sfx_bar--;
						if(sfx_bar<0){
							sfx_bar=0;
						}
					}
					else{
						afficher_image(screen,sfxm1);
					}
					switch(sfx_bar){
						case 0:{
							afficher_image(screen,sfx00);
							break;
						}
						case 1:{
							afficher_image(screen,sfx25);
							break;
						}
						case 2:{
							afficher_image(screen,sfx50);
							break;
						}
						case 3:{
							afficher_image(screen,sfx75);
							break;
						}
						case 4:{
							afficher_image(screen,sfx100);
							break;
						}
					}
					sfxv=sfx_bar*25;
					
					//windowed:
					if(event.motion.x<=931 && event.motion.x>=707 && event.motion.y<=628 && event.motion.y>=556 && event.button.button==SDL_BUTTON_LEFT){
						wind=1;
	
						screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
						afficher_image(screen,bg);
						//frame:
						afficher_image(screen,frame);
						//settings(texte):
						afficher_text(screen,settings,"Settings");
						//volume(texte):
						afficher_text(screen,volume,"Volume");
						//screen mode(texte):
						afficher_text(screen,screenmode,"Screen Mode");
						//controls(texte)
						afficher_text(screen,controls,"Controls");
					}
					//full screen:
					if(event.motion.x<=1213 && event.motion.x>=989 && event.motion.y<=628 && event.motion.y>=556 && event.button.button==SDL_BUTTON_LEFT){
						wind=0;
						
						screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
						afficher_image(screen,bg);
						//frame:
						afficher_image(screen,frame);
						//settings(texte):
						afficher_text(screen,settings,"Settings");
						//volume(texte):
						afficher_text(screen,volume,"Volume");
						//screen mode(texte):
						afficher_text(screen,screenmode,"Screen Mode");
						//controls(texte)
						afficher_text(screen,controls,"Controls");
						}
					//keyboard:
					if(event.motion.x<=1213 && event.motion.x>=989 && event.motion.y<=795 && event.motion.y>=723 && event.button.button==SDL_BUTTON_LEFT){
						ctrl=0;
					}
					//controller:
					if(event.motion.x<=931 && event.motion.x>=707 && event.motion.y<=795 && event.motion.y>=723 && event.button.button==SDL_BUTTON_LEFT){
						ctrl=1;
					}
					if(wind==1){
						event.type=SDL_KEYDOWN;
						event.key.keysym.sym=SDLK_w;
						afficher_image(screen,fs1);
						afficher_image(screen,wd2);
						
					}
					else{
					        event.type=SDL_KEYDOWN;
						event.key.keysym.sym=SDLK_f;
						afficher_image(screen,fs2);
						afficher_image(screen,wd1);
						
					}
					if(ctrl==1){
						afficher_image(screen,ctrl2);
						afficher_image(screen,key1);
					}
					else{
						afficher_image(screen,ctrl1);
						afficher_image(screen,key2);
					}
					//SDL_Flip(screen);
					//back:
					if(event.motion.x<=997 && event.motion.x>=923 && event.motion.y<=904 && event.motion.y>=830 && event.button.button==SDL_BUTTON_LEFT){
						musiquebref_click(clk,sfxv);
						//liberer_musiquebref(clk);
						afficher_image(screen,bk2);
						SDL_Delay(100);
						bck=1;
					}
					else{
						afficher_image(screen,bk1);
					}
					SDL_PollEvent(&event);
					if(event.type==SDL_KEYDOWN){
						if(event.key.keysym.sym==SDLK_ESCAPE){
							bck=1;
						}
					}
					SDL_Flip(screen);
				}
			}
			else{
				Mix_VolumeMusic(music_bar*25);
				while(SDL_PollEvent(&event)){
					switch(event.type){
						case SDL_KEYDOWN:{
							switch(event.key.keysym.sym){
								case SDLK_f:{
									musiquebref_click(clk,sfxv);
									screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
									wind=0;
									break;
								}
								case SDLK_w:{
									musiquebref_click(clk,sfxv);
									screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
									wind=1;
									break;
								}
								case SDLK_UP:{
									if(entre_p==1 && entre_s==0 && entre_e==0){
										entre_p=0;
									}
									else{
										if(entre_p==0 && entre_s==1 && entre_e==0){
											entre_p=1;
											entre_s=0;
										}
										else{
											if(entre_p==0 && entre_s==0 && entre_e==1){
												entre_s=1;
												entre_e=0;
											}
										}
									}
									break;
								}
								case SDLK_DOWN:{
									if(entre_p==0 && entre_s==0 && entre_e==0){
										entre_p=1;
									}
									else{
										if(entre_p==1 && entre_s==0 && entre_e==0){
											entre_p=0;
											entre_s=1;
										}
										else{
											if(entre_p==0 && entre_s==1 && entre_e==0){
												entre_e=1;
												entre_s=0;
											}
											else{
												if(entre_p==0 && entre_s==0 && entre_e==1){
													entre_e=0;
												}
											}
										}
									}
									break;
								}
							}
						}
						break;
					}
				}
				if((event.motion.x<=1055 && event.motion.x>=820 && event.motion.y<=410 && event.motion.y>=350)||(entre_p==1)){
					afficher_image(screen,nb1);
					if(drag1==0){
						musiquebref_drag(drg,sfxv);
						//liberer_musiquebref(drg);
					}
					if(event.button.button==SDL_BUTTON_LEFT){
						musiquebref_click(clk,sfxv);
					}
					drag1=1;
				}
				else{
					drag1=0;
					afficher_image(screen,b1);
				}
				if((event.motion.x<=1205 && event.motion.x>=735 && event.motion.y<=565 && event.motion.y>=500)||(entre_s==1)){
					afficher_image(screen,nb2);
					if(drag2==0){
						musiquebref_drag(drg,sfxv);
						//liberer_musiquebref(drg);
					}
					if(event.button.button==SDL_BUTTON_LEFT){
						musiquebref_click(clk,sfxv);
					}
					drag2=1;
				}
				else{
					drag2=0;
					afficher_image(screen,b2);
				}
				if((event.motion.x<=1063 && event.motion.x>=870 && event.motion.y<=710 && event.motion.y>=650)||(entre_e==1)){
					afficher_image(screen,nb3);
					if(drag3==0){
						musiquebref_drag(drg,sfxv);
						//liberer_musiquebref(drg);
					}
					if(event.button.button==SDL_BUTTON_LEFT || ((entre_e==1) && event.button.button==SDLK_SPACE)){
						musiquebref_click(clk,sfxv);
					}
					drag3=1;
					if(event.button.button==SDL_BUTTON_LEFT){
						SDL_Delay(1000); // wait before launching next command
						boucle=0;
					}
				}
				else{
					drag3=0;
					afficher_image(screen,b3);
				}
			}
			SDL_Flip(screen); //refresh screen
			while(SDL_PollEvent(&event)){
				switch(event.type){
					case SDL_QUIT:{
						boucle=0;
						break;
					}
				}
			}
		}
		TTF_Quit();
		//free_text(settings);
		//free_text(volume);
		//free_text(screenmode);
		//free_text(controls);
		free_image(nb1);
		free_image(nb2);
		free_image(nb3);
		free_image(bg);
		free_image(b1);
		free_image(b2);
		free_image(b3);
		free_image(m00);
		free_image(m25);
		free_image(m50);
		free_image(m75);
		free_image(m100);
		free_image(mp1);
		free_image(mp2);
		free_image(mm1);
		free_image(mm2);
		free_image(sfx00);
		free_image(sfx25);
		free_image(sfx50);
		free_image(sfx75);
		free_image(sfx100);
		free_image(sfxp1);
		free_image(sfxp2);
		free_image(sfxm1);
		free_image(sfxm2);
		free_image(frame);
		free_image(wd1);
		free_image(fs1);
		free_image(key1);
		free_image(ctrl1);
		free_image(wd2);
		free_image(fs2);
		free_image(key2);
		free_image(ctrl2); 
		free_image(bk1);
		free_image(bk2);
		//liberer_music(music);
		// Libération de la mémoire animation:
                free_images(images);
	}
}


