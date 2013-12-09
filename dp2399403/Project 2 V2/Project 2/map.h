#ifndef MAP_H
#define MAP_H


class map
{
   private:

       static const int COLS=21;
    static const int ROWS=21;


   public:

    map();

    int fill2DArray(char [][COLS], int);
    void print2D(map,char [][COLS],int);
    int charMov(char [][COLS],int,char,int,int,int );
    int monMov(char [][COLS],int,char,int,int,int);
    float getDist(int,int,int,int,float);


};

#endif // MAP_H
