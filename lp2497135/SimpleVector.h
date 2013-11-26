// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;


template <class T>
class SimpleVector{
private:
   T *aptr;          // To point to the allocated array
   T *pp;
   T *psh;
   int arraySize;    // Number of elements in the array
   int maxSize;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;} 
   // Constructor declaration
   SimpleVector(int);
   // Copy constructor declaration
   SimpleVector(const SimpleVector &); 
   // Destructor declaration
   ~SimpleVector();  
   // Accessor to return the array size
   int size() const
      { return arraySize; }
   // Accessor to return a specific element
   T getElementAt(int position);
   // Overloaded [] operator declaration
   T &operator[](const int &);

   void print();
   void pop();
   void push(T);
};
//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s){
   arraySize = s;
   maxSize = arraySize;
   // Allocate memory for the array.
   try{
      aptr = new T [s];
   }
   catch (bad_alloc){
      memError();
   }
   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}
//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
   // Copy the array size.
   arraySize = obj.arraySize;
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
	   *(aptr + count) = *(obj.aptr + count);
}
//**************************************
// Destructor for SimpleVector class.  *
//**************************************
template <class T>
SimpleVector<T>::~SimpleVector(){
   if (arraySize > 0)
      delete [] aptr;
}
//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************
template <class T>
void SimpleVector<T>::memError(){
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}
//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************
template <class T>
void SimpleVector<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}
//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************
template <class T>
T SimpleVector<T>::getElementAt(int sub){
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub){
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
/*******************************************************
** Function: print
*******************************************************/
template <class T>
void SimpleVector<T>::print(){
	for (int i = 0; i < arraySize; i++)
		cout << aptr[i] << " ";
	cout << endl << endl;
	return;
}
/*******************************************************
** Function: pop
*******************************************************/
template <class T>
void SimpleVector<T>::pop(){
   /*pp = new T [--arraySize];
   for (int count = 0; count < arraySize; count++)
      *(pp + count) = *(aptr + count);
   delete [] aptr;
   aptr = new T [arraySize];
   aptr = pp;
   delete [] pp;
   return;*/
	
	--arraySize;
	return;
}
/*******************************************************
** Function: push
*******************************************************/
template <class T>
void SimpleVector<T>::push(T end){
    /*psh = new T [++arraySize];
    for (int count = 0; count < arraySize-1; count++)
       *(psh + count) = *(aptr + count);
	*(psh + arraySize-1) = end;
	delete [] aptr;
    aptr = new T [arraySize];
	aptr = psh;
    delete [] psh;
	return;*/
	
	maxSize = maxSize*2;
	++arraySize;
	psh = new T [maxSize];
    for (int count = 0; count < arraySize-1; count++)
       *(psh + count) = *(aptr + count);
	*(psh + arraySize-1) = end;
	delete [] aptr;
    aptr = new T [maxSize];
	aptr = psh;
	return;
}
#endif

