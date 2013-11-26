/* 
 * File:   main.cpp
 * Author: cybraryn
 *
 * Created on November 25, 2013, 3:16 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct MWeather {
    double high_temperature;
    double low_temperature; 
};


//int main(int argc, char** argv) {

    //return 0;
//}

int main()
{
    struct MWeather{
        float total_rainfall,
               high_temperature,
               low_temperature,
               average_temperature;
    };

    
    
    
    //float averageTemp(vector<Mweather>);
    float averageVector(const vector<Mweather>&); 
    string months[12] = {"January", "February", "March",
    "April", "May", "June", "July", "August","September",
    "October","November","December"};

    vector<MWeather> weatherData(12);

    for(int i = 0; i < 12; i++){
        cout << "Enter in the total rainfall, high temperature and "
             << "low temperature, for the month of " << months[i];

        cout << "\n>";

        cin >> weatherData[i].total_rainfall
            >> weatherData[i].high_temperature
            >> weatherData[i].low_temperature;
    }

    cout << averageTemp(weather[0]);

    return 0;
} 

float averageTemp(vector<Mweather> data)
{
    return (data.low_temperature + data.high_temperature)/2.0;
}