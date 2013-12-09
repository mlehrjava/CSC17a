#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <cmath>
using namespace std;


#include "game.h"
game::game()
{
    //ctor
}
void game::splash(){
    cout<<"                *                                             *"<<endl;
    cout<<"                *                                             *"<<endl;
    cout<<"                *                Arena Masters                *"<<endl;
    cout<<"                *                                             *"<<endl;
    cout<<"                *                                             *"<<endl<<endl;
    cout<<"                     From the dawn of time we came, moving"<<endl;
    cout<<"                  silently down through the centuries. Living"<<endl;
    cout<<"                  many secret lives, struggling to reach the"<<endl;
    cout<<"                    time of the gathering, when the few who"<<endl;
    cout<<"                  remain will battle to the last. No one has"<<endl;
    cout<<"                  ever known we were among you.....until now."<<endl<<endl<<endl;

    cout<<"                       <Press any key to continue...>"<<endl;
    cin.ignore();
    system("cls");
}
void game::gamestart(map map1,int, pStat *stats, monSta *mstats, char a[][COLS]){

    srand(static_cast<unsigned int>(time(0)));
    char mov;
    char side;
    side =186;
    char top;
    top = 205;
    int count=1;
    int moncount=1;
    int dead = 0;
    int x =1;
    int y =1;
    int monx = 19;
    int mony = 19;
    int dec, atdec;
    int mondec, monat;
    if((stats->hitP>dead) && (mstats->hitP >dead)){
    do{
        float disTot;
        map1.print2D( map1,a,ROWS);
         printHP(stats,mstats);
          disTot = map1.getDist(x,y,monx,mony,disTot);
        cout<<"Distance : "<<disTot<<endl;
        cout<<"Press 1 to attack, 2 for movement: ";

        cin>>dec;
        switch(dec){

                //Decision for the attack phase
                case 1: {
                        cout<<endl;
                         cout<<endl;
                        cout<<"Enter 1 for Melee, and 2 for Ranged"<<endl;
                        cout<<"Melee : "<<stats->meleeAt<<endl;
                        cout<<"Ranged: "<<stats->rangeAt<<endl;
                        cout<<"Choose Wisely: ";
                        cin>>atdec;
                        switch(atdec){

                            //Decision for Melee Attack
                            case 1: {
                                //Warrior Melee
                                if(stats->plclass==1){
                                    if(disTot<4){
                                        mstats->hitP = mstats->hitP - (stats->strength + 3);
                                        cout<<"You slash your enemy for "<<(stats->strength + 3)<<" damage."<<endl;
                                        _sleep(4000);
                                    }
                                    else if(disTot>4){
                                        cout<<"Your opponent is out of range."<<endl;
                                        _sleep(4000);
                                    }
                                }
                                //Mage Melee
                                else if(stats->plclass==2){
                                    if(disTot<3){
                                        mstats->hitP = mstats->hitP - 4;
                                        cout<<"You hit you enemy with your staff for 4 damage."<<endl;
                                        _sleep(4000);
                                    }
                                    else if(disTot>3){
                                        cout<<"Your opponent is out of range."<<endl;
                                        _sleep(4000);
                                    }
                                }
                                //Rogue Melee
                                else if(stats->plclass==3){
                                    if(disTot<3){
                                        mstats->hitP = mstats->hitP - (stats->balance + 2);
                                        cout<<"You stab your enemy for "<<(stats->balance + 2)<<" damage."<<endl;
                                        _sleep(4000);
                                    }
                                    else if(disTot>3){
                                        cout<<"Your opponent is out of range."<<endl;
                                        _sleep(4000);
                                    }
                                }
                                //Priest Melee
                                else if(stats->plclass==4){
                                    if(disTot<2){
                                        mstats->hitP = mstats->hitP - stats->strength;
                                        cout<<"You hit your enemy with a bible for "<<stats->strength<<" damage."<<endl;
                                        _sleep(4000);
                                    }
                                    else if(disTot>2){
                                        cout<<"Your opponent is out of range."<<endl;
                                        _sleep(4000);
                                    }
                                }

                            }
                            //Decision for Ranged Attack
                            case 2: {
                                //Warrior Ranged
                                if(stats->plclass==1){
                                    if(disTot<15){
                                        mstats->hitP = mstats->hitP - stats->chari;
                                        cout<<"You throw an axe at your enemy for "<<stats->chari<<" damage."<<endl;
                                        _sleep(4000);
                                    }
                                    else if(disTot>15){
                                        cout<<"Your opponent is out of range."<<endl;
                                        _sleep(4000);
                                    }
                                }
                                //Mage Ranged
                                else if(stats->plclass==2){
                                    if(disTot<15){
                                        mstats->hitP=mstats->hitP - (stats->intel);
                                        cout<<"You cast a frost bolt for "<<(stats->intel)<<" damage."<<endl;
                                        _sleep(4000);
                                    }
                                    else if(disTot>15){
                                        cout<<"Your opponent is out of range."<<endl;
                                        _sleep(4000);
                                    }
                                }
                                //Rogue Ranged
                                else if(stats->plclass==3){
                                    if(disTot<15){
                                        mstats->hitP=mstats->hitP - (stats->dexterity);
                                        cout<<"You shoot an arrow at your enemy for "<<(stats->dexterity)<<" damage."<<endl;
                                    }
                                    else if(disTot<15){
                                        cout<<"Your opponent is out of range."<<endl;
                                        _sleep(4000);
                                    }
                                }
                                //Priest Heal
                                else if(stats->plclass==4){
                                    stats->hitP = stats->hitP + stats->intel;
                                    cout<<"You heal yourself for "<<(stats->hitP - (stats->hitP + stats->intel)) * -1 <<" hit points."<<endl;
                                    _sleep(4000);
                                }
                            }

                        }

                        break;

                }
                //Decision for the movement phase
                            case 2: {
                                cout<<"It's your move gladiator(n,s,e,w): ";
                                cin>>mov;

                    if(mov == 'w'){
                        if((a[x][y-1]=='T')||(a[x][y-1]==side)){
                                do{
                            a[x][y++];
                            cout<<"You can't move there."<<endl;
                            _sleep(4000);
                            break;
                                }while((a[x][y-1]=='T')||(a[x][y-1]==side));
                        }
                        else if(a[x][y-1]=='H'){
                            stats->hitP+=10;
                            cout<<"You gained 10 health points."<<endl;
                            _sleep(4000);
                            break;
                        }
                        else if(a[x][y-1]=='S'){
                            stats->strength+=10;
                            cout<<"You gained 10 strength."<<endl;
                            _sleep(4000);
                            break;
                        }
                          else if(a[x][y-1]=='I'){
                            stats->intel+=10;
                            cout<<"You gained 10 intelligence."<<endl;
                            _sleep(4000);
                            break;
                        }

                    }
                     else if(mov == 'e'){
                        if((a[x][y+1]=='T')||a[x][y+1]==side){
                                do{
                            a[x][y--];
                            cout<<"You can't move there."<<endl;
                            _sleep(4000);
                            break;
                                }while((a[x][y+1]=='T')||(a[x][y+1]==side));
                        }
                         else if(a[x][y+1]=='H'){
                            stats->hitP+=10;
                            cout<<"You gained 10 health points."<<endl;
                            _sleep(4000);
                            break;
                        }
                         else if(a[x][y+1]=='S'){
                            stats->strength+=10;
                            cout<<"You gained 10 strength."<<endl;
                            _sleep(4000);
                            break;
                        }
                           else if(a[x][y+1]=='I'){
                            stats->intel+=10;
                            cout<<"You gained 10 intelligence."<<endl;
                            _sleep(4000);
                            break;
                        }
                    }
                     else if(mov == 'n'){
                        if((a[x-1][y]=='T')||a[x-1][y]==top){
                                do{
                            a[x++][y];
                            cout<<"You can't move there."<<endl;
                            _sleep(4000);
                            break;
                                }while((a[x-1][y]=='T')||(a[x-1][y]==top));
                        }
                          else if(a[x-1][y]=='H'){
                            stats->hitP+=10;
                            cout<<"You gained 10 health points."<<endl;
                            _sleep(4000);
                            break;
                        }
                         else if(a[x-1][y]=='S'){
                            stats->strength+=10;
                            cout<<"You gained 10 strength."<<endl;
                            _sleep(4000);
                            break;
                        }
                            else if(a[x-1][y]=='I'){
                            stats->intel+=10;
                            cout<<"You gained 10 intelligence."<<endl;
                            _sleep(4000);
                            break;
                        }
                    }
                     else if(mov == 's'){
                        if((a[x+1][y]=='T')||(a[x+1][y]==top)){
                                do{
                            a[x--][y];
                            cout<<"You can't move there."<<endl;
                            _sleep(4000);
                            break;
                                }while((a[x+1][y]=='T')||(a[x+1][y]==top));
                        }
                           else if(a[x+1][y]=='H'){
                            stats->hitP+=10;
                            cout<<"You gained 10 health points."<<endl;
                            _sleep(4000);
                            break;
                        }
                          else if(a[x+1][y]=='S'){
                            stats->strength+=10;
                            cout<<"You gained 10 strength."<<endl;
                            _sleep(4000);
                            break;
                        }
                         else if(a[x+1][y]=='I'){
                            stats->intel+=10;
                            cout<<"You gained 10 intelligence."<<endl;
                            _sleep(4000);
                            break;
                        }
                    }

                    map1.charMov(a,ROWS,mov, count,x,y);

                    if(mov=='e'){
                        y++;
                    }
                    else if(mov=='s'){
                        x++;
                    }
                    else if(mov=='n'){
                        x--;
                    }

                    else if(mov=='w'){
                        y--;
                    }
                        break;

                            }
        }
        mondec = (rand()%2) +1;
        if(disTot<15){
            switch(mondec){
            case 1: {
                if(disTot<5){
                     monat = (rand()%2) + 1;
                switch(monat){


                     //Decision for Melee Attack
                            case 1: {
                                //Warrior Melee
                                if(mstats->plclass==1){
                                    if(disTot<4){
                                        stats->hitP = stats->hitP - (mstats->strength + 3);
                                        cout<<"Your opponent slashes you for "<<(mstats->strength + 3)<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot>4){
                                        cout<<"Your opponent attempted to slash, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Mage Melee
                                else if(mstats->plclass==2){
                                    if(disTot<3){
                                        stats->hitP = stats->hitP - 4;
                                        cout<<"Your opponent hits you with their staff for 4 damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot>3){
                                        cout<<"Your opponent attempted to hit you with their staff, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Rogue Melee
                                else if(mstats->plclass==3){
                                    if(disTot<3){
                                        stats->hitP = stats->hitP - (mstats->balance + 2);
                                        cout<<"Your opponent stabs with for "<<(mstats->balance + 2)<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot>3){
                                        cout<<"Your opponent attempted to stab, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Priest Melee
                                else if(mstats->plclass==3){
                                    if(disTot<2){
                                        stats->hitP = stats->hitP - mstats->strength;
                                        cout<<"Your opponent hits you with a bible for "<<mstats->strength<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot>2){
                                        cout<<"Your opponent attempted to hit you with a bible, but missed... as they should have."<<endl;
                                        _sleep(3000);
                                    }
                                }

                            }
                            //Decision for Ranged Attack
                            case 2: {
                                //Warrior Ranged
                                if(mstats->plclass==1){
                                    if(disTot<15){
                                        mstats->hitP = stats->hitP - mstats->chari;
                                        cout<<"Your opponent throws an axe at you for "<<mstats->chari<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot>15){
                                        cout<<"Your opponent attempted to throw an axe, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Mage Ranged
                                else if(mstats->plclass==2){
                                    if(disTot<15){
                                        stats->hitP=stats->hitP - (mstats->intel);
                                        cout<<"Your opponent casts a frost bolt for "<<(mstats->intel)<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot>15){
                                        cout<<"Your opponent attempted to cast frost bolt, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Rogue Ranged
                                else if(mstats->plclass==3){
                                    if(disTot<15){
                                        stats->hitP=stats->hitP - (mstats->dexterity);
                                        cout<<"Your opponent shoots an arrow at you for "<<(mstats->dexterity)<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot<15){
                                        cout<<"Your opponent attempted to shoot an arrow, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Priest Heal
                                else if(mstats->plclass==4){
                                    mstats->hitP = mstats->hitP + mstats->intel;
                                    cout<<"Your opponent healed themselves by "<<mstats->hitP<<"hit points."<<endl;
                                    _sleep(3000);
                                }
                            }

                        }
                    //This is the end of the first if statements
                }
               else if(disTot>5){
                     //Warrior Ranged
                                if(mstats->plclass==1){
                                    if(disTot<15){
                                        mstats->hitP = stats->hitP - mstats->chari;
                                        cout<<"Your opponent throws an axe at you for "<<mstats->chari<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot>15){
                                        cout<<"Your opponent attempted to throw an axe, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Mage Ranged
                                else if(mstats->plclass==2){
                                    if(disTot<15){
                                        stats->hitP=stats->hitP - (mstats->intel);
                                        cout<<"Your opponent casts a frost bolt for "<<(mstats->intel)<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot>15){
                                        cout<<"Your opponent attempted to cast frost bolt, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Rogue Ranged
                                else if(mstats->plclass==3){
                                    if(disTot<15){
                                        stats->hitP=stats->hitP - (mstats->dexterity);
                                        cout<<"Your opponent shoots an arrow at you for "<<(mstats->dexterity)<<" damage."<<endl;
                                        _sleep(3000);
                                    }
                                    else if(disTot<15){
                                        cout<<"Your opponent attempted to shoot an arrow, but missed."<<endl;
                                        _sleep(3000);
                                    }
                                }
                                //Priest Heal
                                else if(mstats->plclass==4){
                                    mstats->hitP = mstats->hitP + mstats->intel;
                                    cout<<"Your opponent healed themselves by "<<mstats->hitP<<"hit points."<<endl;
                                    _sleep(3000);
                                }
                //This is the end of the second if statement
               }

                        break;
            }



            case 2: {
                    if(mov == 'e'){
                        if((a[monx][mony-1]=='T')||(a[monx][mony-1]==side)){
                                do{
                           a[monx][mony++];
                           cout<<"Your opponent attempted to move, however ran into an obstacle."<<endl;
                            break;
                                }while((a[monx][mony-1]=='T')||(a[monx][mony-1]==side));
                        }
                        else if(a[monx][mony-1]=='H'){
                            mstats->hitP+=10;
                            cout<<"Your opponent gained 10 health points."<<endl;
                            _sleep(4000);
                            break;
                        }
                        else if(a[monx][mony-1]=='S'){
                            mstats->strength+=10;
                            cout<<"Your opponent gained 10 strength."<<endl;
                            _sleep(4000);
                            break;
                        }
                          else if(a[monx][mony-1]=='I'){
                            mstats->intel+=10;
                            cout<<"Your opponent gained 10 intelligence."<<endl;
                            _sleep(4000);
                            break;
                        }
                    }
                     else if(mov == 'w'){
                        if((a[monx][mony+1]=='T')||a[monx][mony+1]==side){
                                do{
                            a[monx][mony--];
                            cout<<"Your opponent attempted to move, however ran into an obstacle."<<endl;
                            break;
                                }while((a[monx][mony+1]=='T')||(a[monx][mony+1]==side));
                        }
                        else if(a[monx][mony+1]=='H'){
                            mstats->hitP+=10;
                            cout<<"Your opponent gained 10 health points."<<endl;
                            _sleep(4000);
                            break;
                        }
                        else if(a[monx][mony+1]=='S'){
                            mstats->strength+=10;
                            cout<<"Your opponent gained 10 strength."<<endl;
                            _sleep(4000);
                            break;
                        }
                          else if(a[monx][mony+1]=='I'){
                            mstats->intel+=10;
                            cout<<"Your opponent gained 10 intelligence."<<endl;
                            _sleep(4000);
                            break;
                        }

                    }
                     else if(mov == 's'){
                        if((a[monx-1][mony]=='T')||a[monx-1][mony]==top){
                                do{
                            a[monx++][mony];
                            cout<<"Your opponent attempted to move, however ran into an obstacle."<<endl;

                            break;
                                }while((a[monx-1][mony]=='T')||(a[monx-1][mony]==top));
                        }
                        else if(a[monx-1][mony]=='H'){
                            mstats->hitP+=10;
                            cout<<"Your opponent gained 10 health points."<<endl;
                            _sleep(4000);
                            break;
                        }
                        else if(a[monx-1][mony]=='S'){
                            mstats->strength+=10;
                            cout<<"Your opponent gained 10 strength."<<endl;
                            _sleep(4000);
                            break;
                        }
                          else if(a[monx-1][mony]=='I'){
                            mstats->intel+=10;
                            cout<<"Your opponent gained 10 intelligence."<<endl;
                            _sleep(4000);
                            break;
                        }
                    }
                     else if(mov == 'n'){
                        if((a[monx+1][mony]=='T')||(a[monx+1][mony]==top)){
                                do{
                            a[monx--][mony];
                            cout<<"Your opponent attempted to move, however ran into an obstacle."<<endl;
                            break;
                                }while((a[monx+1][mony]=='T')||(a[monx+1][mony]==top));
                        }
                        else if(a[monx+1][mony]=='H'){
                            mstats->hitP+=10;
                            cout<<"Your opponent gained 10 health points."<<endl;
                            _sleep(4000);
                            break;
                        }
                        else if(a[monx+1][mony]=='S'){
                            mstats->strength+=10;
                            cout<<"Your opponent gained 10 strength."<<endl;
                            _sleep(4000);
                            break;
                        }
                          else if(a[monx+1][mony]=='I'){
                            mstats->intel+=10;
                            cout<<"Your opponent gained 10 intelligence."<<endl;
                            _sleep(4000);
                            break;
                        }
                    }

                    if(mov=='w'){
                        mony++;
                        cout<<"Your opponent moves east of their location."<<endl;
                        _sleep(3000);
                    }
                    else if(mov=='n'){
                        monx++;
                        cout<<"Your opponent moves south of their location."<<endl;
                        _sleep(3000);
                    }
                    else if(mov=='s'){
                        monx--;
                        cout<<"Your opponent north of their location."<<endl;
                        _sleep(3000);
                    }
                    else if(mov=='e'){
                        mony--;
                        cout<<"You opponent moves west of their location."<<endl;
                        _sleep(3000);
                    }
                    map1.monMov(a,ROWS,mov,moncount,monx,mony);

            }
            }

        }
        else if(disTot>=15){


            if(mov == 'e'){
                        if((a[monx][mony-1]=='T')||(a[monx][mony-1]==side)){
                                do{
                           a[monx][mony++];
                           cout<<"Your opponent attempted to move, however ran into an obstacle."<<endl;
                           _sleep(4000);
                            break;
                                }while((a[monx][mony-1]=='T')||(a[monx][mony-1]==side));
                        }

                    }
                     else if(mov == 'w'){
                        if((a[monx][mony+1]=='T')||a[monx][mony+1]==side){
                                do{
                            a[monx][mony--];
                            cout<<"Your opponent attempted to move, however ran into an obstacle."<<endl;
                           _sleep(4000);
                            break;
                                }while((a[monx][mony+1]=='T')||(a[monx][mony+1]==side));
                        }
                    }
                     else if(mov == 's'){
                        if((a[monx-1][mony]=='T')||a[monx-1][mony]==top){
                                do{
                            a[monx++][mony];
                            cout<<"Your opponent attempted to move, however ran into an obstacle."<<endl;
                           _sleep(4000);
                            break;
                                }while((a[monx-1][mony]=='T')||(a[monx-1][mony]==top));
                        }
                    }
                     else if(mov == 'n'){
                        if((a[monx+1][mony]=='T')||(a[monx+1][mony]==top)){
                                do{
                            a[monx--][mony];
                            cout<<"Your opponent attempted to move, however ran into an obstacle."<<endl;
                           _sleep(4000);
                            break;
                                }while((a[monx+1][mony]=='T')||(a[monx+1][mony]==top));
                        }
                    }

                    map1.monMov(a,ROWS,mov,moncount,monx,mony);
                    if(mov=='w'){
                        mony++;
                        cout<<"Your opponent moves east of their location."<<endl;
                        _sleep(4000);
                    }
                    else if(mov=='n'){
                        monx++;
                        cout<<"Your opponent moves south of their location."<<endl;
                        _sleep(4000);
                    }
                    else if(mov=='s'){
                        monx--;
                        cout<<"Your opponent north of their location."<<endl;
                        _sleep(4000);
                    }
                    else if(mov=='e'){
                        mony--;
                        cout<<"You opponent moves west of their location."<<endl;
                        _sleep(4000);
                    }

        }


        system("cls");




    }while((stats->hitP>dead) && (mstats->hitP >dead));
    }


}
monSta game::createMon(monSta *monstat){


    monsters mon1;
    int clas;

    mon1.monRace(monstat);
    mon1.monClass(clas, monstat);



    return *monstat;
}
character game::gameInit(character player1, pStat *stats){


    //Initialize all variables
    string pName; //Name for Character
    string cnClass; //Name of Class
    int pClass; //Class of character

	//system("cls");
    player1.getRace(stats);
    player1.getClass(pClass, stats);

    return player1;
}
void game::printHP(pStat *stats, monSta *mstats){
    cout<<"Your Health : "<<stats->hitP<<"        Your Enemy's Health: "<<mstats->hitP<<endl;
}
void game::gameOver(pStat *stats, monSta *mstats){
    system("cls");
    cout<<endl;
    cout<<"Game Over!"<<endl;
    if((stats->hitP)<(mstats->hitP)){
       cout<<"Your enemy is victorious, with "<<mstats->hitP<<" health."<<endl;
        cout<<"There can only be one..."<<endl;
       }
    else if((stats->hitP)>(mstats->hitP)){
            cout<<"You are victorious, with "<<stats->hitP<<" health."<<endl;
            cout<<"There can only be one..."<<endl;
            }

}
void game::printStat(pStat *stats, monSta *mstats){

        //Outputs Stats and names, respectively
    cout<<"Your Stats                Your Enemy"<<endl;
    cout<<endl<<endl;

    cout<<"Race: "<<stats->rName<<"               Race: "<<mstats->rName<<endl;
    cout<<"Class: "<<stats->cusclass<<"            Class: "<<mstats->cusclass<<endl;
    cout<<"Hit Points: "<<stats->hitP<<"            Hit Points: "<<mstats->hitP<<endl;
    cout<<"Strength: "<<stats->strength<<"               Strength: "<<mstats->strength<<endl;
    cout<<"Intellect: "<<stats->intel<<"              Intellect: "<<mstats->intel<<endl;
    cout<<"Dexterity: "<<stats->dexterity<<"              Dexterity: "<<mstats->dexterity<<endl;
    cout<<"Balance: "<<stats->balance<<"                Balance: "<<mstats->balance<<endl;
    cout<<"Charisma: "<<stats->chari<<"               Charisma: "<<mstats->chari<<endl;
    cout<<"Wisdom: "<<stats->wisdom<<"                 Wisdom: "<<mstats->wisdom<<endl<<endl;
    cout<<"To move, enter a compass direction."<<endl;
        cout<<"For example, type 'e' to move east, or right."<<endl<<endl;
        cout<<"Map Legend: H = Health Potions: Adds 10 health"<<endl;
        cout<<"            S = Strength Potions: Adds 10 strength"<<endl;
        cout<<"            I = Intelligence Potions: Adds 10 Intelligence"<<endl;
        cout<<"            T = Trees: You have to move around these"<<endl;
        cout<<"            P = Your character"<<endl;
        cout<<"            M = Your enemy"<<endl<<endl;

    cout<<"                     <Press any key to continue...>"<<endl;
    cin.ignore();
    system("cls");

}
