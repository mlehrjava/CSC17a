//Mark E. Lehr
//Nov 27th, 2013
//Hash Implementation Test 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Object.h"
#include "Llist.h"
using namespace std;

void cr8Init(char []);
int hashFnk(char []);

int main(int argv,char *argc[]){
        //Set the random number seed
        srand(static_cast<unsigned int>(time(0)));
        //Dynamically create an array of size 676
        const int lSize=26*26;
        Llist *hashStack=new Llist[lSize];
        //Randomly fill the array with data
        const int nStudents=20000;
        for(int student=0;student<nStudents;student++){
            Object *info=new Object(int(rand()%4+1));
            char init[2];
            cr8Init(init);
            int index=hashFnk(init);
            hashStack[index].insert(*info);
        }
        for(int list=0;list<lSize;list++){
            cout<<"The number of insertions is = "<<hashStack[list].getLength()<<" for "<<list<<endl;
        }
	
        //Clean up
        delete [] hashStack;
	return 0;
}

void cr8Init(char a[]){
    a[0]=rand()%26+65;
    a[1]=rand()%26+65;
}

int hashFnk(char a[]){
    return (a[0]-65)*26+a[1]-65;
}