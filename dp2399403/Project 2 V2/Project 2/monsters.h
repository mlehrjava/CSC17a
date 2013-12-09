
#ifndef MONSTERS_H
#define MONSTERS_H

#include <string>

struct monSta{

    int plclass;
    int intel;
    int strength;
    int dexterity;
    int balance;
    int chari;
    int wisdom;
    int hitP;
    int race;
    std::string rName;
    std::string cusclass;

};

class monsters
{
    private:

    monSta *monst;
    int pClass;

    public:

        monsters();

        monSta monRace(monSta *);
        monSta monClass(int, monSta *);
      //  ~monsters(){delete monst;}


};

#endif // MONSTERS_H
