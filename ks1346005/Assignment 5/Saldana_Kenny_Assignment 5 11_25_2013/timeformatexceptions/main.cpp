/* 
 * File:   main.cpp
 * Author: Kenny Saldana
 * Info: Ch 16 problem 2
 *
 * Created on November 25, 2013, 2:46 PM
 */

#include <cstdlib>
#include <iostream>
#include "Time.h"

using namespace std;

int main(int argc, char** argv) {

    return 0;
}

//Utility Functions -- Prototypes
int ToMilitary(unsigned hours, unsigned minutes, char am_pm);
//Function to implement the Set operation
void
Time::Set
(unsigned hours, unsigned minutes, char am_pm)
{
// Check class invariant
if (hours >= 1 && hours <= 12 &&
minutes >= 0 && minutes <= 59 &&
(am_pm == 'A' || am_pm == 'P'))
{
myHours = hours;
myMinutes = minutes;
myAMorPM = am_pm;
myMilTime = ToMilitary(hours, minutes, am_pm);
}
else
cerr << "*** Can't set time with these values ***\n";
//Object's data members remain unchanged
}
//Function to implement the Display operation
void
Time::Display
(ostream & out) const
{
out << myHours << ':'
<< (myMinutes < 10 ? "0" : "") << myMinutes
<< ' ' << myAMorPM << ".M. ("
<< myMilTime << " mil. time)";
}

//Utility Functions -- Definitions
/* ToMilitary converts standard time to military time.
*
* Receive: hours, minutes, am_pm
* Return: The military time equivalent
*/
int ToMilitary (unsigned hours, unsigned minutes, char am_pm)
{
if (hours == 12)
hours = 0;
return hours * 100 + minutes + (am_pm == 'P' ? 1200: 0);
}
