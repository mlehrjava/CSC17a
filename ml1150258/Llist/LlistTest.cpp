//Mark E. Lehr
//Nov 27th, 2013
//List Implementation Test 

#include <iostream>
#include "Object.h"
#include "Llist.h"
using namespace std;

int main(int argv,char *argc[]){
        //Create 3 objects, note I didn't set the
	//information in the objects.  Not necessary
	//to perform this test.
	int n=4;
	Object info1(n),info2(n+1),info3(n+2);

	//Insert the 3 objects in the list
	Llist x;
	x.insert(info1);
	x.insert(info2);
	x.insert(info3);

	//Check out the information
	cout<<"The number of insertions is = "<<x.getLength()<<endl;
	cout<<"The size of the first object in the List is = " <<x.fromFront(1)->getSize()<<endl;
	cout<<"The size of the second object in the List is = "<<x.fromFront(2)->getSize()<<endl;
	cout<<"The size of the third object in the List is = " <<x.fromFront(3)->getSize()<<endl;

	return 1;
}