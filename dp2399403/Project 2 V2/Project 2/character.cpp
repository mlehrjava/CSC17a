#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>


using namespace std;

#include "character.h"




character::character()
{
    //ctor
}
//int wmain(){}
string character::getName(string pName){

    cout<<"Hello Adventurer, what is your name: ";
    getline(cin, pName);
    cout<<endl;

    return pName;

}
pStat character::getRace(pStat *stats){

    //Displays Race Choices
    cout<<"1. Human: A diplomat to all of the land."<<endl;
    cout<<"2. Dwarf: A strong miner who keeps to themselves."<<endl;
    cout<<"3. Orc: A strong, but savage half man and beast."<<endl;
    cout<<"4. Elf: An intellect whose knowledge in magic is infinite."<<endl<<endl;
    cout<<"Select your race: ";
    cin>>stats->race;
    cin.ignore();
    cout<<endl;
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
pStat character::getClass(int pClass, pStat *stats){

     string custclName; //Name of a custom class


    int fintStat,fstrStat, // Intelligence, Strength
        fdexStat, fbalStat, // Dexterity, Balance
        fcharStat, fwisStat;//Charisma, Wisdom
    pClass=0;
        //Stats for custom user input
    int ciintStat,cistrStat, // Intelligence, Strength
        cidexStat, cibalStat, // Dexterity, Balance
        cicharStat, ciwisStat,//Charisma, Wisdom
        cihpStat; //Hit Points

    //Classes for character, respectively
    char cWarr, cMage, //Warrior, Mage
        cRogue, cPriest, //Rogue, Priest
        cCustom; //A custom class made by the user

    int intStat = 0, strStat = 0, // Intelligence, Strength
        dexStat = 0, balStat = 0, // Dexterity, Balance
        charStat = 0, wisStat = 0,//Charisma, Wisdom
        hpStat = 0; // Hit Points

     cout<<"1. Warrior                             2. Mage"<<endl<<endl;
    cout<<"A hero who uses hand to hand combat.   A hero who uses magic to their advantage."<<endl;
    cout<<"Hit Points: 50                         Hit Points: 50"<<endl;
    cout<<"Strength:8                             Strength: 4"<<endl;
    cout<<"Intelligence: 4                        Intelligence: 8"<<endl;
    cout<<"Dexterity: 6                           Dexterity: 3"<<endl;
    cout<<"Balance: 6                             Balance: 4"<<endl;
    cout<<"Charisma: 3                            Charisma: 6"<<endl;
    cout<<"Wisdom: 4                              Wisdom: 6"<<endl;
    cout<<endl;
    cout<<"3. Rogue                               4. Priest"<<endl<<endl;
    cout<<"A hero who uses stealth.               A hero who heals their party."<<endl;
    cout<<"Hit Points: 50                         Hit Points: 50"<<endl;
    cout<<"Strength:5                             Strength: 4"<<endl;
    cout<<"Intelligence: 5                        Intelligence: 7"<<endl;
    cout<<"Dexterity: 6                           Dexterity: 3"<<endl;
    cout<<"Balance: 7                             Balance: 6"<<endl;
    cout<<"Charisma: 6                            Charisma: 6"<<endl;
    cout<<"Wisdom: 5                              Wisdom: 6"<<endl;
    cout<<endl;
    cout<<"5. A custom hero with self selected stats.";
    cout<<endl;

    cout<<"Select your Class: ";
    cin>>pClass;
    cin.ignore();
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
                    case 5: pClass = cCustom;
                         cout<<"Enter your class name: ";
                         getline(cin, stats->cusclass);
                         cout<<endl;

                         cout<<"Enter your strength(Values of 10-20): ";
                         cin>>cistrStat;
                         if(cistrStat>20 || cistrStat <10){
                                         do{
                                                      cout<<"Please enter a value from 10-20: ";
                                                      cin>>cistrStat;
                                                      }while(cistrStat >20 || cistrStat <10);
                                         }
                         strStat = cistrStat;
                         cout<<"Enter your intelligence(Values of 10-20): ";
                         cin>>ciintStat;
                         if(ciintStat>20 || ciintStat <10){
                                         do{
                                                      cout<<"Please enter a value from 10-20: ";
                                                      cin>>ciintStat;
                                                      }while(ciintStat >20 || ciintStat <10);
                                         }
                         intStat = ciintStat;
                         cout<<"Enter your dexterity(Values of 10-20): ";
                         cin>>cidexStat;
                         if(cidexStat>20 || cidexStat <10){
                                         do{
                                                      cout<<"Please enter a value from 1-10: ";
                                                      cin>>cidexStat;
                                                      }while(cidexStat >20 || cidexStat <10);
                                         }
                         dexStat = cidexStat;
                         cout<<"Enter your balance(Values of 10-20): ";
                         cin>>cibalStat;
                         if(cibalStat>20 || cibalStat <10){
                                         do{
                                                      cout<<"Please enter a value from 10-20: ";
                                                      cin>>cibalStat;
                                                      }while(cibalStat >20 || cibalStat <10);
                                         }
                         balStat = cibalStat;
                         cout<<"Enter your charisma(Values of 10-20): ";
                         cin>>cicharStat;
                         if(cicharStat>20 || cicharStat <10){
                                         do{
                                                      cout<<"Please enter a value from 10-20: ";
                                                      cin>>cicharStat;
                                                      }while(cicharStat >20 || cicharStat <10);
                                         }
                         charStat = cicharStat;
                         cout<<"Enter your wisdom(Values of 10-20): ";
                         cin>>ciwisStat;
                         if(ciwisStat>20 || ciwisStat <10){
                                         do{
                                                      cout<<"Please enter a value from 10-20: ";
                                                      cin>>ciwisStat;
                                                      }while(ciwisStat >20 || ciwisStat <10);
                                         }
                         wisStat = ciwisStat;
                         cout<<"Enter your hit points(Values of 10-20): ";
                         cin>>cihpStat;
                         if(cihpStat>20 || cihpStat<10){
                                        do{
                                                       cout<<"Please enter a value from 10-20: ";
                                                       cin>>cihpStat;
                                                       }while(cihpStat >20 || cihpStat < 10);
                                        }
                         stats->hitP = cihpStat;
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
             stats->meleeAt = "Slash";
             stats->rangeAt = "Axe Throw";
             }
   else if(stats->plclass ==2){
             stats->cusclass ="Mage";
             stats->meleeAt = "Staff Bash";
             stats->rangeAt = "Frost Bolt";
             }
    else if(stats->plclass ==3){
             stats->cusclass ="Rogue";
             stats->meleeAt = "Stab";
             stats->rangeAt  = "Long Bow";
             }
     else if(stats->plclass ==4){
             stats->cusclass ="Priest";
             stats->meleeAt = "Bible Bash";
             stats->rangeAt = "Holy Light";
             }
    else if(stats->plclass ==5){
            stats->cusclass;
    }

    system("cls");
    return  pClass, *stats;
}





