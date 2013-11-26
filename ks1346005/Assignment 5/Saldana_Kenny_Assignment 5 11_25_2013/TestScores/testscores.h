/* 
 * File:   testscores.h
 * Author: Kenny Saldana
 * Info: Header file for problem 14 (CH 16)
 *
 * Created on November 25, 2013, 2:23 PM
 */

#ifndef TESTSCORES_H
#define	TESTSCORES_H
void testAvg(int len, int marks[]);  // Function prototype
	 
	class TestScores       // TestScores class declaration
	{
	private:
	       int _len;                     // To hld the size of the array
	       int* _marks[];                // To hold the grades in the array
	public:
	       /* Default Constructor
	       TestScores()
	       {
	             _len = 0;
	             _marks = 0;
	       }*/
// Constructor
	       TestScores(int len, int marks[])
	       {
	           _len = len;
	           *_marks = marks;
	       }
	            
	       // Member Function to get calculate the average
	       int getAvg()
	       {
	           int i, j, sum=0, currMark;
	           char error[60];
	     
	           if(_len < 1)
	           return 0;
	     
	           for (i=0; i<_len; i++)
	           {
	               currMark = (*_marks)[i];
	     
	               // Throwing exception when grade is negative
	               if (currMark < 0 )
	               {
	                    throw "ERROR:  Grade can not be negative";       
	               }
	               // Throwing exception when grade exceeds 100.              
	               if (currMark > 100 )
	               {
	                    throw "ERROR:  Grade can not exceed 100 points";
	               }
	               sum += currMark;
	           }
	     
	          return (sum) / _len;
	       }
	};

#endif	/* TESTSCORES_H */