#include "header.h"


void buttons_fleche( SDL_Event* event, int* entre_r, int* entre_l, int* entre_q, int* end)
{
	switch(event->type){
						case SDL_KEYDOWN:{
						switch(event->key.keysym.sym){
							case SDLK_DOWN:{
									if((*entre_r)==0 && *entre_l==0 && *entre_q==0){
										*entre_r=1;
									}
									else{
										if(*entre_r==1 && *entre_l==0 && *entre_q==0){
											*entre_r=0;
											*entre_l=1;
										}
										else{
											if(*entre_r==0 && *entre_l==1 && *entre_q==0){
												*entre_q=1;
												*entre_l=0;
											}
											else{
												if(*entre_r==0 && *entre_l==0 && *entre_q==1){
													*entre_q=0;
												}
											}
										}
									}
									break;
								}
							case SDLK_UP:{
									if(*entre_r==1 && *entre_l==0 && *entre_q==0){
										*entre_r=0;
									}
									else{
										if(*entre_r==0 && *entre_l==1 && *entre_q==0){
											*entre_r=1;
											*entre_l=0;
										}
										else{
											if(*entre_r==0 && *entre_l==0 && *entre_q==1){
												*entre_l=1;
												*entre_q=0;
											}
										}
									}
									break;
								}
								case SDL_QUIT:{
								*end=0;
								break;
							}
						break;
						}
						}
						}
}
