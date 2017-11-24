#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Temperature
{
    public:
        Temperature();
        Temperature(string inputstr);
        string get();
        bool isvalid;

    private:
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int sec;
        int deg;

        void setyear();
        void setmonth();
        void setday();
        void sethour();
        void setminute();
        void setsec();

};

#endif // TEMPERATURE_H
