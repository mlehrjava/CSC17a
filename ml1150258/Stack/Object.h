//Mark E. Lehr
//Nov 27th, 2013
//Create a dynamic object.
//This will be a simple dynamic
//positive array that cannot
//be miss-utilized.

#ifndef OBJECT_H
#define OBJECT_H

class Object{
    private:
	int size;
	int *array;
    public:
	Object(int s=10){
            size=s;
            array=new int[size];
            for(int i=0;i<size;i++){
		array[i]=-1;
            }
	};
	~Object(){delete []array;};
	int getElement(int i){
            if(i<size&&i>=0)return array[i];
            else return -2;
        };
	int getSize(){return size;};
	void setElement(int i,int v){
                if(i<size&&i>=0&&v>0)array[i]=v;
	};
};

#endif