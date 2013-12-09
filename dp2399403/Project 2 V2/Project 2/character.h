
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>



struct pStat{

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
    std::string name;
    std::string meleeAt;
    std::string rangeAt;

};

class character
{


    private:

        pStat *stats;
        int pClass; //Class of character


    public:

        character();
        string getName(string );
        pStat getRace(pStat *);
        pStat getClass(int , pStat *);


     //  ~character(){delete stats;}
};
#endif // CHARACTER_H
