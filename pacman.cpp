#include<iostream>
#include"hash.h"
#include <iomanip>
#include "time.h"
using namespace std;
bool isnotblock1( int ,int);
int showmenu( int);
void scape1 (int &,int &,int &,int &);
void redghostmotion(int redghostarray[12][9]);
void pacmanmotion1();
int pausemenu1();
int pinktarget1(int,int ,int );
bool finish1(int [12][9]);//prototype;
bool finish2(int [10][11]);//prototype;

void scape2(int &,int &,int &,int &);
void redghostmotion2(int redghostarray[10][11]);
void pacmanmotion2();
int pinktarget2(int,int ,int );
bool isnotblock2( int ,int);



int main(){
	while(true){
int a=showmenu(1);
	switch(a){
	case 1:{ pacmanmotion1();
	//			showmenu(1);
	}break;
	case 2: //showhelp()
		 ;break;
	case 0:return 0;
					}}
}
////////////////////////////////////////////////////////////////////////////////////pacmotion1//////////////////////
void pacmanmotion1(){
	bool moving = true;
	int flag2=0;
	int i=0;
	int j=0;
	int redx=4;
	int redy=4;
	int pinkx=4;
	int pinky=4;
	int orgx=4;
	int orgy=4;
	int pacmanx=4 ;
	int pacmany=11 ;
	int paci=pacmanx*50;
	int pacj=pacmany*50;
	int vpaci=10;
	int vpacj=10;
	int score1=0;
	int score2=0;
	int dif=0;
	int flag=0;
	int redxi=300;
	int redyj=200;
	int pinki=300;
	int pinkj=200;
	int orgi=300;
	int orgj=200;
	int live=5;
	int livey=0;
	int second=0;
	int timeblue=0;
	char str[5];


	int way1[12][9]={{0,2,2,2,2,2,2,2,0},
			{0,2,0,0,0,0,0,2,0},
			{3,2,2,2,0,2,2,2,3},
			{2,0,0,2,0,2,0,0,2},
			{2,2,2,2,2,2,2,2,2},
			{0,0,2,0,1,0,2,0,0},
			{3,2,2,0,0,0,2,2,3},
			{2,0,2,2,2,2,2,0,2},
			{2,0,0,2,0,2,0,0,2},
			{2,2,2,2,0,2,2,2,2},
			{0,2,0,0,0,0,0,2,0},
			{0,2,2,2,1,2,2,2,0}};





	SDL_Event event;
	SDL_Surface *screen;
	InitEngine(screen);
	SDL_Surface *map1;
	SDL_Surface *pacman;
	SDL_Surface *pacleft;
	SDL_Surface *pacright;
	SDL_Surface *pacup;
	SDL_Surface *pacdown;
	SDL_Surface *nut;
	SDL_Surface *bignut;
	SDL_Surface*red;
	SDL_Surface* pink;
	SDL_Surface* blue;
	SDL_Surface* orange;
	SDL_Surface*picred;
	SDL_Surface*picpink;
	SDL_Surface*picorg;
	SDL_Surface *pacman2;
			SDL_Surface *pacman3;
			SDL_Surface *pacleft1;
			SDL_Surface *pacleft2;
			SDL_Surface *pacleft3;
			SDL_Surface *pacright1;
			SDL_Surface *pacright2;
			SDL_Surface *pacright3;
			SDL_Surface *pacup1;
			SDL_Surface *pacup2;
			SDL_Surface *pacup3;
			SDL_Surface *pacdown1;
			SDL_Surface *pacdown2;
			SDL_Surface *pacdown3;
			SDL_Surface *n0;
					SDL_Surface *n1;
					SDL_Surface *n2;
					SDL_Surface *n3;
					SDL_Surface *n4;
					SDL_Surface *n5;
					SDL_Surface *n6;
					SDL_Surface *n7;
					SDL_Surface *n8;
					SDL_Surface *n9;
			SDL_Surface* gameover;


	Music* intermission;
	Sound * eatnut;
	Sound* pacdeath;
	picred =ImgLoader("/home/maah/workspace/lasttest2/src/red.png",255,255,255);
	red =ImgLoader("/home/maah/workspace/lasttest2/src/red.png",255,255,255);
	map1 = ImgLoader("/home/maah/workspace/lasttest2/src/map1.png",255,255,255);
	pacman = ImgLoader("/home/maah/workspace/lasttest2/src/pacright3.png",255,255,255);
	pacleft = ImgLoader("/home/maah/workspace/lasttest2/src/pacleft3.png",255,255,255);
	pacright = ImgLoader("/home/maah/workspace/lasttest2/src/pacright3.png",255,255,255);
	pacup = ImgLoader("/home/maah/workspace/lasttest2/src/pacup3.png",255,255,255);
	pacdown = ImgLoader("/home/maah/workspace/lasttest2/src/pacdown3.png",255,255,255);
	nut = ImgLoader("/home/maah/workspace/lasttest2/src/doone.png",255,255,255);
	bignut = ImgLoader("/home/maah/workspace/lasttest2/src/jayeze.png",255,255,255);
	picpink=ImgLoader("/home/maah/workspace/lasttest2/src/pink.png",255,255,255);
	pink=ImgLoader("/home/maah/workspace/lasttest2/src/pink.png",255,255,255);
	blue=ImgLoader("/home/maah/workspace/lasttest2/src/blue.png",255,255,255);
	orange=ImgLoader("/home/maah/workspace/lasttest2/src/orange.png",255,255,255);
	orange=ImgLoader("/home/maah/workspace/lasttest2/src/orange.png",255,255,255);
	intermission = LoadMusic("/home/maah/workspace/lasttest2/src/pacman_intermission.wav");
	eatnut=LoadSound("/home/maah/workspace/lasttest2/src/pacman_chomp.wav");
	pacdeath=LoadSound("/home/maah/workspace/lasttest2/src/pacman_death.wav");
	pacleft2 = ImgLoader("/home/maah/workspace/prj27/src/pacleft2.png",255,255,255);
			pacleft3 = ImgLoader("/home/maah/workspace/prj27/src/pacleft3.png",255,255,255);
			pacright1 = ImgLoader("/home/maah/workspace/prj27/src/pacright1.png",255,255,255);
			pacright2 = ImgLoader("/home/maah/workspace/prj27/src/pacright2.png",255,255,255);
			pacright3 = ImgLoader("/home/maah/workspace/prj27/src/pacright3.png",255,255,255);
			pacup1 = ImgLoader("/home/maah/workspace/prj27/src/pacup1.png",255,255,255);
			pacup2 = ImgLoader("/home/maah/workspace/prj27/src/pacup2.png",255,255,255);
			pacup3 = ImgLoader("/home/maah/workspace/prj27/src/pacup3.png",255,255,255);
			pacdown1 = ImgLoader("/home/maah/workspace/prj27/src/pacdown1.png",255,255,255);
			pacdown2 = ImgLoader("/home/maah/workspace/prj27/src/pacdown2.png",255,255,255);
			pacdown3 = ImgLoader("/home/maah/workspace/prj27/src/pacdown3.png",255,255,255);
			n0 = ImgLoader("/home/maah/workspace/lastestprj/src/0.png",255,255,255);
					n1 = ImgLoader("/home/maah/workspace/lastestprj/src/1.png",255,255,255);
					n2 =ImgLoader("/home/maah/workspace/lastestprj/src/2.png",255,255,255);
					n3 =ImgLoader("/home/maah/workspace/lastestprj/src/3.png",255,255,255);
					n4=ImgLoader("/home/maah/workspace/lastestprj/src/4.png",255,255,255);
					n5=ImgLoader("/home/maah/workspace/lastestprj/src/5.png",255,255,255);
					n6=ImgLoader("/home/maah/workspace/lastestprj/src/6.png",255,255,255);
					n7=ImgLoader("/home/maah/workspace/lastestprj/src/7.png",255,255,255);
					n8=ImgLoader("/home/maah/workspace/lastestprj/src/8.png",255,255,255);
					n9=ImgLoader("/home/maah/workspace/lastestprj/src/9.png",255,255,255);
		gameover = ImgLoader("/home/maah/workspace/lastestprj/src/9.png",255,255,255);


	PlayMusic(intermission,-1);
	while(moving)
	{
		second++;
		livey=0;
		if(finish1(way1)){
				pacmanmotion2();
				return ;
		}





SDL_FillRect(screen,NULL,BLACK);
SDL_BlitSurface(pacman,screen,paci,pacj);
SDL_BlitSurface(map1,screen,0,0);
if(second>=50)
SDL_BlitSurface(red,screen,redx*50,redy*50);
//SDL_BlitSurface(red,screen,redxi,redyj);
if(second>=100)
SDL_BlitSurface(pink,screen,pinkx*50,pinky*50);
//SDL_BlitSurface(pink,screen,pinki,pinkj);
if(second>=150)
SDL_BlitSurface(orange,screen,orgx*50,orgy*50);

SDL_Delay(100);
///////////////////////////////////////////////print nut /////////////////////////////////////////
									for(int i=0;i<12;i++){
										for(int j=0;j<9;j++){
											 if(way1[i][j]==1)
												 continue;
										 if(way1[i][j]==2)
										SDL_BlitSurface(nut,screen,j*50,i*50);
										if(way1[i][j]==3) //daneye bozorg
										 SDL_BlitSurface(bignut,screen,j*50,i*50);
															 			 }
															 		 }
/////////////////////////////////////////////////////////////score/////////////////
									int j=score2;
																										 		str[4] = (char) ( (j%10) + '0' );
																										 		str[3] = (char) ( (j%100 - j%10)/10 + '0');
																										 		str[2] = (char) ( (j%1000 - j%100)/100 + '0');
																										 		str[1] = (char) ( (j%10000 - j%1000)/1000 + '0');
																										 		str[0] = (char) ( (j%100000 - j%10000)/10000 + '0');



																										 		for(int i=0;i<5;i++)
																										 			switch(str[i]){
																										 			case 0:
																										 				SDL_BlitSurface(n0,screen,600+(i*25),400);
																										 				break;
																										 			case 1:
																										 				SDL_BlitSurface(n1,screen,600+(i*25),400);
																										 				break;
																										 			case 2:
																										 				SDL_BlitSurface(n2,screen,600+(i*25),400);
																										 				break;
																										 			case 3:
																										 				SDL_BlitSurface(n3,screen,600+(i*25),400);
																										 				break;
																										 			case 4:
																										 				SDL_BlitSurface(n4,screen,600+(i*25),400);
																										 				break;
																									 				case 5:
																										 				SDL_BlitSurface(n5,screen,600+(i*25),400);
																										 				break;
																										 			case 6:
																										 				SDL_BlitSurface(n6,screen,600+(i*25),400);
																										 				break;
																									 				case 7:
																									 					SDL_BlitSurface(n7,screen,600+(i*25),400);
																									 					break;
																									 				case 8:
																									 					SDL_BlitSurface(n8,screen,600+(i*25),400);
																									 					break;
																									 				case 9:
																									 					SDL_BlitSurface(n9,screen,600+(i*25),400);
																									 					break;
																										 			}
///////////////////////////////////////////////////////////////////////////////

																	SDL_Flip(screen);
																	 SDL_FreeSurface(screen);
///////////////////////////////////////////////////////////pacman//////////////////////////////////////////////////////////////



																	 if(flag!=flag2 && (paci%50==0) && (pacj%50 ==0) )
																	 {
																		 switch(flag)
																		 {
																		 case 1:
																			 if(isnotblock1(pacmanx-1,pacmany) && (paci-vpaci>=0)&&(paci%50 ==0))
																				 flag2=flag;break;
																		 case 2:
																			 if(isnotblock1(pacmanx+1,pacmany )&& (paci+vpaci<=500) && (paci%50==0))
																				 flag2=flag;break;
																		 case 3:if(isnotblock1(pacmanx,pacmany-1) &&  pacj-vpacj>=0 && (pacj%50 ==0) )
																			 	 flag2=flag;break;
																		 case 4:if(isnotblock1(pacmanx,pacmany+1) && pacj+vpacj<=450 && (pacj%50 ==0))
																			 	 flag2=flag;break;

																		 }
																	 }
																	 switch(flag2){
																	 														case 1:cout<< "left2"<<endl;

																	 														if(isnotblock1(pacmanx-1,pacmany) && (paci-vpaci>=0)){
																	 															paci-=vpaci;
																	 															cout<<paci<<" "<<pacj<<endl;
																	 															if(paci%50 ==0)
																	 																pacmanx=paci/50;
																	 															cout<<pacmanx<<" "<<pacmany<<endl;
																	 														}

																	 														break;
																	 														case 2: if(isnotblock1(pacmanx+1,pacmany )&& (paci+vpaci<=500)){

																	 															paci+=vpaci;
																	 															cout<<paci<<" "<<pacj<<endl;
																	 															if(paci%50==0)
																	 																pacmanx=paci/50;
																	 															cout<<pacmanx<<" "<<pacmany<<endl;
																	 															cout<< "right2"<<endl;
																	 														}
																	 														break;
																	 														case 3:if(isnotblock1(pacmanx,pacmany-1) &&  pacj-vpacj>=0 ){

																	 															pacj-=vpacj;
																	 															cout<<paci<<" "<<pacj<<endl;
																	 															if(pacj%50 ==0)
																	 																pacmany= pacj/50;
																	 															cout<<pacmanx<<" "<<pacmany<<endl;
																	 															cout<< "down2"<<endl;
																	 														}
																	 														break;
																	 														case 4:if(isnotblock1(pacmanx,pacmany+1) && pacj+vpacj<=450 ){

																	 															pacj+=vpacj;
																	 															cout<<paci<<" "<<pacj<<endl;
																	 															if(pacj%50 ==0){
																	 																pacmany=pacj/50;
																	 															cout<<pacmanx<<" "<<pacmany<<endl;}
																	 															cout<< "up2"<<endl;
																	 														}
																	 														break;
																	 							}
																					if(SDL_PollEvent(&event)){
																												if(event.type==SDL_QUIT)
																														moving=false;
																													SDLKey keypressed = event.key.keysym.sym;

																					switch(keypressed){

																					case SDLK_ESCAPE:
																						{ if(pausemenu1()==3)	{StopMusic();	return;}
																						else cout<<"bargashtam"<<endl;

																				break;
																				}

																					case SDLK_LEFT: {

																														 if(isnotblock1(pacmanx-1,pacmany) == 1  && paci%50 ==0)
																															flag=1;
																														 pacman=pacleft2;
																														cout<< "left"<<endl;


																																	break;}


																																case SDLK_RIGHT:{

																																	 if(isnotblock1(pacmanx+1,pacmany) == 1  && paci%50 ==0 )
																																		flag=2;
																																	 pacman = pacright2;
																																	cout<< "right"<<endl;
																																	break;}


																																case SDLK_UP:{

																																	 if(isnotblock1(pacmanx,pacmany-1) == 1  && pacj%50 ==0 )
																																		flag=3;
																																	 pacman = pacup2;
																																	cout<< "up"<<endl;


																																	break;}


																																case SDLK_DOWN:{

																																	if(isnotblock1(pacmanx,pacmany+1) == 1  && pacj%50 ==0)
																																		flag=4;
																																	pacman = pacdown2;
																																	cout<< "down"<<endl;


																																break;}

																					}

																				}








///////////////////////////////////eat big nut//////////////////////////////////////////////







cout<<"timeblue"<<timeblue;
		  if((pacmanx==0 && pacmany==2 && way1[2][0]==3) || (pacmanx==8 && pacmany==2 && way1[2][8]==3) || (pacmanx==0 && pacmany==6 && way1[6][0]==3) || (pacmanx==8 && pacmany==6 && way1[6][8]==3))
		  {   cout<<"omade "<<endl; timeblue=10000;}

				 if(timeblue-9955>0){
					 vpaci=vpacj=25;
					 cout<<"????????????"<<endl;
					 timeblue--;
						scape1(redx,redy,redxi,redyj);
						red=blue; pink=blue; orange=blue;
						scape1(pinkx,pinky,pinki,pinkj);
						scape1(orgx,orgy,orgi,orgj);

		 	 	if(pacmanx==redx && pacmany==redy){score2+=200; redx=redy=4;redxi=300;redyj=200;}
				if(pacmanx==pinkx && pacmany== pinky ){score2+=200;pinkx=pinky=4;pinki=300;pinkj=200;}
				if(pacmanx==orgx && pacmany == orgy){score2+=200;orgx=orgy=4;orgx=orgy=4;orgi=300;orgy=200;}
								 }
				 else{cout<<"else"<<endl;
					 red=picred;
					 orange=picorg;
					 pink=picpink;



				 	if(pacmanx==redx && pacmany==redy){live--; redx=redy=pinkx=pinky=orgx=orgy=4;second=0;pacmanx=4;pacmany=11;	 redxi=300;
							redyj=200; pinki=300; pinkj=200; orgi=300; orgj=200;paci=pacmanx*50;pacj=pacmany*50; PlaySound(pacdeath,1);}
					if(pacmanx==pinkx && pacmany== pinky ){paci=pacmanx*50;pacj=pacmany*50;
							live--;redyj=200; pinki=300; pinkj=200; orgi=300; orgj=200;redx=redy=pinkx=pinky=orgx=orgy=4;second=0;pacmanx=4;pacmany=11;	PlaySound(pacdeath,1);}
					if(pacmanx==orgx && pacmany == orgy){paci=pacmanx*50;pacj=pacmany*50;
						redyj=200; pinki=300; pinkj=200; orgi=300; orgj=200;live--;redx=redy=pinkx=pinky=orgx=orgy=4;second=0;pacmanx=4;pacmany=11;	PlaySound(pacdeath,1);}

				 }
				 if(live==-1)
				 {
					 SDL_BlitSurface(gameover,screen,150,150);
					 SDL_Delay(2000);
					 return;
				 }
				 for(int d=0;d<live;d++){
				 			SDL_BlitSurface(pacman,screen,600,livey);
				 				livey+=60;
				 						}
////////////////////////////////////////////////////////////////////////////////////




					if(	way1[pacmany][pacmanx]==2){
						score2+=50;
						PlaySound(eatnut,1);
						if(score1 != score2)
						score1=score2;}

					way1[pacmany][pacmanx]=1;

					int redghostarray[12][9];
						for(int i=0;i<12;i++){
							for(int j=0;j<9;j++){

									redghostarray[i][j]=108;

							}
						}	redghostarray[pacmany][pacmanx]=0;
							redghostmotion(redghostarray);

							int pinkghostarray[12][9];
											for(int i=0;i<12;i++){
												for(int j=0;j<9;j++){

														pinkghostarray[i][j]=108;

												}
											}
							switch(flag){
							case 1:pinkghostarray[pacmany][pinktarget1(pacmanx,pacmany,flag)]=0;break;
							case 2:pinkghostarray[pacmany][pinktarget1(pacmanx,pacmany,flag)]=0;break;
							case 3:pinkghostarray[pinktarget1(pacmanx,pacmany,flag)][pacmanx]=0;break;
							case 4:pinkghostarray[pinktarget1(pacmanx,pacmany,flag)][pacmanx]=0;break;
							}

							redghostmotion(pinkghostarray);



								int orgghostarray[12][9];
									for(int i=0;i<12;i++){
										for(int j=0;j<9;j++){

												orgghostarray[i][j]=108;

										}
											}
									orgghostarray[pacmany][pacmanx]=0;
									redghostmotion(orgghostarray);
									dif=(orgx-pacmanx)*(orgx-pacmanx)+(orgy-pacmany)*(orgy-pacmany);

									for(int i=0;i<12;i++){
											for(int j=0;j<9;j++){

												cout<<	orgghostarray[i][j]<<setw(5);

																}
																	cout<<endl;}



////////////////////////////////////////////////////////////////////////////redghostmotion////////////////////////////////////////////////////////////////////*/

	if(second>=50){


	if(redghostarray[redy][redx-1]<redghostarray[redy][redx] && redx-1>=0 ){
	redxi-=10;cout<<redxi<<"redxi";
	if(redxi%50==0)
		--redx;
	cout<<"red position1: "<<redx<<" "<<redy<<redghostarray[redy][redx]<<endl;
				}
if(redghostarray[redy+1][redx]<redghostarray[redy][redx]&& redy+1<12)
	{redyj+=10;cout<<redyj<<"redyj";
	if(redyj%50==0)
	++redy;
	cout<<"red position2: "<<redx<<" "<<redy<<redghostarray[redy][redx]<<endl;}
if(redghostarray[redy-1][redx]<redghostarray[redy][redx] && redy-1>=0){
	redyj-=10;cout<<redyj<<"redyj";
	if(redyj%50==0)
	--redy;
cout<<"red position3: "<<redx<<" "<<redy<<redghostarray[redy][redx]<<endl;}
if(redghostarray[redy][redx+1]<redghostarray[redy][redx] && redx+1<9){
	redxi+=10;cout<<redxi<<"redxi";
	if(redxi%50==0)
	++redx;
cout<<"red position4: "<<redx<<" "<<redy<<redghostarray[redy][redx]<<endl;}
}
	//////////////////////////////////////////////////////pinkghostmotion/////////////////////////////////////////////
if(second>=100){


											if(pinkghostarray[pinky][pinkx-1]<pinkghostarray[pinky][pinkx] && pinkx-1>=0 ){
												pinki-=10;cout<<pinki<<"pinki"<<endl;
												if(pinki%50==0)
												pinkx--;
													cout<<"pink position1: "<<pinkx<<" "<<pinky<<pinkghostarray[pinky][pinkx]<<endl;
												}
												if(pinkghostarray[pinky+1][pinkx]<pinkghostarray[pinky][pinkx]&& pinky+1<12)
												{pinkj+=10;cout<<pinkj<<"pinkj"<<endl;
													if(pinkj%50==0)
													pinky++;
												 cout<<"pink position2: "<<pinkx<<" "<<pinky<<pinkghostarray[pinky][pinkx]<<endl;}
												if(pinkghostarray[pinky-1][pinkx]<pinkghostarray[pinky][pinkx] && pinky-1>=0)
												{pinkj-=10;cout<<pinkj<<"pinkj"<<endl;
												if(pinkj%50==0)
													pinky--;
												cout<<"pink position3: "<<pinkx<<" "<<pinky<<pinkghostarray[pinky][pinkx]<<endl;}
												if(pinkghostarray[pinky][pinkx+1]<pinkghostarray[pinky][pinkx] && pinkx+1<9)
												{pinki+=10;cout<<pinki<<"pinki"<<endl;
												if(pinki%50==0)
													pinkx++;cout<<"pink position4: "<<pinkx<<" "<<pinky<<pinkghostarray[pinky][pinkx]<<endl;}
	}
									////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							if(second>=150){


												if(dif>25){

														scape1(orgx,orgy,orgi,orgj);
												}
												else{
													if(orgghostarray[orgy][orgx-1]<orgghostarray[orgy][orgx] && orgx-1>=0 ){
														orgi-=10;
														if(orgi%50==0)orgx--;
													cout<<"org position1: "<<orgx<<" "<<orgy<<orgghostarray[orgy][orgx]<<endl;
												}
												if(orgghostarray[orgy+1][orgx]<orgghostarray[orgy][orgx]&& orgy+1<12)
												{orgj+=10;
												if(orgj%50==0)orgy++; cout<<"org position2: "<<orgx<<" "<<orgy<<orgghostarray[orgy][orgx]<<endl;}
												if(orgghostarray[orgy-1][orgx]<orgghostarray[orgy][orgx] && orgy-1>=0)
												{orgj-=10;
												if(orgj%50==0)orgy--;cout<<"org position3: "<<orgx<<" "<<orgx<<orgghostarray[orgy][orgx]<<endl;}
												if(orgghostarray[orgy][orgx+1]<orgghostarray[orgy][orgx] && orgx+1<9)
												{orgi+=10;
												if(orgi%50==0)orgx++;cout<<"org position4: "<<orgx<<" "<<orgx<<orgghostarray[orgy][orgx]<<endl;}

												}}
									/////////////////////////////////////////orangghostmotion//////////////////////////////////////////////////////////////////







	}

















	SDL_Flip(screen);




	return ;


}


