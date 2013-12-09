/*
  Author: David Patrick
  Date: 12/8/13
  Purpose: A turn based strategy game
*/

using namespace std;

#include "character.h"
#include "monsters.h"
#include "map.h"
#include "game.h"


//Declare Global Variables

const int COLS=21;
const int ROWS=21;


int main(int argc, char *argv[])
{

    //Initialize the game
    game game1;
    game1.splash();

    //Creates the players
    character player1;
    pStat *stats = new pStat;
    game1.gameInit(player1, stats);
    monSta *monstat = new monSta;
    game1.createMon(monstat);


    //Creates the map
    char mapvar[ROWS][COLS];
    map map1;
    map1.fill2DArray(mapvar, ROWS);

    //Prints the Pre-Game Information
     map1.print2D(map1,mapvar, ROWS);
     game1.printStat(stats, monstat);

     //Starts the game
     game1.gamestart(map1,ROWS,stats, monstat,mapvar);
     game1.gameOver(stats,monstat);

     delete monstat;
     delete stats;

    return 0;
}
