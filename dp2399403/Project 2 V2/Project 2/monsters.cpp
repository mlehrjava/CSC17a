#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;


#include "monsters.h"


monsters::monsters(){


}
//int wmain(){}

monSta monsters::monRace(monSta *stats){

     srand(static_cast<unsigned int>(time(0)));
    stats->race = 0;
    stats->race = (rand()%3)+1;

     switch(stats->race){

                  case 1: {
                       stats->race = 1;
                       break;
                       }

                  case 2: {
                       stats->race = 2;
                       break;
                       }

                  case 3: {
                         stats->race = 3;
                         break;
                         }

                  case 4: {
                       stats->race = 4;
                       break;
                       }
            }
        if(stats->race ==1){
             stats->rName = "Human";
             }
   else if(stats->race ==2){
             stats->rName ="Dwarf";
             }
    else if(stats->race ==3){
             stats->rName ="Orc";
             }
     else if(stats->race ==4){
             stats->rName ="Elf";
             }


     return *stats;

}
monSta monsters::monClass(int pClass, monSta *stats){

    pClass = 0;
    pClass = (rand()%3) + 1;
     srand(static_cast<unsigned int>(time(0)));
    stats->intel = 0;
    stats->strength =0;
    stats->dexterity = 0;
    stats->balance = 0;
    stats->chari = 0;
    stats->wisdom = 0;


    int intStat = 0, strStat = 0, // Intelligence, Strength
        dexStat = 0, balStat = 0, // Dexterity, Balance
        charStat = 0, wisStat = 0,//Charisma, Wisdom
        hpStat = 0; // Hit Points




            switch(pClass){


                   case 1: stats->plclass = 1;
                        strStat = 8;
                        intStat = 4;
                        dexStat = 6;
                        balStat = 6;
                        charStat = 3;
                        wisStat = 4;
                        hpStat = 50;
                        stats->hitP = hpStat;
                               if(stats->race == 1){
                                        stats->intel = intStat;
                                        stats->strength = strStat;
                                        stats->dexterity = dexStat +2;
                                        stats->balance = balStat -2;
                                        stats->chari = charStat;
                                        stats->wisdom = wisStat +2;
                                        }
                                else if(stats->race == 2){
                                    stats->intel = intStat;
                                    stats->strength = strStat + 2;
                                    stats->dexterity = dexStat;
                                    stats->balance = balStat + 2;
                                    stats->chari = charStat -2;
                                    stats->wisdom = wisStat;
                                    }
                                else if(stats->race ==3){
                                    stats->intel = intStat;
                                    stats->strength = strStat + 2;
                                    stats->dexterity = dexStat + 2;
                                    stats->balance = balStat;
                                    stats->chari = charStat -2;
                                    stats->wisdom = wisStat - 2;
                                    }
                               else if(stats->race ==4){
                                    stats->intel = intStat + 2;
                                    stats->strength = strStat -2;
                                    stats->dexterity = dexStat;
                                    stats->balance = balStat +4;
                                    stats->chari = charStat;
                                    stats->wisdom = wisStat + 4;
                                    }

                                    break;
                    case 2: stats->plclass  = 2;
                         strStat = 4;
                         intStat = 7;
                         dexStat = 3;
                         balStat = 4;
                         charStat = 6;
                         wisStat = 6;
                         hpStat = 50;
                         stats->hitP = hpStat;
                              if(stats->race == 1){
                                        stats->intel = intStat;
                                        stats->strength = strStat;
                                        stats->dexterity = dexStat +2;
                                        stats->balance = balStat -2;
                                        stats->chari = charStat;
                                        stats->wisdom = wisStat +2;
                                        }
                                else if(stats->race == 2){
                                    stats->intel = intStat;
                                    stats->strength = strStat + 2;
                                    stats->dexterity = dexStat;
                                    stats->balance = balStat + 2;
                                    stats->chari = charStat -2;
                                    stats->wisdom = wisStat;
                                    }
                                else if(stats->race ==3){
                                    stats->intel = intStat;
                                    stats->strength = strStat + 2;
                                    stats->dexterity = dexStat + 2;
                                    stats->balance = balStat;
                                    stats->chari = charStat -2;
                                    stats->wisdom = wisStat - 2;
                                    }
                               else if(stats->race ==4){
                                    stats->intel = intStat + 2;
                                    stats->strength = strStat -2;
                                    stats->dexterity = dexStat;
                                    stats->balance = balStat +4;
                                    stats->chari = charStat;
                                    stats->wisdom = wisStat + 4;
                                    }

                                    break;
                   case 3: stats->plclass = 3;
                        strStat = 5;
                        intStat = 5;
                        dexStat = 6;
                        balStat = 7;
                        charStat = 6;
                        wisStat = 5;
                        hpStat = 50;
                        stats->hitP = hpStat;
                               if(stats->race == 1){
                                        stats->intel = intStat;
                                        stats->strength = strStat;
                                        stats->dexterity = dexStat +2;
                                        stats->balance = balStat -2;
                                        stats->chari = charStat;
                                        stats->wisdom = wisStat +2;
                                        }
                                else if(stats->race == 2){
                                    stats->intel = intStat;
                                    stats->strength = strStat + 2;
                                    stats->dexterity = dexStat;
                                    stats->balance = balStat + 2;
                                    stats->chari = charStat -2;
                                    stats->wisdom = wisStat;
                                    }
                                else if(stats->race ==3){
                                    stats->intel = intStat;
                                    stats->strength = strStat + 2;
                                    stats->dexterity = dexStat + 2;
                                    stats->balance = balStat;
                                    stats->chari = charStat -2;
                                    stats->wisdom = wisStat - 2;
                                    }
                               else if(stats->race ==4){
                                    stats->intel = intStat + 2;
                                    stats->strength = strStat -2;
                                    stats->dexterity = dexStat;
                                    stats->balance = balStat +4;
                                    stats->chari = charStat;
                                    stats->wisdom = wisStat + 4;
                                    }

                                    break;
                    case 4: stats->plclass  = 4;
                         strStat = 4;
                         intStat = 7;
                         dexStat = 3;
                         balStat = 6;
                         charStat = 6;
                         wisStat = 6;
                         hpStat = 50;
                        stats->hitP = hpStat;
                               if(stats->race == 1){
                                        stats->intel = intStat;
                                        stats->strength = strStat;
                                        stats->dexterity = dexStat +2;
                                        stats->balance = balStat -2;
                                        stats->chari = charStat;
                                        stats->wisdom = wisStat +2;
                                        }
                                else if(stats->race == 2){
                                    stats->intel = intStat;
                                    stats->strength = strStat + 2;
                                    stats->dexterity = dexStat;
                                    stats->balance = balStat + 2;
                                    stats->chari = charStat -2;
                                    stats->wisdom = wisStat;
                                    }
                                else if(stats->race ==3){
                                    stats->intel = intStat;
                                    stats->strength = strStat + 2;
                                    stats->dexterity = dexStat + 2;
                                    stats->balance = balStat;
                                    stats->chari = charStat -2;
                                    stats->wisdom = wisStat - 2;
                                    }
                               else if(stats->race ==4){
                                    stats->intel = intStat + 2;
                                    stats->strength = strStat -2;
                                    stats->dexterity = dexStat;
                                    stats->balance = balStat +4;
                                    stats->chari = charStat;
                                    stats->wisdom = wisStat + 4;
                                    }

                                    break;
                   }

    if(stats->plclass ==1){
             stats->cusclass = "Warrior";
             }
   else if(stats->plclass ==2){
             stats->cusclass ="Mage";
             }
    else if(stats->plclass ==3){
             stats->cusclass ="Rogue";
             }
     else if(stats->plclass ==4){
             stats->cusclass ="Priest";
             }
    else if(stats->plclass ==5){
            stats->cusclass;
    }

    return *stats;
}
