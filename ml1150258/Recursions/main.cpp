/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on December 2, 2013, 6:21 PM
 * Recursions Galore!!!!
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

float myTan(float);
int   biCoef(int,int);
void  babTwr(int,char,char,char);
int   add(int,int);
int   mult(int,int);
int   pwer(int,int);

int main(int argc, char** argv) {
    //Compare the recursive tangent function
    for(float angle=0;angle<=0.5;angle+=0.1){
        cout<<"Computer Tanget("<<angle<<")="<<tan(angle)<<" ";
        cout<<"Recursive Tanget("<<angle<<")="<<myTan(angle)<<endl;
    }
    //Output for binomial coefficients
    for(int row=0;row<=10;row++){
        for(int col=0;col<=row;col++){
            cout<<biCoef(row,col)<<" ";
        }
        cout<<endl;
    }
    //Play babylonian towers (disks numbered 0 to n-1)
    int nDisks=3-1;//numbered from 0 to n-1
    babTwr(nDisks,'A','B','C');
    //Add 2 numbers
    int a=-3,b=4;
    cout<<"a="<<a<<" b="<<b<<" ";
    cout<<"a+b="<<add(a,b)<<endl;
    //Multiply 2 numbers
    cout<<"a="<<a<<" b="<<b<<" ";
    cout<<"a*b="<<mult(a,b)<<endl;
    //Raise a to the power of b
    cout<<"a="<<a<<" b="<<b<<" ";
    cout<<"a^b="<<pwer(a,b)<<endl;

    return 0;
}

int pwer(int a,int b){
    if(b==1)return a;
    int res=pwer(a,b/2);
    if(b%2)return res*res*a;
    return res*res;
}

int mult(int a,int b){
    if(a==1)return b;
    if(a>0){
         return mult(--a,b)+b;
    }else{
        return mult(++a,b)-b;
    }
}

int add(int a,int b){
    if(a==0)return b;
    if(a>0)return add(--a,++b);
    return add(++a,--b);
}

void babTwr(int disk,char source,char destination,char spare){
    if(disk==0){
        cout<<"disk "<<disk<<" from peg "<<source
                <<" to destination peg "<<destination<<endl;
    }else{
        babTwr(disk-1,source,spare,destination);
        cout<<"disk "<<disk<<" from peg "<<source
                <<" to destination peg "<<destination<<endl;
        babTwr(disk-1,spare,destination,source);
    }
}

int biCoef(int row,int col){
    if(row==0)return 1;
    if(col==0)return 1;
    if(row==col)return 1;
    return biCoef(row-1,col-1)+biCoef(row-1,col);
}

float myTan(float x){
    float tol=1e-3;
    if(x>-tol&&x<tol) return x-x*x*x/6;
    float a=myTan(x/2);
    return 2*a/(1-a*a);
}

