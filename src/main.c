#include"header.h"
void main(){
	int end=0;
	int up=0,down=0,r=0,l=0,ri=0;
	int up2=0,down2=0,r2=0,l2=0,ri2=0,entre_r=0,entre_q=0,entre_l=0;
	int x=140,y=650;
	int x2=300,y2=500;
	int leadb=1;
	int attack=0;
	int speed=0;
	int sous_menu=1;
	int moving=0;
	int on=1;
	int perso2=0;
	int att=30;
	int miniup=0;
	int tmps=0;
	int jmp=0;
	int level2=0,level3=0;
	int en1=0,en2=0,en3=0;
	int level1=0;
	SDL_Event event;
	SDL_Surface * screen;
	background b;
	image lb,bg2,hp[11],minie,minib,ssbg;
	character h,h2,e,e2,boss;
	char string[20];
	texte t,d,resume0,resume1,leaderboard0,leaderboard1,quit0,quit1;
	vie v;
	object o;
	int death=9;
	//////////variable lot4
	int redimensionnement=10;
	minimap m;
    	int total_time = 30000;
    	int temps_restant; 
    	int temps_debut = 0;
    	int temps_ecoule = 0;
    	int temps_affichage = 0;
    	int temps_actuel = 0;
     	int current_image_enigme = 0;
     	int num_images_enigme = 13;
     	img_animation images_enigme[13];
     	img_animation mini_images_enigme[13];
     	//////////////////////
     	int running = 1;
        int current_image = 0;
        int num_images = 9;
        menu_animation images[9];
	int boucle=1,bck=0,drag1=0,drag2=0,drag3=0;
	int wind=1,ctrl=0,entre_p=0,entre_s=0,entre_e=0;
	int music_bar=2,sfx_bar=2;
	int sfxv=2;

	Mix_Chunk *drg;
	Mix_Chunk *clk;
	image bg,b1,nb1,b2,nb2,b3,nb3,m00,m25,m50,m75,m100,mp1,mp2,mm1,mm2,sfx00,sfx25,sfx50,sfx75,sfx100,sfxp1,sfxp2,sfxm1,sfxm2,frame,wd1,wd2,fs1,fs2,key1,key2,ctrl1,ctrl2,bk1,bk2;
	Mix_Music *music;
	texte settings,volume,screenmode,controls;
	strcpy(h.SI.playername,"player1");
	TTF_Init();
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1){
		printf("Coundn't initialise\n");
	}
	else{
		screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
		initBack(&b,"v1.0/gfx/map/2.png");
		initilize_img(&bg2,"v1.0/gfx/lb/bg2.jpg",0,0);
		initilize_img(&minie,"v1.0/gfx/minimap/mini_enemy.png",600,120);
		initilize_img(&minib,"v1.0/gfx/minimap/mini_boss.png",1550,120);
		for(int i=0;i<11;i++){
			sprintf(string,"v1.0/hp/%d.png",i+1);
			hp[i].url=IMG_Load(string);
			hp[i].pos.x=361;
			hp[i].pos.y=960;
		}
		initilize_img(&lb,"v1.0/gfx/lb/lb.png",SCREEN_W/2-400,SCREEN_H/2-400);
		init_vie(&v,10,80);
		init_character(&h,x,y);
		init_character(&h2,x2,y2);
		initEnnemi(&e,1500,350);
		initEnnemi(&e2,1500,350);
		init_grimgor(&boss,1500,350);
		initialiserMinimap(&m);
		initialiser_text(&resume0,"PIXELADE.TTF",100,255,255,255,65,447);
		initialiser_text(&resume1,"PIXELADE.TTF",100,255,136,0,65,447);
		initialiser_text(&leaderboard0,"PIXELADE.TTF",100,255,255,255,65,547);
		initialiser_text(&leaderboard1,"PIXELADE.TTF",100,255,136,0,65,547);
		initialiser_text(&quit0,"PIXELADE.TTF",100,255,255,255,65,647);
		initialiser_text(&quit1,"PIXELADE.TTF",100,255,136,0,65,647);
		//POSITION DU HERO
		SDL_Rect PositionAhmed ;
		PositionAhmed.x=140;
		PositionAhmed.y=1200;
		init_object(&o,b.pos.x+5000,0);
		init_object(&o,b.pos.x+6500,0);
		init_object(&o,b.pos.x+8000,0);
		init_object(&o,b.pos.x+9700,0);
		initialiser_text(&t,"v1.0/font/Colleged.ttf",50,255,255,255,15,15);
		initialiser_text(&d,"v1.0/font/Colleged.ttf",50,255,255,255,750,15);
		animer_Enigme_point(images_enigme);
		animer_mini_Enigme_point(mini_images_enigme);
		sprintf(string,"score:%d",h.SI.score);
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
		initilize_img(&ssbg,"sous menu.png",0,0);
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
						boucle=0;
						end=1;
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
		while((end)){// && h.vie>0
			SDL_PollEvent(&event);
			//mini_jump(&PositionAhmed,&miniup);
                        y=h.pos.y;
                        jump(&h2);
                        y2=h2.pos.y;
			afficherBack(b,screen,b.pos.x,b.pos.y);
			afficher_text(screen,d,"Stage1");
			afficher_text(screen,t,string);
			afficher_vies(screen,&v,15,80,h.vie);
			afficher(m,screen);
			afficher_image(screen,minie);
			afficher_image(screen,minib);
			///////////////////////////////////////animation enigme lot4
			SDL_Rect PositionEnigme;
			PositionEnigme.x=1575;
			PositionEnigme.y=75;
                        SDL_BlitSurface(mini_images_enigme[current_image_enigme].surface, NULL, screen, &PositionEnigme);
                        current_image_enigme++;
                        if (current_image_enigme >= num_images_enigme) {
                        current_image_enigme = 0;
                                                         }
                        SDL_Delay(5);
                        SDL_Rect PosAnimation;
			PosAnimation.x=1700;
			PosAnimation.y=209;  
                        SDL_BlitSurface(images_enigme[current_image_enigme].surface, NULL, screen, &PosAnimation);
                        current_image_enigme++;
                        if (current_image_enigme >= num_images_enigme) {
                        current_image_enigme = 0;
                                                         }
                        SDL_Delay(10);
                        
                         temps_debut = SDL_GetTicks();  
                         afficher_temps(screen,temps_debut);
                        /////////////////////////////////////////
                        //animation_bg(&o);
			afficher_lampe(&o,screen,b.pos.x+5000,0);
			afficher_lampe(&o,screen,b.pos.x+6500,0);
			afficher_lampe(&o,screen,b.pos.x+8000,0);
			afficher_lampe(&o,screen,b.pos.x+9700,0);
			if(h.up==0 && r==0 && l==0 && att>28){
				if(h.direction==0){
					h.actuelimage.url=IMG_Load("v1.0/gfx/right/HERO/IDLE/1.png");
				}
				else{
					h.actuelimage.url=IMG_Load("v1.0/gfx/left/HERO/IDLE/1.png");
				}
			}
			printf("------------------boss health: %d\n",boss.health);
			if(att<=28){
				att++;
				hero_attack(&h);
				h.pos.y-=250;
				afficher_character(screen,&h,h.pos.x,h.pos.y);
				if(collisionBB(h,e)==1){
					e.health=0;
					death=0;
				}
				if(collisionBB(h,e2)==1){
					e2.health=0;
				}
				if(collisionBB(h,boss)==1){
					boss.health-=10;
				}
				h.pos.y+=250;
				SDL_Delay(10);
			}
			if(b.pos.x<=-240){
				en1=1;
			}
			if(b.pos.x<=-240){
				en2=1;
			}
			if(b.pos.x<=-7000){
				en3=1;
			}
			if(en1==1 && e.health!=0){
				printf("************en1\n");
				printf("----------xe: %d\n",e.pos.x);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				moveIA(&e,&h,screen,&attack,moving,&on);
			}
			if(death<=8){
				NPC_death(&e);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				death++;
				SDL_Delay(5);
			}
			if(e2.health==0){
				NPC_death(&e);
			}
			if(boss.health==0){
				boss_death(&boss);
			}
			if(en2==1 && e2.health!=0){
				printf("************en2\n");
				printf("-----------xe2: %d\n",e2.pos.x);
				afficherEnnemi(&e2,screen,e2.pos.x,e2.pos.y);
				moveIA(&e2,&h,screen,&attack,moving,&on);
			}
			if(en3==1 && boss.health!=0){
				printf("************en3\n");
				printf("-----------xboss: %d\n",boss.pos.x);
				afficherEnnemi(&boss,screen,boss.pos.x,boss.pos.y);
				moveIA_boss(&boss,&h,screen,&attack,moving,&on);
				if(boss.health<0){
					boss.health=0;
				}
				afficher_image(screen,hp[boss.health/10]);
			}
			if(r==0 && l==0 && up==0 && down==0 && h.up==0 && att>28){
				hero_stand_by(&h);
				afficher_character(screen,&h,h.pos.x,h.pos.y);
				tmps++;
			}
			else{
				tmps=0;
			}
			jump(&h);
			if(h.up==1){
				SDL_Delay(5);
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
			}
			scrolling_caractere(b,&h,up,down,r,l,&moving);
			if(r==1){
				scrolling (&b,up,down,r,l,20,5);
				h.direction=0;
				hero_run(&h);
				h.pos.y-=50;
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
				h.pos.y+=50;
				h.SI.score++;
				printf("pos hero = %d",h.pos.x);
				if (h.pos.x>1000)
				{
				PositionAhmed.x+=20;
				}
				else if( h.pos.x<1000 )
				{
				PositionAhmed.x+=40;
				}
				else if( h.pos.x>1220 )
				{
				PositionAhmed.x+=3;
				}
				sprintf(string,"score:%d",h.SI.score);
			}
			if(l==1){
				scrolling (&b,up,down,r,l,20,10);
				h.direction=1;
				hero_run(&h);
				h.pos.y-=50;
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
				h.pos.y+=50;
				h.SI.score++;
				if((h.pos.x)>=200){
					(PositionAhmed.x)-=40;
				}
				else{
				if( h.pos.x<200){
					PositionAhmed.x-=20;
				
				}
				}
				sprintf(string,"score:%d",h.SI.score);
			}
			if(up==1){
				scrolling (&b,up,down,r,l,20,10);
				h.SI.score++;
				PositionAhmed.y-=5;
				sprintf(string,"score:%d",h.SI.score);
			}
			if(down==1){
				scrolling (&b,up,down,r,l,20,10);
				h.SI.score++;
				PositionAhmed.y+=5;
				sprintf(string,"score:%d",h.SI.score);
			}
			if(r2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				h2.direction=0;
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(l2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				h2.direction=1;
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(up2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(down2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(perso2==1){
				afficher_character(screen,&h2,x2,y2);
			}
			while(leadb==0){
				SDL_PollEvent(&event);
				afficher_image(screen,bg2);
				afficher_image(screen,lb);
				SDL_Flip(screen);
				if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE){
					leadb=1;
				}
			}
			while (sous_menu==0){
				while(SDL_PollEvent(&event)){
				afficherBack(b,screen,b.pos.x,b.pos.y);
				afficher_character(screen,&h,x,y);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				afficher_image(screen,ssbg);
				buttons_fleche(&event,&entre_r,&entre_l,&entre_q,&end);
				}
				if( entre_r ==1 && event.key.keysym.sym==SDLK_RETURN){ sous_menu=1;}
				if( entre_l ==1 && event.key.keysym.sym==SDLK_RETURN){ leadb=0;
				entre_l=0;
				sous_menu=1;
				}
				if( entre_q ==1 && event.key.keysym.sym==SDLK_RETURN){sous_menu=1; end=0; save_game("saved_game.txt",x,y,b.pos.x,b.pos.y,e.pos.x,e.pos.y,h.SI.score);}
				if(event.motion.x<306 && event.motion.x>65 && event.motion.y<522 && event.motion.y>447 || (entre_r==1)){afficher_text(screen,resume1,"Resume");}
				else { afficher_text(screen,resume0,"Resume");
				 }
				if(entre_l==1){ afficher_text(screen,leaderboard1,"Leaderboard");
				}
				else { afficher_text(screen,leaderboard0,"Leaderboard"); }
				if( entre_q==1){afficher_text(screen,quit1,"Save & Quit the game");}
				else { afficher_text(screen,quit0,"Save & Quit the game"); }
				if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE) {sous_menu=1;}
				SDL_Flip(screen);
			}
			SDL_Flip(screen);
			while(SDL_PollEvent(&event)){
				switch(event.type){
					case SDL_KEYDOWN:{
						switch(event.key.keysym.sym){
							case SDLK_RIGHT:{
								r=1;
								break;
							}
							case SDLK_LEFT:{
								l=1;
								break;
							}
							case SDLK_UP:{
								up=1;
								break;
							}
							case SDLK_DOWN:{
								down=1;
								break;
							}
							case SDLK_d:{
								r2=1;
								break;
							}
							case SDLK_q:{
								l2=1;
								break;
							}
							case SDLK_z:{
								up2=1;
								break;
							}
							case SDLK_s:{
								down2=1;
								break;
							}
							case SDLK_o:{
								perso2=1;
								break;
							}
							case SDLK_p:{
								//perso2=0;
								sous_menu=0;
								break;
							}
							case SDLK_TAB:{
								leadb=0;
								break;
							}
							case SDLK_ESCAPE:{
								end=0;
								break;
							}
							case SDLK_k:{
								att=0;
								break;
							}
							case SDLK_SPACE:{
								jmp=0;
								if(h.up==0){
									h.up=1;
								}
								if(miniup==0){
									miniup=1;
								}
								break;
							}
							case SDLK_a:{
								if(h2.up==0){
									h2.up=1;
								}
								break;
							}
						}
						break;
					}
					case SDL_KEYUP:{
						h.SI.score+=10;
						switch(event.key.keysym.sym){
							case SDLK_RIGHT:{
								r=0;
								ri=1;
								break;
							}
							case SDLK_LEFT:{
								ri=0;
								l=0;
								break;
							}
							case SDLK_UP:{
								up=0;
								break;
							}
							case SDLK_DOWN:{
								down=0;
								break;
							}
							case SDLK_d:{
								r2=0;
								break;
							}
							case SDLK_q:{
								l2=0;
								break;
							}
							case SDLK_z:{
								up2=0;
								break;
							}
							case SDLK_s:{
								down2=0;
								break;
							}
						}
						break;
					}
					case SDL_QUIT:{
						end=0;
						break;
					}
				}
				SDL_Flip(screen);
			}
			MAJMinimap(PositionAhmed,&m,redimensionnement);//redimentionnement de la position mini hero
		}
		while(level2==1){// && h.vie>0
			SDL_PollEvent(&event);
			//mini_jump(&PositionAhmed,&miniup);
                        y=h.pos.y;
                        jump(&h2);
                        y2=h2.pos.y;
			afficherBack(b,screen,b.pos.x,b.pos.y);
			afficher_text(screen,d,"Stage1");
			afficher_text(screen,t,string);
			afficher_vies(screen,&v,15,80,h.vie);
			afficher(m,screen);
			afficher_image(screen,minie);
			afficher_image(screen,minib);
			///////////////////////////////////////animation enigme lot4
			SDL_Rect PositionEnigme;
			PositionEnigme.x=1575;
			PositionEnigme.y=75;
                        SDL_BlitSurface(mini_images_enigme[current_image_enigme].surface, NULL, screen, &PositionEnigme);
                        current_image_enigme++;
                        if (current_image_enigme >= num_images_enigme) {
                        current_image_enigme = 0;
                                                         }
                        SDL_Delay(5);
                        SDL_Rect PosAnimation;
			PosAnimation.x=1700;
			PosAnimation.y=209;  
                        SDL_BlitSurface(images_enigme[current_image_enigme].surface, NULL, screen, &PosAnimation);
                        current_image_enigme++;
                        if (current_image_enigme >= num_images_enigme) {
                        current_image_enigme = 0;
                                                         }
                        SDL_Delay(10);
                        
                         temps_debut = SDL_GetTicks();  
                         afficher_temps(screen,temps_debut);
                        /////////////////////////////////////////
                        //animation_bg(&o);
			afficher_lampe(&o,screen,b.pos.x+5000,0);
			afficher_lampe(&o,screen,b.pos.x+6500,0);
			afficher_lampe(&o,screen,b.pos.x+8000,0);
			afficher_lampe(&o,screen,b.pos.x+9700,0);
			if(h.up==0 && r==0 && l==0 && att>28){
				if(h.direction==0){
					h.actuelimage.url=IMG_Load("v1.0/gfx/right/HERO/IDLE/1.png");
				}
				else{
					h.actuelimage.url=IMG_Load("v1.0/gfx/left/HERO/IDLE/1.png");
				}
			}
			printf("------------------boss health: %d\n",boss.health);
			if(att<=28){
				att++;
				hero_attack(&h);
				h.pos.y-=250;
				afficher_character(screen,&h,h.pos.x,h.pos.y);
				if(collisionBB(h,e)==1){
					e.health=0;
					death=0;
				}
				if(collisionBB(h,e2)==1){
					e2.health=0;
				}
				if(collisionBB(h,boss)==1){
					boss.health-=10;
				}
				h.pos.y+=250;
				SDL_Delay(10);
			}
			if(b.pos.x<=-240){
				en1=1;
			}
			if(b.pos.x<=-240){
				en2=1;
			}
			if(b.pos.x<=-10000){
				en3=1;
			}
			if(en1==1 && e.health!=0){
				printf("************en1\n");
				printf("----------xe: %d\n",e.pos.x);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				moveIA(&e,&h,screen,&attack,moving,&on);
			}
			if(death<=8){
				NPC_death(&e);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				death++;
				SDL_Delay(5);
			}
			if(e2.health==0){
				NPC_death(&e);
			}
			if(boss.health==0){
				boss_death(&boss);
			}
			if(en2==1 && e2.health!=0){
				printf("************en2\n");
				printf("-----------xe2: %d\n",e2.pos.x);
				afficherEnnemi(&e2,screen,e2.pos.x,e2.pos.y);
				moveIA(&e2,&h,screen,&attack,moving,&on);
			}
			if(en3==1 && boss.health!=0){
				printf("************en3\n");
				printf("-----------xboss: %d\n",boss.pos.x);
				afficherEnnemi(&boss,screen,boss.pos.x,boss.pos.y);
				moveIA_boss(&boss,&h,screen,&attack,moving,&on);
				if(boss.health<0){
					boss.health=0;
				}
				afficher_image(screen,hp[boss.health/10]);
			}
			if(r==0 && l==0 && up==0 && down==0 && h.up==0 && att>28){
				hero_stand_by(&h);
				afficher_character(screen,&h,h.pos.x,h.pos.y);
				tmps++;
			}
			else{
				tmps=0;
			}
			jump(&h);
			if(h.up==1){
				SDL_Delay(5);
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
			}
			scrolling_caractere(b,&h,up,down,r,l,&moving);
			if(r==1){
				scrolling (&b,up,down,r,l,20,5);
				h.direction=0;
				hero_run(&h);
				h.pos.y-=50;
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
				h.pos.y+=50;
				h.SI.score++;
				printf("pos hero = %d",h.pos.x);
				if (h.pos.x>1000)
				{
				PositionAhmed.x+=20;
				}
				else if( h.pos.x<1000 )
				{
				PositionAhmed.x+=40;
				}
				else if( h.pos.x>1220 )
				{
				PositionAhmed.x+=3;
				}
				sprintf(string,"score:%d",h.SI.score);
			}
			if(l==1){
				scrolling (&b,up,down,r,l,20,10);
				h.direction=1;
				hero_run(&h);
				h.pos.y-=50;
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
				h.pos.y+=50;
				h.SI.score++;
				if((h.pos.x)>=200){
					(PositionAhmed.x)-=40;
				}
				else{
				if( h.pos.x<200){
					PositionAhmed.x-=20;
				
				}
				}
				sprintf(string,"score:%d",h.SI.score);
			}
			if(up==1){
				scrolling (&b,up,down,r,l,20,10);
				h.SI.score++;
				PositionAhmed.y-=5;
				sprintf(string,"score:%d",h.SI.score);
			}
			if(down==1){
				scrolling (&b,up,down,r,l,20,10);
				h.SI.score++;
				PositionAhmed.y+=5;
				sprintf(string,"score:%d",h.SI.score);
			}
			if(r2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				h2.direction=0;
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(l2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				h2.direction=1;
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(up2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(down2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(perso2==1){
				afficher_character(screen,&h2,x2,y2);
			}
			while(leadb==0){
				SDL_PollEvent(&event);
				afficher_image(screen,bg2);
				afficher_image(screen,lb);
				SDL_Flip(screen);
				if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE){
					leadb=1;
				}
			}
			while (sous_menu==0){
				while(SDL_PollEvent(&event)){
				afficherBack(b,screen,b.pos.x,b.pos.y);
				afficher_character(screen,&h,x,y);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				afficher_image(screen,ssbg);
				buttons_fleche(&event,&entre_r,&entre_l,&entre_q,&end);
				}
				if( entre_r ==1 && event.key.keysym.sym==SDLK_RETURN){ sous_menu=1;}
				if( entre_l ==1 && event.key.keysym.sym==SDLK_RETURN){ leadb=0;
				entre_l=0;
				sous_menu=1;
				}
				if( entre_q ==1 && event.key.keysym.sym==SDLK_RETURN){sous_menu=1; end=0; save_game("saved_game.txt",x,y,b.pos.x,b.pos.y,e.pos.x,e.pos.y,h.SI.score);}
				if(event.motion.x<306 && event.motion.x>65 && event.motion.y<522 && event.motion.y>447 || (entre_r==1)){afficher_text(screen,resume1,"Resume");}
				else { afficher_text(screen,resume0,"Resume");
				 }
				if(entre_l==1){ afficher_text(screen,leaderboard1,"Leaderboard");
				}
				else { afficher_text(screen,leaderboard0,"Leaderboard"); }
				if( entre_q==1){afficher_text(screen,quit1,"Save & Quit the game");}
				else { afficher_text(screen,quit0,"Save & Quit the game"); }
				if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE) {sous_menu=1;}
				SDL_Flip(screen);
			}
			SDL_Flip(screen);
			while(SDL_PollEvent(&event)){
				switch(event.type){
					case SDL_KEYDOWN:{
						switch(event.key.keysym.sym){
							case SDLK_RIGHT:{
								r=1;
								break;
							}
							case SDLK_LEFT:{
								l=1;
								break;
							}
							case SDLK_UP:{
								up=1;
								break;
							}
							case SDLK_DOWN:{
								down=1;
								break;
							}
							case SDLK_d:{
								r2=1;
								break;
							}
							case SDLK_q:{
								l2=1;
								break;
							}
							case SDLK_z:{
								up2=1;
								break;
							}
							case SDLK_s:{
								down2=1;
								break;
							}
							case SDLK_o:{
								perso2=1;
								break;
							}
							case SDLK_p:{
								//perso2=0;
								sous_menu=0;
								break;
							}
							case SDLK_TAB:{
								leadb=0;
								break;
							}
							case SDLK_ESCAPE:{
								end=0;
								break;
							}
							case SDLK_k:{
								att=0;
								break;
							}
							case SDLK_SPACE:{
								jmp=0;
								if(h.up==0){
									h.up=1;
								}
								if(miniup==0){
									miniup=1;
								}
								break;
							}
							case SDLK_a:{
								if(h2.up==0){
									h2.up=1;
								}
								break;
							}
						}
						break;
					}
					case SDL_KEYUP:{
						h.SI.score+=10;
						switch(event.key.keysym.sym){
							case SDLK_RIGHT:{
								r=0;
								ri=1;
								break;
							}
							case SDLK_LEFT:{
								ri=0;
								l=0;
								break;
							}
							case SDLK_UP:{
								up=0;
								break;
							}
							case SDLK_DOWN:{
								down=0;
								break;
							}
							case SDLK_d:{
								r2=0;
								break;
							}
							case SDLK_q:{
								l2=0;
								break;
							}
							case SDLK_z:{
								up2=0;
								break;
							}
							case SDLK_s:{
								down2=0;
								break;
							}
						}
						break;
					}
					case SDL_QUIT:{
						end=0;
						break;
					}
				}
				SDL_Flip(screen);
			}
			MAJMinimap(PositionAhmed,&m,redimensionnement);//redimentionnement de la position mini hero
		}
		while(level3==1){// && h.vie>0
			SDL_PollEvent(&event);
			//mini_jump(&PositionAhmed,&miniup);
                        y=h.pos.y;
                        jump(&h2);
                        y2=h2.pos.y;
			afficherBack(b,screen,b.pos.x,b.pos.y);
			afficher_text(screen,d,"Stage1");
			afficher_text(screen,t,string);
			afficher_vies(screen,&v,15,80,h.vie);
			afficher(m,screen);
			afficher_image(screen,minie);
			afficher_image(screen,minib);
			///////////////////////////////////////animation enigme lot4
			SDL_Rect PositionEnigme;
			PositionEnigme.x=1575;
			PositionEnigme.y=75;
                        SDL_BlitSurface(mini_images_enigme[current_image_enigme].surface, NULL, screen, &PositionEnigme);
                        current_image_enigme++;
                        if (current_image_enigme >= num_images_enigme) {
                        current_image_enigme = 0;
                                                         }
                        SDL_Delay(5);
                        SDL_Rect PosAnimation;
			PosAnimation.x=1700;
			PosAnimation.y=209;  
                        SDL_BlitSurface(images_enigme[current_image_enigme].surface, NULL, screen, &PosAnimation);
                        current_image_enigme++;
                        if (current_image_enigme >= num_images_enigme) {
                        current_image_enigme = 0;
                                                         }
                        SDL_Delay(10);
                        
                         temps_debut = SDL_GetTicks();  
                         afficher_temps(screen,temps_debut);
                        /////////////////////////////////////////
                        //animation_bg(&o);
			afficher_lampe(&o,screen,b.pos.x+5000,0);
			afficher_lampe(&o,screen,b.pos.x+6500,0);
			afficher_lampe(&o,screen,b.pos.x+8000,0);
			afficher_lampe(&o,screen,b.pos.x+9700,0);
			if(h.up==0 && r==0 && l==0 && att>28){
				if(h.direction==0){
					h.actuelimage.url=IMG_Load("v1.0/gfx/right/HERO/IDLE/1.png");
				}
				else{
					h.actuelimage.url=IMG_Load("v1.0/gfx/left/HERO/IDLE/1.png");
				}
			}
			printf("------------------boss health: %d\n",boss.health);
			if(att<=28){
				att++;
				hero_attack(&h);
				h.pos.y-=250;
				afficher_character(screen,&h,h.pos.x,h.pos.y);
				if(collisionBB(h,e)==1){
					e.health=0;
					death=0;
				}
				if(collisionBB(h,e2)==1){
					e2.health=0;
				}
				if(collisionBB(h,boss)==1){
					boss.health-=10;
				}
				h.pos.y+=250;
				SDL_Delay(10);
			}
			if(b.pos.x<=-240){
				en1=1;
			}
			if(b.pos.x<=-240){
				en2=1;
			}
			if(b.pos.x<=-10000){
				en3=1;
			}
			if(en1==1 && e.health!=0){
				printf("************en1\n");
				printf("----------xe: %d\n",e.pos.x);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				moveIA(&e,&h,screen,&attack,moving,&on);
			}
			if(death<=8){
				NPC_death(&e);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				death++;
				SDL_Delay(5);
			}
			if(e2.health==0){
				NPC_death(&e);
			}
			if(boss.health==0){
				boss_death(&boss);
			}
			if(en2==1 && e2.health!=0){
				printf("************en2\n");
				printf("-----------xe2: %d\n",e2.pos.x);
				afficherEnnemi(&e2,screen,e2.pos.x,e2.pos.y);
				moveIA(&e2,&h,screen,&attack,moving,&on);
			}
			if(en3==1 && boss.health!=0){
				printf("************en3\n");
				printf("-----------xboss: %d\n",boss.pos.x);
				afficherEnnemi(&boss,screen,boss.pos.x,boss.pos.y);
				moveIA_boss(&boss,&h,screen,&attack,moving,&on);
				if(boss.health<0){
					boss.health=0;
				}
				afficher_image(screen,hp[boss.health/10]);
			}
			if(r==0 && l==0 && up==0 && down==0 && h.up==0 && att>28){
				hero_stand_by(&h);
				afficher_character(screen,&h,h.pos.x,h.pos.y);
				tmps++;
			}
			else{
				tmps=0;
			}
			jump(&h);
			if(h.up==1){
				SDL_Delay(5);
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
			}
			scrolling_caractere(b,&h,up,down,r,l,&moving);
			if(r==1){
				scrolling (&b,up,down,r,l,20,5);
				h.direction=0;
				hero_run(&h);
				h.pos.y-=50;
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
				h.pos.y+=50;
				h.SI.score++;
				printf("pos hero = %d",h.pos.x);
				if (h.pos.x>1000)
				{
				PositionAhmed.x+=20;
				}
				else if( h.pos.x<1000 )
				{
				PositionAhmed.x+=40;
				}
				else if( h.pos.x>1220 )
				{
				PositionAhmed.x+=3;
				}
				sprintf(string,"score:%d",h.SI.score);
			}
			if(l==1){
				scrolling (&b,up,down,r,l,20,10);
				h.direction=1;
				hero_run(&h);
				h.pos.y-=50;
				afficher_character(screen,&h,h.pos.x,h.pos.y); 
				h.pos.y+=50;
				h.SI.score++;
				if((h.pos.x)>=200){
					(PositionAhmed.x)-=40;
				}
				else{
				if( h.pos.x<200){
					PositionAhmed.x-=20;
				
				}
				}
				sprintf(string,"score:%d",h.SI.score);
			}
			if(up==1){
				scrolling (&b,up,down,r,l,20,10);
				h.SI.score++;
				PositionAhmed.y-=5;
				sprintf(string,"score:%d",h.SI.score);
			}
			if(down==1){
				scrolling (&b,up,down,r,l,20,10);
				h.SI.score++;
				PositionAhmed.y+=5;
				sprintf(string,"score:%d",h.SI.score);
			}
			if(r2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				h2.direction=0;
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(l2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				h2.direction=1;
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(up2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(down2==1){
				scrolling (&b,up2,down2,r2,l2,20,5);
				hero_run(&h2);
				h2.SI.score++;
				sprintf(string,"score:%d",h2.SI.score);
			}
			if(perso2==1){
				afficher_character(screen,&h2,x2,y2);
			}
			while(leadb==0){
				SDL_PollEvent(&event);
				afficher_image(screen,bg2);
				afficher_image(screen,lb);
				SDL_Flip(screen);
				if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE){
					leadb=1;
				}
			}
			while (sous_menu==0){
				while(SDL_PollEvent(&event)){
				afficherBack(b,screen,b.pos.x,b.pos.y);
				afficher_character(screen,&h,x,y);
				afficherEnnemi(&e,screen,e.pos.x,e.pos.y);
				afficher_image(screen,ssbg);
				buttons_fleche(&event,&entre_r,&entre_l,&entre_q,&end);
				}
				if( entre_r ==1 && event.key.keysym.sym==SDLK_RETURN){ sous_menu=1;}
				if( entre_l ==1 && event.key.keysym.sym==SDLK_RETURN){ leadb=0;
				entre_l=0;
				sous_menu=1;
				}
				if( entre_q ==1 && event.key.keysym.sym==SDLK_RETURN){sous_menu=1; end=0; save_game("saved_game.txt",x,y,b.pos.x,b.pos.y,e.pos.x,e.pos.y,h.SI.score);}
				if(event.motion.x<306 && event.motion.x>65 && event.motion.y<522 && event.motion.y>447 || (entre_r==1)){afficher_text(screen,resume1,"Resume");}
				else { afficher_text(screen,resume0,"Resume");
				 }
				if(entre_l==1){ afficher_text(screen,leaderboard1,"Leaderboard");
				}
				else { afficher_text(screen,leaderboard0,"Leaderboard"); }
				if( entre_q==1){afficher_text(screen,quit1,"Save & Quit the game");}
				else { afficher_text(screen,quit0,"Save & Quit the game"); }
				if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE) {sous_menu=1;}
				SDL_Flip(screen);
			}
			SDL_Flip(screen);
			while(SDL_PollEvent(&event)){
				switch(event.type){
					case SDL_KEYDOWN:{
						switch(event.key.keysym.sym){
							case SDLK_RIGHT:{
								r=1;
								break;
							}
							case SDLK_LEFT:{
								l=1;
								break;
							}
							case SDLK_UP:{
								up=1;
								break;
							}
							case SDLK_DOWN:{
								down=1;
								break;
							}
							case SDLK_d:{
								r2=1;
								break;
							}
							case SDLK_q:{
								l2=1;
								break;
							}
							case SDLK_z:{
								up2=1;
								break;
							}
							case SDLK_s:{
								down2=1;
								break;
							}
							case SDLK_o:{
								perso2=1;
								break;
							}
							case SDLK_p:{
								//perso2=0;
								sous_menu=0;
								break;
							}
							case SDLK_TAB:{
								leadb=0;
								break;
							}
							case SDLK_ESCAPE:{
								end=0;
								break;
							}
							case SDLK_k:{
								att=0;
								break;
							}
							case SDLK_SPACE:{
								jmp=0;
								if(h.up==0){
									h.up=1;
								}
								if(miniup==0){
									miniup=1;
								}
								break;
							}
							case SDLK_a:{
								if(h2.up==0){
									h2.up=1;
								}
								break;
							}
						}
						break;
					}
					case SDL_KEYUP:{
						h.SI.score+=10;
						switch(event.key.keysym.sym){
							case SDLK_RIGHT:{
								r=0;
								ri=1;
								break;
							}
							case SDLK_LEFT:{
								ri=0;
								l=0;
								break;
							}
							case SDLK_UP:{
								up=0;
								break;
							}
							case SDLK_DOWN:{
								down=0;
								break;
							}
							case SDLK_d:{
								r2=0;
								break;
							}
							case SDLK_q:{
								l2=0;
								break;
							}
							case SDLK_z:{
								up2=0;
								break;
							}
							case SDLK_s:{
								down2=0;
								break;
							}
						}
						break;
					}
					case SDL_QUIT:{
						end=0;
						break;
					}
				}
				SDL_Flip(screen);
			}
			MAJMinimap(PositionAhmed,&m,redimensionnement);//redimentionnement de la position mini hero
		}
		saveScore(h.SI,"meilleur score");
		////liberation des ressources
		free_vie(v,0);
		free_vie(v,1);
		free_vie(v,2);
		free_bg(b);
		free_image(lb);
		free_image(bg2);
		free_text(t);
		free_text(d);
		free_character(h);
		free_character(h2);
		free_character(e);
		free_character(e2);
		free_character(boss);
		free_object(o);
		Liberer(&m);
		free_images_animer_Enigme_point(images_enigme);
		free_images_animer_Enigme_point(mini_images_enigme);
	}
}
