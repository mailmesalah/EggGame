#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

void eraseEgg(int,int);
void drawEgg(int,int);
void addEgg(int [],int [],int);
void playGame(){
	int gd=DETECT,gm;
	int i=0;
	int eggX[100],eggY[100];
	int numOfEggs=0;
	int lastNoOfEggs=0;
	int decrementTime=0;

	initgraph(&gd,&gm,"c:\\tc\\bgi");
	randomize();
	while(1){
		i=0;
		while(i<numOfEggs){

			eraseEgg(eggX[i],eggY[i]-2);
			drawEgg(eggX[i],eggY[i]);
			eggY[i]+=2;
			if(eggY[i]>getmaxy()-100){
			//If Egg reaches down reset x and y
			//If Egg touches Bucket then also reset and increment point
				eggX[i]=random(getmaxx()-100);//Screen Width
				eggY[i]=20;
			}
			++i;
		}
		decrementTime=clock()/100*5;
		if(lastNoOfEggs<decrementTime){
			addEgg(eggX,eggY,numOfEggs++);
		}
		lastNoOfEggs=decrementTime;
		delay(40-decrementTime);
	}
}

void addEgg(int eggX[100],int eggY[100],int index){

	eggX[index]=random(getmaxx()-100);//Screen Width
	eggY[index]=20;
}

void eraseEgg(int x,int y){
	setcolor(BLACK);
	setfillstyle(0,BLACK);
	fillellipse(x,y,30,50);
}

void drawEgg(int x,int y){
	setcolor(WHITE);
	setlinestyle(0,0,1);
	setfillstyle(SOLID_FILL,WHITE);
	ellipse(x,y,0,180,18,40);
	ellipse(x,y,180,360,18,30);
	floodfill(x,y,WHITE);
}

void pauseGame(){

}
void endGame(){

}

void main(){
	int input;

	while(1){
		clrscr();
		gotoxy(100,200);
		printf("\t!!!Egg Game!!!\n");
		printf("\t1. Start Game\n");
		printf("\t2. Pause Game\n");
		printf("\t3. Exit Game\n");
		scanf("\t%d",&input);
		switch(input){
			case 1 :
				playGame();
				break;
			case 2 :
				pauseGame();
				break;
			case 3 :
			default:
				endGame();
				exit(0);
		}

	}

}