///////////////////////////////////////////////pacmotion2///////////////////////////////////////////////////
void pacmanmotion2(){
	bool moving = true;
	int flag2=0;
	int i=0;
	int j=0;
	int redx=2;
	int redy=3;
	int pinkx=2;
	int pinky=3;
	int orgx=2;
	int orgy=3;
	int pacmanx=2 ;
	int pacmany=9 ;
	int paci=pacmanx*50;
	int pacj=pacmany*50;
	int vpaci=10;
	int vpacj=10;
	int score1=0;
	int score2=0;
	int dif=0;
	int flag=0;
	int redxi=100;
	int redyj=150;
	int pinki=200;
	int pinkj=150;
	int orgi=100;
	int orgj=150;
	int live=5;
	int livey=0;
	int second=0;
	int timeblue;
char str[5];












int way2[10][11]={{3,2,2,2,2,0,0,2,2,2,3},
				{2,0,0,0,2,2,2,2,0,0,2},
				{2,2,2,2,2,0,2,0,0,2,2},
				{2,0,0,0,2,2,2,2,2,2,0},
				{2,0,0,0,0,2,0,0,2,0,0},            //matrix zamin
				{2,2,3,2,0,2,2,2,2,0,3},
				{0,2,0,2,0,2,0,0,2,2,2},
				{2,2,0,2,2,2,2,0,2,0,2},
				{2,0,0,0,2,0,2,2,2,0,2},
				{2,2,-1,2,2,0,0,0,2,2,2}
				};




SDL_Event event;
SDL_Surface *screen;
InitEngine(screen);
SDL_Surface *map2;
SDL_Surface *pacman1;
SDL_Surface *pacman2;
SDL_Surface *pacman3;
SDL_Surface *pacleft1;
SDL_Surface *pacleft2;
SDL_Surface *pacleft3;
SDL_Surface *pacright1;
SDL_Surface *pacright2;
SDL_Surface *pacright3;
SDL_Surface *pacup1;
SDL_Surface *pacup2;
SDL_Surface *pacup3;
SDL_Surface *pacdown1;
SDL_Surface *pacdown2;
SDL_Surface *pacdown3;
SDL_Surface *nut;
SDL_Surface *bignut;
SDL_Surface*red;
SDL_Surface* pink;
SDL_Surface* blue;
SDL_Surface* orange;
SDL_Surface*picred;
SDL_Surface*picpink;
SDL_Surface*picorg;
Music* intermission;
Sound * eatnut;
Sound * pacdeath;
SDL_Surface *n0;
SDL_Surface *n1;
					SDL_Surface *n2;
					SDL_Surface *n3;
					SDL_Surface *n4;
					SDL_Surface *n5;
					SDL_Surface *n6;
					SDL_Surface *n7;
					SDL_Surface *n8;
					SDL_Surface *n9;


map2 = ImgLoader("/home/maah/workspace/pri27/src/map2.png",255,255,255);
pacman1 = ImgLoader("/home/maah/workspace/prj27/src/pacright1.png",255,255,255);
pacman2 = ImgLoader("/home/maah/workspace/prj27/src/pacright2.png",255,255,255);
pacman3 = ImgLoader("/home/maah/workspace/prj27/src/pacright3.png",255,255,255);
pacleft1 = ImgLoader("/home/maah/workspace/prj27/src/pacleft1.png",255,255,255);
pacleft2 = ImgLoader("/home/maah/workspace/prj27/src/pacleft2.png",255,255,255);
pacleft3 = ImgLoader("/home/maah/workspace/prj27/src/pacleft3.png",255,255,255);
pacright1 = ImgLoader("/home/maah/workspace/prj27/src/pacright1.png",255,255,255);
pacright2 = ImgLoader("/home/maah/workspace/prj27/src/pacright2.png",255,255,255);
pacright3 = ImgLoader("/home/maah/workspace/prj27/src/pacright3.png",255,255,255);
pacup1 = ImgLoader("/home/maah/workspace/prj27/src/pacup1.png",255,255,255);
pacup2 = ImgLoader("/home/maah/workspace/prj27/src/pacup2.png",255,255,255);
pacup3 = ImgLoader("/home/maah/workspace/prj27/src/pacup3.png",255,255,255);
pacdown1 = ImgLoader("/home/maah/workspace/prj27/src/pacdown1.png",255,255,255);
pacdown2 = ImgLoader("/home/maah/workspace/prj27/src/pacdown2.png",255,255,255);
pacdown3 = ImgLoader("/home/maah/workspace/prj27/src/pacdown3.png",255,255,255);
nut = ImgLoader("/home/maah/workspace/prj27/src/doone.png",255,255,255);
bignut = ImgLoader("/home/maah/workspace/prj27/src/jayeze.png",255,255,255);
picred =ImgLoader("/home/maah/workspace/lasttest2/src/red.png",255,255,255);
red =ImgLoader("/home/maah/workspace/lasttest2/src/red.png",255,255,255);
picpink=ImgLoader("/home/maah/workspace/lasttest2/src/pink.png",255,255,255);
pink=ImgLoader("/home/maah/workspace/lasttest2/src/pink.png",255,255,255);
blue=ImgLoader("/home/maah/workspace/lasttest2/src/blue.png",255,255,255);
orange=ImgLoader("/home/maah/workspace/lasttest2/src/orange.png",255,255,255);
intermission = LoadMusic("/home/maah/workspace/lasttest2/src/pacman_intermission.wav");
eatnut=LoadSound("/home/maah/workspace/lasttest2/src/pacman_chomp.wav");
pacdeath = LoadSound("/home/maah/workspace/lasttest2/src/pacman_death.wav");
n0 = ImgLoader("/home/maah/workspace/lastestprj/src/0.png",255,255,255);
n1 = ImgLoader("/home/maah/workspace/lastestprj/src/1.png",255,255,255);
					n2 =ImgLoader("/home/maah/workspace/lastestprj/src/2.png",255,255,255);
					n3 =ImgLoader("/home/maah/workspace/lastestprj/src/3.png",255,255,255);
					n4=ImgLoader("/home/maah/workspace/lastestprj/src/4.png",255,255,255);
					n5=ImgLoader("/home/maah/workspace/lastestprj/src/5.png",255,255,255);
					n6=ImgLoader("/home/maah/workspace/lastestprj/src/6.png",255,255,255);
					n7=ImgLoader("/home/maah/workspace/lastestprj/src/7.png",255,255,255);
					n8=ImgLoader("/home/maah/workspace/lastestprj/src/8.png",255,255,255);
					n9=ImgLoader("/home/maah/workspace/lastestprj/src/9.png",255,255,255);

PlayMusic(intermission,-1);
while(moving)
{
	second++;
	livey=0;
	if(finish2(way2))
			return ;










								SDL_FillRect(screen,NULL,BLACK);
								SDL_BlitSurface(map2,screen,0,0);
								if(second>=50)
								SDL_BlitSurface(red,screen,redx*50,redy*50);
								//SDL_BlitSurface(red,screen,redxi,redyj);
								if(second>=100)
								SDL_BlitSurface(pink,screen,pinkx*50,pinky*50);
								//SDL_BlitSurface(pink,screen,pinki,pinkj);
								if(second>=150)
								SDL_BlitSurface(orange,screen,orgx*50,orgy*50);

								SDL_Delay(100);
								/////////////////////////////////////////////////////////////score/////////////////
																	int j=score2;
																																		 		str[4] = (char) ( (j%10) + '0' );
																																		 		str[3] = (char) ( (j%100 - j%10)/10 + '0');
																																		 		str[2] = (char) ( (j%1000 - j%100)/100 + '0');
																																		 		str[1] = (char) ( (j%10000 - j%1000)/1000 + '0');
																																		 		str[0] = (char) ( (j%100000 - j%10000)/10000 + '0');



																																		 		for(int i=0;i<5;i++)
																																		 			switch(str[i]){
																																		 			case 0:
																																		 				SDL_BlitSurface(n0,screen,600+(i*25),400);
																																		 				break;
																																		 			case 1:
																																		 				SDL_BlitSurface(n1,screen,600+(i*25),400);
																																		 				break;
																																		 			case 2:
																																		 				SDL_BlitSurface(n2,screen,600+(i*25),400);
																																		 				break;
																																		 			case 3:
																																		 				SDL_BlitSurface(n3,screen,600+(i*25),400);
																																		 				break;
																																		 			case 4:
																																		 				SDL_BlitSurface(n4,screen,600+(i*25),400);
																																		 				break;
																																	 				case 5:
																																		 				SDL_BlitSurface(n5,screen,600+(i*25),400);
																																		 				break;
																																		 			case 6:
																																		 				SDL_BlitSurface(n6,screen,600+(i*25),400);
																																		 				break;
																																	 				case 7:
																																	 					SDL_BlitSurface(n7,screen,600+(i*25),400);
																																	 					break;
																																	 				case 8:
																																	 					SDL_BlitSurface(n8,screen,600+(i*25),400);
																																	 					break;
																																	 				case 9:
																																	 					SDL_BlitSurface(n9,screen,600+(i*25),400);
																																	 					break;
																																		 			}
								///////////////////////////////////////////////////////////////////////////////





								//if(paci%30 == 0 || pacj%30 ==0)
									SDL_BlitSurface(pacman1,screen,paci,pacj);
								/*else{ if(paci%40 == 0 || pacj%40 ==0)
									SDL_BlitSurface(pacman2,screen,paci,pacj);
										else if(paci%50 == 0 || pacj%50 ==0)
									SDL_BlitSurface(pacman3,screen,paci,pacj);}*/


//////////////////////print nut///////////////////////
			 for(int i=0;i<11;i++){
				 for(int j=0;j<10;j++){


					 if(way2[j][i]==1)
						 continue;


					 if(way2[j][i]==2)
						SDL_BlitSurface(nut,screen,i*50,j*50);


					 if(way2[j][i]==3) //daneye bozorg

						 SDL_BlitSurface(bignut,screen,i*50,j*50);
					// if( way2[pacy][pacx]!=1)
					// way2[pacy][pacx]=1;


	 			 }
	 		 }

			 way2[pacmany][pacmanx]=1;
			 SDL_Flip(screen);
////////////////////////////////////////////////////////////////pacmanmotion//////////////////////////////
			 if(flag!=flag2 && (paci%50==0) && (pacj%50 ==0) )
			 {
				 switch(flag)
				 {
				 case 1:
					 if(isnotblock2(pacmanx-1,pacmany) && (paci-vpaci>=0)&&(paci%50 ==0))
						 flag2=flag;break;
				 case 2:
					 if(isnotblock2(pacmanx+1,pacmany )&& (paci+vpaci<=500) && (paci%50==0))
						 flag2=flag;break;
				 case 3:if(isnotblock2(pacmanx,pacmany-1) &&  pacj-vpacj>=0 && (pacj%50 ==0) )
					 	 flag2=flag;break;
				 case 4:if(isnotblock2(pacmanx,pacmany+1) && pacj+vpacj<=450 && (pacj%50 ==0))
					 	 flag2=flag;break;

				 }
			 }
			 switch(flag2){
			 														case 1:cout<< "left2"<<endl;

			 														if(isnotblock2(pacmanx-1,pacmany) && (paci-vpaci>=0)){
			 															paci-=vpaci;
			 															cout<<paci<<" "<<pacj<<endl;
			 															if(paci%50 ==0)
			 																pacmanx=paci/50;
			 															cout<<pacmanx<<" "<<pacmany<<endl;



			 														}

			 														break;
			 														case 2: if(isnotblock2(pacmanx+1,pacmany )&& (paci+vpaci<=500)){

			 															paci+=vpaci;
			 															cout<<paci<<" "<<pacj<<endl;
			 															if(paci%50==0)
			 																pacmanx=paci/50;
			 															cout<<pacmanx<<" "<<pacmany<<endl;
			 															cout<< "right2"<<endl;
			 														}
			 														break;
			 														case 3:if(isnotblock2(pacmanx,pacmany-1) &&  pacj-vpacj>=0 ){

			 															pacj-=vpacj;
			 															cout<<paci<<" "<<pacj<<endl;
			 															if(pacj%50 ==0)
			 																pacmany= pacj/50;
			 															cout<<pacmanx<<" "<<pacmany<<endl;
			 															cout<< "down2"<<endl;
			 														}
			 														break;
			 														case 4:if(isnotblock2(pacmanx,pacmany+1) && pacj+vpacj<=450 ){

			 															pacj+=vpacj;
			 															cout<<paci<<" "<<pacj<<endl;
			 															if(pacj%50 ==0){
			 																pacmany=pacj/50;
			 															cout<<pacmanx<<" "<<pacmany<<endl;}
			 															cout<< "up2"<<endl;
			 														}
			 														break;
			 							}
							if(SDL_PollEvent(&event)){
														if(event.type==SDL_QUIT)
																moving=false;
															SDLKey keypressed = event.key.keysym.sym;

							switch(keypressed){

							case SDLK_ESCAPE:{ if(pausemenu1()==3)	{StopMusic();	return;}

							else cout<<"bargashtam"<<endl;
							break;}

							case SDLK_LEFT: {

								 if(isnotblock2(pacmanx-1,pacmany) == 1  && paci%50 ==0){
									flag=1;
									//pacman1=pacleft1;
									//pacman2= pacleft2;
									pacman1 = pacleft3;
								cout<< "left"<<endl;
								 }

											break;}


										case SDLK_RIGHT:{

											 if(isnotblock2(pacmanx+1,pacmany) == 1  && paci%50 ==0 ){
												flag=2;
										//		pacman1=pacright1;
											//	pacman2= pacright2;
												pacman1 = pacright3;
											cout<< "right"<<endl;

											 }
											break;}


										case SDLK_UP:{

										 if(isnotblock2(pacmanx,pacmany-1) == 1  && pacj%50 ==0 ){
											// pacman1=pacup1;
										//	pacman2= pacup2;
											pacman1 = pacup3;

												flag=3;
											cout<< "up"<<endl;

										 }
											break;}


										case SDLK_DOWN:{

											if(isnotblock2(pacmanx,pacmany+1) == 1  && pacj%50 ==0){
												flag=4;
											//	pacman1=pacdown1;
											//	pacman2= pacdown2;
												pacman1 = pacdown3;
											cout<< "down"<<endl;
											}

										break;}



							}

						}
/////////////////////////////////////////////////eat big nut//////////////////////////////////////////

							cout<<"timeblue"<<timeblue;
									  if((pacmanx==0 && pacmany==0 && way2[0][0]==3) || (pacmanx==10 && pacmany==0 && way2[10][0]==3) || (pacmanx==2 && pacmany==5 && way2[2][5]==3) || (pacmanx==10 && pacmany==5 && way2[10][5]==3))
									  {
										  cout<<"omade "<<endl; timeblue=1000;}


											 if(timeblue-955>0){
												 vpaci=vpacj=25;
												// cout<<"????????????"<<endl;
												 timeblue--;
													scape2(redx,redy,redxi,redyj);
													red=blue; pink=blue; orange=blue;
													scape2(pinkx,pinky,pinki,pinkj);
													scape2(orgx,orgy,orgi,orgj);

									 	 	if(pacmanx==redx && pacmany==redy){score2+=200; redx=2,redy=3;redxi=100;redyj=150; PlaySound(pacdeath,1);}
											if(pacmanx==pinkx && pacmany== pinky ){score2+=200;pinkx=2,pinky=3;pinki=100;pinkj=150;	PlaySound(pacdeath,1);}
											if(pacmanx==orgx && pacmany == orgy){score2+=200;orgx=2,orgy=3;orgi=100;orgy=300;	PlaySound(pacdeath,1);}
															 }
											 else{cout<<"else"<<endl;
												 red=picred;
												 orange=picorg;
												 pink=picpink;



											 	if(pacmanx==redx && pacmany==redy){live--; redx=redy=pinkx=pinky=orgx=orgy=3;second=0;pacmanx=2;pacmany=9;	int redxi=100;
														redyj=150; pinki=100; pinkj=150; orgi=100; orgj=150;paci=pacmanx*50;pacj=pacmany*50;}
												if(pacmanx==pinkx && pacmany== pinky ){paci=pacmanx*50;pacj=pacmany*50;
														live--;redyj=150; pinki=100; pinkj=150; orgi=100; orgj=150;redx=redy=pinkx=pinky=orgx=orgy=3;second=0;pacmanx=2;pacmany=9;}
												if(pacmanx==orgx && pacmany == orgy){paci=pacmanx*50;pacj=pacmany*50;
													redyj=150; pinki=100; pinkj=150; orgi=100; orgj=150;live--;redx=redy=pinkx=pinky=orgx=orgy=3;second=0;pacmanx=2;pacmany=9;}

											 }

											 for(int d=0;d<live;d++){
											 			SDL_BlitSurface(pacman1,screen,600,livey);
											 				livey+=60;
											 						}





//////////////////////////////////////////////////////////////////////

										if(	way2[pacmany][pacmanx]==2){
											score2+=50;
											PlaySound(eatnut,1);
											if(score1 != score2)
											score1=score2;}

										way2[pacmany][pacmanx]=1;

										int redghostarray[10][11];
											for(int i=0;i<10;i++){
												for(int j=0;j<11;j++){

														redghostarray[i][j]=110;

												}
											}	redghostarray[pacmany][pacmanx]=0;
												redghostmotion2(redghostarray);

												int pinkghostarray[10][11];
																for(int i=0;i<10;i++){
																	for(int j=0;j<11;j++){

																			pinkghostarray[i][j]=110;

																	}
																}
												switch(flag){
												case 1:pinkghostarray[pacmany][pinktarget2(pacmanx,pacmany,flag)]=0;break;
												case 2:pinkghostarray[pacmany][pinktarget2(pacmanx,pacmany,flag)]=0;break;
												case 3:pinkghostarray[pinktarget2(pacmanx,pacmany,flag)][pacmanx]=0;break;
												case 4:pinkghostarray[pinktarget2(pacmanx,pacmany,flag)][pacmanx]=0;break;
												}

												redghostmotion2(pinkghostarray);



													int orgghostarray[10][11];
														for(int i=0;i<10;i++){
															for(int j=0;j<11;j++){

																	orgghostarray[i][j]=110;

															}
																}
														orgghostarray[pacmany][pacmanx]=0;
														redghostmotion2(orgghostarray);
														dif=(orgx-pacmanx)*(orgx-pacmanx)+(orgy-pacmany)*(orgy-pacmany);

														for(int i=0;i<10;i++){
																for(int j=0;j<11;j++){

																//	cout<<	orgghostarray[i][j]<<setw(5);

																					}
																						cout<<endl;}



					////////////////////////////////////////////////////////////////////////////redghostmotion////////////////////////////////////////////////////////////////////*/

						if(second>=50){


						if(redghostarray[redy][redx-1]<redghostarray[redy][redx] && redx-1>=0 ){
						redxi-=10;cout<<redxi<<"redxi";
						if(redxi%50==0)
							--redx;
						cout<<"red position1: "<<redx<<" "<<redy<<redghostarray[redy][redx]<<endl;
									}
					if(redghostarray[redy+1][redx]<redghostarray[redy][redx]&& redy+1<10)
						{redyj+=10;cout<<redyj<<"redyj";
						if(redyj%50==0)
						++redy;
						cout<<"red position2: "<<redx<<" "<<redy<<redghostarray[redy][redx]<<endl;}
					if(redghostarray[redy-1][redx]<redghostarray[redy][redx] && redy-1>=0){
						redyj-=10;cout<<redyj<<"redyj";
						if(redyj%50==0)
						--redy;
					cout<<"red position3: "<<redx<<" "<<redy<<redghostarray[redy][redx]<<endl;}
					if(redghostarray[redy][redx+1]<redghostarray[redy][redx] && redx+1<11){
						redxi+=10;cout<<redxi<<"redxi";
						if(redxi%50==0)
						++redx;
					cout<<"red position4: "<<redx<<" "<<redy<<redghostarray[redy][redx]<<endl;}
					}
						//////////////////////////////////////////////////////pinkghostmotion/////////////////////////////////////////////
					if(second>=100){


																if(pinkghostarray[pinky][pinkx-1]<pinkghostarray[pinky][pinkx] && pinkx-1>=0 ){
																	pinki-=10;cout<<pinki<<"pinki"<<endl;
																	if(pinki%50==0)
																	pinkx--;
																		cout<<"pink position1: "<<pinkx<<" "<<pinky<<pinkghostarray[pinky][pinkx]<<endl;
																	}
																	if(pinkghostarray[pinky+1][pinkx]<pinkghostarray[pinky][pinkx]&& pinky+1<10)
																	{pinkj+=10;cout<<pinkj<<"pinkj"<<endl;
																		if(pinkj%50==0)
																		pinky++;
																	 cout<<"pink position2: "<<pinkx<<" "<<pinky<<pinkghostarray[pinky][pinkx]<<endl;}
																	if(pinkghostarray[pinky-1][pinkx]<pinkghostarray[pinky][pinkx] && pinky-1>=0)
																	{pinkj-=10;cout<<pinkj<<"pinkj"<<endl;
																	if(pinkj%50==0)
																		pinky--;
																	cout<<"pink position3: "<<pinkx<<" "<<pinky<<pinkghostarray[pinky][pinkx]<<endl;}
																	if(pinkghostarray[pinky][pinkx+1]<pinkghostarray[pinky][pinkx] && pinkx+1<11)
																	{pinki+=10;cout<<pinki<<"pinki"<<endl;
																	if(pinki%50==0)
																		pinkx++;cout<<"pink position4: "<<pinkx<<" "<<pinky<<pinkghostarray[pinky][pinkx]<<endl;}
						}
														////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
												if(second>=150){


																	if(dif>25){

																			scape2(orgx,orgy,orgi,orgj);
																	}
																	else{
																		if(orgghostarray[orgy][orgx-1]<orgghostarray[orgy][orgx] && orgx-1>=0 ){
																			orgi-=10;
																			if(orgi%50==0)orgx--;
																		cout<<"org position1: "<<orgx<<" "<<orgy<<orgghostarray[orgy][orgx]<<endl;
																	}
																	if(orgghostarray[orgy+1][orgx]<orgghostarray[orgy][orgx]&& orgy+1<10)
																	{orgj+=10;
																	if(orgj%50==0)orgy++; cout<<"org position2: "<<orgx<<" "<<orgy<<orgghostarray[orgy][orgx]<<endl;}
																	if(orgghostarray[orgy-1][orgx]<orgghostarray[orgy][orgx] && orgy-1>=0)
																	{orgj-=10;
																	if(orgj%50==0)orgy--;cout<<"org position3: "<<orgx<<" "<<orgx<<orgghostarray[orgy][orgx]<<endl;}
																	if(orgghostarray[orgy][orgx+1]<orgghostarray[orgy][orgx] && orgx+1<11)
																	{orgi+=10;
																	if(orgi%50==0)orgx++;cout<<"org position4: "<<orgx<<" "<<orgx<<orgghostarray[orgy][orgx]<<endl;}

																	}}
														/////////////////////////////////////////orangghostmotion//////////////////////////////////////////////////////////////////


















																													 SDL_Flip(screen);

																													 return ;
										}


























}

