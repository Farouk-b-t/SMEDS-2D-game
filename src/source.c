#include"header.h"
void intro(Mix_Music *music){
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	music=Mix_LoadMUS("sfx/menu/menu.mp3");
	Mix_PlayMusic(music,-1);
	Mix_VolumeMusic(10000);
}
void liberer_music(Mix_Music *music){
	Mix_FreeMusic(music);
}
////////////////////////
void musiquebref_click(Mix_Chunk *music,int volume){
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
	music=Mix_LoadWAV("sfx/click/click_sfx_1.wav");
	Mix_PlayChannel(-1,music,0);
	Mix_VolumeChunk(music,volume);
}
void musiquebref_drag(Mix_Chunk *music,int volume){//dragging sound
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
	music=Mix_LoadWAV("sfx/drag/drag_sfx_1.wav");
	if(music==NULL){
		printf("Couldn't load the sound\n");
	}
	else{
		Mix_PlayChannel(-1,music,0);
		Mix_VolumeChunk(music,volume);
	}
}
void liberer_musiquebref(Mix_Chunk *music){//segmentation fault
	Mix_FreeChunk(music);
}
//////////////////////////////////:
//animation:
void load_images(menu_animation images[]) {
    images[0].filename = "anim_bg/bg1.png";
    images[1].filename = "anim_bg/bg2.png";
    images[2].filename = "anim_bg/bg3.png";
    images[3].filename = "anim_bg/bg4.png";
    images[4].filename = "anim_bg/bg5.png";
    images[5].filename = "anim_bg/bg6.png";
    images[6].filename = "anim_bg/bg7.png";
    images[7].filename = "anim_bg/bg8.png";
    images[8].filename = "anim_bg/bg9.png";


    for (int i = 0; i < 9; i++) {
        images[i].surface = IMG_Load(images[i].filename);
        if (images[i].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", images[i].filename, SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
}

void free_images(menu_animation images[]) {
    for (int i = 0; i < 9; i++) {
        SDL_FreeSurface(images[i].surface);
    }
}
