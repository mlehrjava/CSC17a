/* 
 * File:   main2.cpp
 * Author: Kenny Saldana
 * Info: Ch 16 problem 13
 *
 * Created on November 25, 2013, 3:22 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//int main(int argc, char** argv) {

    //return 0;
//}

class rainFall{
    private:
    int counter;
    float amount;
    float ave;
    public:
    vector<float> monthRain;
    vector<string> monthName;
    rainFall()
    {
        counter = 0;    ave = 0;
        amount = 0.00;
        monthName.push_back("JAN");
        monthName.push_back("FEB");
        monthName.push_back("MAR");
        monthName.push_back("APR");
        monthName.push_back("MAY");
        monthName.push_back("JUN");
        monthName.push_back("JUL");
        monthName.push_back("AUG");
        monthName.push_back("SEP");
        monthName.push_back("OCT");
        monthName.push_back("NOV");
        monthName.push_back("DEC");
    }
    void setVector(float &rainFall)
    {
        monthRain.push_back(rainFall); 
    }
    float calAmount()
    {
        for(counter; counter < 12; counter++)
        {
            amount += monthRain.at(counter);
        }
        return amount;
    }
    
    float calAve(float amount)
    {
        ave = (amount/12);
        return ave;
    }
    
    void BubbleSort()
    {
      int i, j, flag = 1;
      float temp;
      int numLength = 12; 
      for(i = 1; (i <= numLength) && flag; i++)
      {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
               if (monthRain[j+1] > monthRain[j])
              { 
                    temp = monthRain[j];
                    monthRain[j] = monthRain[j+1];
                    monthRain[j+1] = temp;
                    flag = 1;
               }
          }
     }
    }
    float getHeight()
    {
        BubbleSort();
        return monthRain.at(0);
    }
    
    float getLow()
    {
        return monthRain.at(11);
    }
};

int main(void)
{
    rainFall rf;
    float rainfall; 
    int counter = 0;
    for(counter; counter < 12; counter++)
    {
        cout << "Enter a rainfall in " <<rf.monthName.at(counter) << " : ";
        cin >>   rainfall;
        while(rainfall < 0)
        {
            cout << "***** ERROR ****** "<< endl;
            cout << "The amount of ainfall is more than 0 "<< endl;
            cout << "Enter " <<counter << "month's amount of rainfall : ";
            cin >>   rainfall;
        }
        rf.setVector(rainfall);
    }
    cout << "Total rainfall in this year was "<<rf.calAmount() << " mg" <<endl;
    cout << "Average rainfall in this year was " << rf.calAve(rf.calAmount()) << " mg / month " << endl;
    cout << "Highest rainfall in this year was " << rf.getHeight() << " mg / month"<<endl;
    cout << "Lowest rainfall in this year was " << rf.getLow() << " mg / month"<<endl;
    return 0;
}