/////////////////////////////////////////////////////////////////////////////////
bool finish1(int way1[12][9])
						{
							for(int i=0;i<12;i++){
								for(int j=0;j<9;j++){
									if(way1[i][j]!=1 ||way1[i][j]!=0 )
										return false;



						}}
							return true;
						}
////////////////////////////////////////////////////////////////////////////////
bool finish2(int way1[10][11])
						{
							for(int i=0;i<10;i++){
								for(int j=0;j<11;j++){
									if(way1[i][j]!=1 ||way1[i][j]!=0 )
										return false;



						}}
							return true;
						}
///////////////////////////////////////////////////////////////////////////////
bool isnotblock1 (int pacmanx,int pacmany){
	int block1[12][9]={{0,2,2,2,2,2,2,2,0},{0,2,0,0,0,0,0,2,0},{3,2,2,2,0,2,2,2,3},{2,0,0,2,0,2,0,0,2},{2,2,2,2,2,2,2,2,2},{0,0,2,0,0,0,2,0,0},
					{3,2,2,0,0,0,2,2,3},{2,0,2,2,2,2,2,0,2},{2,0,0,2,0,2,0,0,2},{2,2,2,2,0,2,2,2,2},{0,2,0,0,0,0,0,2,0},{0,2,2,2,2,2,2,2,0}};

	if(block1[pacmany][pacmanx]==0)
		return false;
	return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int pinktarget1(int pacmanx,int pacmany ,int flage){
	switch(flage)

	{
	case 1:  {

		if(pacmanx-4<0){
			if(isnotblock1(0,pacmany))pacmanx=0;
			 	 else{
			 		 if(isnotblock1(1,pacmany))pacmanx=1;
			 		 else{
			 			 if(isnotblock1(2,pacmany))pacmanx=2;
			 			 else{
			 				 pacmanx=3;
			 			 }
			 		 }
			 	 }
		}



		else{
			if(isnotblock1(pacmanx-4,pacmany))pacmanx=pacmanx-4;
			else{
				if(isnotblock1(pacmanx-3,pacmany))pacmanx=pacmanx-3;
				else{
					if(isnotblock1(pacmanx-2,pacmany))pacmanx-=2;
					else{
						pacmanx-=1;
					}
				}
			}

		}


		}return pacmanx;

	case 2:	{
							if(pacmanx+4>8){
									if(isnotblock1(8,pacmany))pacmanx=8;
									else {
										if(isnotblock1(7,pacmany))pacmanx=7;
										else{
											if(isnotblock1(6,pacmany))pacmanx=6;
											else{
												pacmanx=5;
												}
											}
										}
												}

							else{
								if(isnotblock1(pacmanx+4,pacmany))pacmanx=pacmanx+4;
								else{
									if(isnotblock1(pacmanx+3,pacmany))pacmanx=pacmanx+3;
									else{
										if(isnotblock1(pacmanx+2,pacmany))pacmanx+=2;
										else{
											pacmanx+=1;
										}
									}
								}

									}

							}	return pacmanx;







	case 3:{
		if(pacmany-4<0){
				if(isnotblock1(pacmanx,0))pacmany=0;
					 	 else{
					 		 if(isnotblock1(pacmanx,1))pacmany=1;
					 		 	 else{
					 		 		if(isnotblock1(pacmanx,2))pacmany=2;
					 		 			else{
					 		 				pacmany=3;
					 			 	 	 	 }

					 		 	 }
					 	 	 }
		}

		else{
				if(isnotblock1(pacmanx,pacmany-4))pacmany-=4;
				else{
					if(isnotblock1(pacmanx,pacmany-3))pacmany-=3;
					else{
						if(isnotblock1(pacmanx,pacmany-2))pacmany-=2;
						else{
							pacmany-=1;
							}
						}
					}
				}






}return pacmany;






	case 4:{

		if(pacmany+4>12){
						if(isnotblock1(pacmanx,12))pacmany=12;
							else{
								if(isnotblock1(pacmanx,11))pacmany=11;
								else{
									if(isnotblock1(pacmanx,10))pacmany=10;
									else{
										pacmany=9;
									}
								}
							}


					}


					else{
						if(isnotblock1(pacmanx,pacmany+4))pacmany+=4;
						else{
							if(isnotblock1(pacmanx,pacmany+3))pacmany+=3;
							else{
								if(isnotblock1(pacmanx,pacmany+2))pacmany+=2;
								else{
									pacmany+=1;
									}
								}
							}
						}
					}return pacmany;



	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void scape1(int &ghostx,int &ghosty,int &ghosti,int &ghostj){
int tempx=ghostx;
int tempy=ghosty;
int flag2=0;


	do{
	//if(ghosti%50==0 || ghostj%50==0)
		flag2=rand()%4+1;

	switch(flag2){
		case 1:if(isnotblock1(ghostx-1,ghosty)&&  ghostx-1>=0)
		{ //ghosti-=10; if(ghosti%50==0)
			ghostx--;}break;

		case 2:if(isnotblock1(ghostx+1,ghosty)&& ghostx+1<9)
		{//ghosti+=10; if(ghosti%50==0)
			ghostx++;}break;
		case 3:if(isnotblock1(ghostx,ghosty-1)&& ghosty-1>=0){
		//	ghostj-=10; if(ghostj%50==0)
			ghosty--;}break;
		case 4:if(isnotblock1(ghostx,ghosty+1)&& ghosty+1<12){
			//ghostj+=10; if(ghostj%50==0)
			ghosty++;}break;
				}

}while( (tempx==ghostx && tempy==ghosty));
return;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pinkghostmotion(int pinkghostarray[12][9]){
	for(int k=0 ;k<107;k++){
	for(int i=0;i<12;i++){
		for(int j=0;j<9;j++){
			if(pinkghostarray[i][j]==k){
				if(isnotblock1(j,i-1) && pinkghostarray[i-1][j]==108)
					pinkghostarray[i-1][j]= k+1;

				if(pinkghostarray[i][j]==k){
					if(isnotblock1(j,i+1)&& pinkghostarray[i+1][j]==108)
						pinkghostarray[i+1][j]=k+1;
					if( isnotblock1(j+1,i)&&pinkghostarray[i][j+1]==108)
						pinkghostarray[i][j+1]=k+1;
					if(isnotblock1(j-1,i) && pinkghostarray[i][j-1]==108)
						pinkghostarray[i][j-1]=k+1;
				}
			}
		}
	}
}


return;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void redghostmotion(int redghostarray[12][9]){
	for(int k=0 ;k<107;k++){
			for(int i=0;i<12;i++){
				for(int j=0;j<9;j++){
					if(redghostarray[i][j]==k){
						if(isnotblock1(j,i-1) && redghostarray[i-1][j]==108)
							redghostarray[i-1][j]= k+1;

						if(redghostarray[i][j]==k){
							if(isnotblock1(j,i+1)&& redghostarray[i+1][j]==108)
								redghostarray[i+1][j]=k+1;
							if( isnotblock1(j+1,i)&& redghostarray[i][j+1]==108)
								redghostarray[i][j+1]=k+1;
							if(isnotblock1(j-1,i) && redghostarray[i][j-1]==108)
								redghostarray[i][j-1]=k+1;
						}
					}
				}
			}
		}


return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int showmenu( int a){
SDL_Surface *screen;
SDL_Surface *start;
SDL_Surface *help;
SDL_Surface *quit;
SDL_Surface *picmenudown;
SDL_Surface *picmenu1;
SDL_Surface *picmenu2;
SDL_Surface *picmenu3;
SDL_Surface *picmenu4;

Sound *biginning;
InitEngine(screen);
start=ImgLoader("/home/maah/workspace/lasttest3/src/STARTMENU.png",255,255,255);
help=ImgLoader("/home/maah/workspace/lasttest3/src/HELPMENU.png",255,255,255);
quit=ImgLoader("/home/maah/workspace/lasttest3/src/quitMENU.png",255,255,255);
picmenudown = ImgLoader("/home/maah/workspace/lasttest3/src/picmenu5.png",255,255,255);
picmenu1 = ImgLoader("/home/maah/workspace/lasttest3/src/menupic1.png",255,255,255);
picmenu2 = ImgLoader("/home/maah/workspace/lasttest3/src/menupic2.png",255,255,255);
picmenu3= ImgLoader("/home/maah/workspace/lasttest3/src/menupic3.png",255,255,255);
picmenu4 = ImgLoader("/home/maah/workspace/lasttest3/src/menupic4.png",255,255,255);
biginning = LoadSound("/home/maah/workspace/lasttest3/src/pacman_biginning.wav");

SDL_BlitSurface(start,screen,285,50);
SDL_BlitSurface(help,screen,285,170);
SDL_BlitSurface(quit,screen,285,290);
SDL_BlitSurface(picmenu1,screen,100,90);
SDL_BlitSurface(picmenu2,screen,600,290);
SDL_BlitSurface(picmenu3,screen,100,290);
SDL_BlitSurface(picmenu4,screen,600,90);
SDL_BlitSurface(picmenu4,screen,600,90);
SDL_Flip(screen);
		bool choice=true;


		while(choice)
		{PlaySound(biginning,1);

			SDL_BlitSurface(picmenudown,screen,300,500);
						Update();
						if(SDL_PollEvent(&event)){
														if(event.type==SDL_QUIT){
															choice=false; return 0;}
						SDLKey keypressed = event.key.keysym.sym;

						switch(keypressed){

						case SDLK_s: //start
							return 1;
						case SDLK_h: //help
							SDL_BlitSurface(screen,help,50,0);
							//SDL_Flip(screen);
							cout<<"helpppppppp"<<endl;
							 //help
							{return 5;}

						case SDLK_q://quit
								{choice =false; return 0;}



						}
					}


		}}
//////////////////////////////////////////////////////
int  pausemenu1(){

SDL_Surface *screen;
InitEngine(screen);
SDL_Surface *pausemenu;
SDL_Surface* pauserestart;
SDL_Surface* pausecountinue;
//SDL_Surface* pauseexit;
pausemenu=ImgLoader("/home/maah/workspace/lasttest3/src/MENUPAUSE.png",255,255,255);
//pauseexit=ImgLoader("/home/nazanin/Desktop/code/pausemenu/src/EXITPAUSE.png",255,255,255);
pausecountinue=ImgLoader("/home/maah/workspace/lasttest3/src/CONTINUEPAUSE.png",255,255,255);
bool running =true;
while(running){
cout<<"pausemenu"<<endl;
SDL_BlitSurface(pausecountinue,screen,285,150);
SDL_BlitSurface(pausemenu,screen,285,230);
//SDL_BlitSurface(pauseexit,screen,285,230);

SDL_Flip(screen);
Update();
if(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT)
				running=false; return 0;}
						SDLKey keypressed = event.key.keysym.sym;

switch(keypressed){


case SDLK_c:
return 0;
case SDLK_m:
return 3;
}
}

}
///////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
bool isnotblock2( int pacx,int pacy)
{
	int way2[10][11]={{3,2,2,2,2,0,0,2,2,2,3},
					{2,0,0,0,2,2,2,2,0,0,2},
					{2,2,2,2,2,0,2,0,0,2,2},
					{2,0,1,0,2,2,2,2,2,2,0},
					{2,0,0,0,0,2,0,0,2,0,0},            //matrix zamin
					{2,2,3,2,0,2,2,2,2,0,2},
					{0,2,0,2,0,2,0,0,2,2,2},
					{2,2,0,2,2,2,2,0,2,0,2},
					{2,0,0,0,2,0,2,2,2,0,2},
					{2,2,1,2,2,0,0,0,2,2,2}
					};
	if(way2[pacy][pacx] == 0)
				return false;


	return true;
}
///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int pinktarget2(int pacmanx,int pacmany ,int flage){
switch(flage)

{
case 1:  {

	if(pacmanx-4<0){
		if(isnotblock2(0,pacmany))pacmanx=0;
		 	 else{
		 		 if(isnotblock2(1,pacmany))pacmanx=1;
		 		 else{
		 			 if(isnotblock2(2,pacmany))pacmanx=2;
		 			 else{
		 				 pacmanx=3;
		 			 }
		 		 }
		 	 }
	}



	else{
		if(isnotblock2(pacmanx-4,pacmany))pacmanx=pacmanx-4;
		else{
			if(isnotblock2(pacmanx-3,pacmany))pacmanx=pacmanx-3;
			else{
				if(isnotblock2(pacmanx-2,pacmany))pacmanx-=2;
				else{
					pacmanx-=1;
				}
			}
		}

	}


	}return pacmanx;

case 2:	{
						if(pacmanx+4>8){
								if(isnotblock2(8,pacmany))pacmanx=8;
								else {
									if(isnotblock2(7,pacmany))pacmanx=7;
									else{
										if(isnotblock2(6,pacmany))pacmanx=6;
										else{
											pacmanx=5;
											}
										}
									}
											}

						else{
							if(isnotblock2(pacmanx+4,pacmany))pacmanx=pacmanx+4;
							else{
								if(isnotblock2(pacmanx+3,pacmany))pacmanx=pacmanx+3;
								else{
									if(isnotblock2(pacmanx+2,pacmany))pacmanx+=2;
									else{
										pacmanx+=1;
									}
								}
							}

								}

						}	return pacmanx;







case 3:{
	if(pacmany-4<0){
			if(isnotblock2(pacmanx,0))pacmany=0;
				 	 else{
				 		 if(isnotblock2(pacmanx,1))pacmany=1;
				 		 	 else{
				 		 		if(isnotblock2(pacmanx,2))pacmany=2;
				 		 			else{
				 		 				pacmany=3;
				 			 	 	 	 }

				 		 	 }
				 	 	 }
	}

	else{
			if(isnotblock2(pacmanx,pacmany-4))pacmany-=4;
			else{
				if(isnotblock2(pacmanx,pacmany-3))pacmany-=3;
				else{
					if(isnotblock2(pacmanx,pacmany-2))pacmany-=2;
					else{
						pacmany-=1;
						}
					}
				}
			}






}return pacmany;






case 4:{

	if(pacmany+4>12){
					if(isnotblock2(pacmanx,12))pacmany=12;
						else{
							if(isnotblock2(pacmanx,11))pacmany=11;
							else{
								if(isnotblock2(pacmanx,10))pacmany=10;
								else{
									pacmany=9;
								}
							}
						}


				}


				else{
					if(isnotblock2(pacmanx,pacmany+4))pacmany+=4;
					else{
						if(isnotblock2(pacmanx,pacmany+3))pacmany+=3;
						else{
							if(isnotblock2(pacmanx,pacmany+2))pacmany+=2;
							else{
								pacmany+=1;
								}
							}
						}
					}
				}return pacmany;



}
}
//////////////////////////////////////////////////////////////////////////////////////////
void scape2(int &ghostx,int &ghosty,int &ghosti,int &ghostj){
int tempx=ghostx;
int tempy=ghosty;
int flag2=0;


do{
//if(ghosti%50==0 || ghostj%50==0)
	flag2=rand()%4+1;

switch(flag2){
	case 1:if(isnotblock2(ghostx-1,ghosty)&&  ghostx-1>=0)
	{ //ghosti-=10; if(ghosti%50==0)
		ghostx--;}break;

	case 2:if(isnotblock2(ghostx+1,ghosty)&& ghostx+1<9)
	{//ghosti+=10; if(ghosti%50==0)
		ghostx++;}break;
	case 3:if(isnotblock2(ghostx,ghosty-1)&& ghosty-1>=0){
	//	ghostj-=10; if(ghostj%50==0)
		ghosty--;}break;
	case 4:if(isnotblock2(ghostx,ghosty+1)&& ghosty+1<12){
		//ghostj+=10; if(ghostj%50==0)
		ghosty++;}break;
			}

}while( (tempx==ghostx && tempy==ghosty));
return;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pinkghostmotion2(int pinkghostarray[12][9]){
for(int k=0 ;k<109;k++){
for(int i=0;i<10;i++){
	for(int j=0;j<11;j++){
		if(pinkghostarray[i][j]==k){
			if(isnotblock2(j,i-1) && pinkghostarray[i-1][j]==110)
				pinkghostarray[i-1][j]= k+1;

			if(pinkghostarray[i][j]==k){
				if(isnotblock2(j,i+1)&& pinkghostarray[i+1][j]==110)
					pinkghostarray[i+1][j]=k+1;
				if( isnotblock2(j+1,i)&&pinkghostarray[i][j+1]==110)
					pinkghostarray[i][j+1]=k+1;
				if(isnotblock2(j-1,i) && pinkghostarray[i][j-1]==110)
					pinkghostarray[i][j-1]=k+1;
			}
		}
	}
}
}


return;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void redghostmotion2(int redghostarray[10][11]){
for(int k=0 ;k<109;k++){
		for(int i=0;i<10;i++){
			for(int j=0;j<11;j++){
				if(redghostarray[i][j]==k){
					if(isnotblock2(j,i-1) && redghostarray[i-1][j]==110)
						redghostarray[i-1][j]= k+1;

					if(redghostarray[i][j]==k){
						if(isnotblock2(j,i+1)&& redghostarray[i+1][j]==110)
							redghostarray[i+1][j]=k+1;
						if( isnotblock2(j+1,i)&& redghostarray[i][j+1]==110)
							redghostarray[i][j+1]=k+1;
						if(isnotblock2(j-1,i) && redghostarray[i][j-1]==110)
							redghostarray[i][j-1]=k+1;
					}
				}
			}
		}
	}


return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


