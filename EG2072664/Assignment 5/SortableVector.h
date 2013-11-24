//Sortable Vector class template - class specification and implementation

#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H
#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

template <class T>
class SortableVector
{
private:
	T *aptr;
	int arraySize;
	void memError();
	void subError();
	void quickSort(T *, int, int);
	int partition(T *, int, int);

public:
	//Constructors
	SortableVector() { aptr = 0; arraySize = 0; }
	SortableVector(int);
	SortableVector(const SortableVector &);
	~SortableVector();

	//Accessors
	int size() const { return arraySize; }
	T getElementAt(int position);
	
	//Mutators
	void sort();

	//Overloaded constructors
	T &operator[] (const int &);
};


//constructor for SortableVector class - sets the size of the array and allocates memory
template <class T>
SortableVector<T>::SortableVector(int s){

	//set array size and allocate memory
	arraySize = s;
	try{
		aptr = new T [s];
	}
	catch (bad_alloc){
		memError();
	}

	//inilialize array
	for(int i=0; i < arraySize; i++){
		*(aptr + i) = 0;
	}
}


//Copy constructor for SortableVector class
template <class T>
SortableVector<T>::SortableVector(const SortableVector &obj){

	//copy array size
	arraySize = obj.arraySize;

	//allocate memory for the array
	aptr = new T [arraySize];
	if(aptr == 0)
		memError();

	//copy elements of obj's array
	for(int i=0; i<arraySize; i++){
		*(aptr + i) = *(obj.aptr + i);
	}

}


//destructor for SortableVector Class
template <class T>
SortableVector<T>::~SortableVector(){
	if(arraySize > 0)
		delete [] aptr;
}

//memError function - displays an error and terminates the program when memory allocation fails
template <class T>
void SortableVector<T>::memError(){
	cout << "ERROR: Cannot allocate memory. Terminating.\n";
	exit(EXIT_FAILURE);
}

//subError function - displays error message if the subscript is out of range
template <class T>
void SortableVector<T>::subError(){
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

//getElementAt function - argument is a subscript. 
//Returns the value stored at the subscript in the array.
template <class T>
T SortableVector<T>::getElementAt(int sub){
	if(sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

//overloaded [] operator. The argument is a subscript.
//Returns a reference to the element in the array indexed by the subscript.
template <class T>
T &SortableVector<T>::operator[](const int &sub){
	if(sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

//sort function - user accessible sorting routine
template <class T>
void SortableVector<T>::sort(){
	quickSort(aptr, 0, arraySize);
}

//quickSort function - uses quick sort to sort the vector in descending order
template <class T>
void SortableVector<T>::quickSort(T *aptr, int top, int bottom){
	int middle;
	if(top < bottom){
		middle = partition(aptr, top, bottom);
		quickSort(aptr, top, middle);
		quickSort(aptr, middle+1, bottom);
	}

	return;
}

//Partition function for quicksorting - returns the middle subscript
template <class T>
int SortableVector<T>::partition(T *aptr, int top, int bottom){
	T x = aptr[top];
	int i = top - 1;
	int j = bottom + 1;
	T temp;
	do{
		do{
			j--;
		}while (x > aptr[j]);

		do{
			i++;
		}while (x < aptr[i]);

		if(i < j)
		{
			temp = aptr[i];
			aptr[i] = aptr[j];
			aptr[j] = temp;
		}
	}while(i < j);

	return j;
}



#endif
