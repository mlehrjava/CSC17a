#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "character.h"
#include "monsters.h"

class game
{
    private:

         static const int COLS=21;
         static const int ROWS=21;
    public:

        game();
        void splash();
        void gamestart(map,int,pStat *,monSta *, char [][COLS]);
        character gameInit(character, pStat *);
        monSta createMon(monSta *);
        void printHP(pStat *, monSta *);
        void gameOver(pStat *,monSta *);
        void printStat(pStat *, monSta *);


};

#endif // GAME_H
