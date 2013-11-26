/* 
 * File:   main.cpp
 * Author: Kenny Saldana
 * Info: CH 16 problem 14
 * Created on November 25, 2013, 2:23 PM
 */

#include <cstdlib>
#include <iostream>
#include "testscores.h"

using namespace std;
 

//int main(int argc, char** argv) {

    //return 0;
//}

	int main()
	{
	    // Test program with and without the exceptions
	    // First test will be normal array
	    int marks1[] = {79, 89, 86, 100, 82, 94, 73 };
	    testAvg(5, marks1);
	 
	    // Next, test the array with a negative test grade
	    int marks2[] = {40, -60, 70 };
	    testAvg(3, marks2);
	 
	    //Finally, test the array with a grade over 100
	    int marks3[] = {140, 30};
	    testAvg(2, marks3);
	     
	    system("PAUSE");
	    return 0;
	}
	 
	//******************************************************************************
	// The testAvg function will accept an array of grades as an argument          *
	// and will return the average of those grades.                                *
	//******************************************************************************
	 
	void testAvg(int len, int marks[])
	{
	    TestScores test(len, marks);
	     
	    int result = 0;
	    try
	    {
	        result = test.getAvg();
	        cout << "The average of the test are: " << result << endl;
	    }
	    catch(char * err)
	    {
	        cout << err << "\n";
	    }
	}