/* 
 * File:   time.h
 * Author: Kenny Saldana
 * Info: Header file for Ch 16 problem 2
 *
 * Created on November 25, 2013, 2:48 PM
 */

#ifndef TIME_H
#define	TIME_H
#include <iostream>
using namespace std;

class Time
{
/******** Member functions ********/
public:
/* Set sets the data members of a Time object to specified values.
*
* Receive: hours, the number of hours in standard time
* minutes, the number of minutes in standard time
* AMPM ('A' if AM, 'P' if PM
* Return: The Time object containing this function with its
* myHours, myMinutes, and myAMorPM members set to hours,
* minutes, and am_pm, respectively, and myMilTime to
* the equivalent military time
********************************************************************/
void Set(unsigned hours, unsigned minutes, char am_pm);
/* Display displays time in standard and military format using
* output stream out.
*
* Receive: ostream out
* Output: The time represented by the Time object containing
* this function
* Passes back: The ostream out with time inserted into it
********************************************************************/
void Display(ostream & out) const;
/********** Data Members **********/
private:
unsigned myHours,
myMinutes;
char myAMorPM; // 'A' or 'P'
unsigned myMilTime; // military time equivalent
}; // end of class declaration

#endif	/* TIME_H */