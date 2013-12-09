#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <cmath>


using namespace std;


#include "map.h"

map::map()
{
    //ctor
}
//int wmain(){}

int map::fill2DArray(char a[][COLS], int ROWS){

        srand(static_cast<unsigned int>(time(0)));
    const int MON=4;
   int x, y;
   int monst, treas;
   monst=1;
   treas=20;
   int playx, playY;
   int hPot, strPot, intPot;
   hPot = 2;
   strPot = 2;
   intPot = 2;
   playx =1;
   playY=1;

	for(int row=0;row<ROWS;row++){

		for(int col=0;col<COLS;col++){

			a[row][col]=32;
			a[row][0]=186;
		    a[0][0]=201;
		    a[0][col]=205;
		    a[0][20]=187;
		    a[row][20]=186;
		    a[20][col]=205;
		    a[20][0]=200;
		    a[20][20]=188;

		}
	}
	for(int i =0;i<treas;i++){
                    x = (rand()%19) +1;
                    y = (rand()%19) + 1;
                      a[x][y]='T';
                    }
    for(int i =0;i<hPot;i++){
                    x = (rand()%19) +1;
                    y = (rand()%19) + 1;
                      a[x][y]='H';
                    }
    for(int i =0;i<strPot;i++){
                    x = (rand()%19) +1;
                    y = (rand()%19) + 1;
                      a[x][y]='S';
                    }
    for(int i =0;i<intPot;i++){
                    x = (rand()%19) +1;
                    y = (rand()%19) + 1;
                      a[x][y]='I';
                    }
   //Initialized the Character and Monster locations
    a[19][19]='M';
    a[playx][playY]='P';

}
void map::print2D(map x, char a[][COLS], int ROWS){
    for(int row=0;row<ROWS;row++){
		for(int col=0;col<COLS;col++){
			cout<<a[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int map::charMov(char a[][COLS],int ROWS, char inp, int count, int x, int y){

    switch(inp){

            case 'w':{


                a[x][y]=32;
                a[x][y-=count]='P';
                break;

            }
            case 'e':{
                a[x][y]=32;
                a[x][y+=count] = 'P';

                break;

            }
            case 'n':{
                a[x][y]=32;
                a[x-=count][y]= 'P';
                break;

            }
            case 's':{

                a[x][y]= 32;
                a[x+=count][y] = 'P';

                break;
            }


    return count, x, y;

    }
}
int map::monMov(char a[][COLS],int ROWS, char inp, int count,int x,int y){

    switch(inp){

            case 'e':{


                a[x][y]=32;
                a[x][y-=count]='M';
                break;

            }
            case 'w':{
                a[x][y]=32;
                a[x][y+=count] = 'M';

                break;

            }
            case 's':{
                a[x][y]=32;
                a[x-=count][y]= 'M';
                break;

            }
            case 'n':{

                a[x][y]= 32;
                a[x+=count][y] = 'M';

                break;
            }


    return count, x, y;

    }

}
float map::getDist(int x, int y, int monx, int mony, float disTot){


    float dist;
    float difx, dify;
    difx=monx-x;
    dify=mony-y;
    difx=pow(difx,2);
    dify=pow(dify,2);
    dist=difx+dify;
    disTot=sqrt(dist);
   // cout<<"Distance : "<<disTot<<endl;
    return disTot;
}
