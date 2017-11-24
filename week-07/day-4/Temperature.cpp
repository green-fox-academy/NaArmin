#include "Temperature.h"

Temperature::Temperature()
{
     year = 0;
     month = 0;
     day = 0;
     hour = 0;
     minute = 0;
     sec = 0;
     deg = 0;
     isvalid = true;
}
Temperature::Temperature(string inputstr)
{
    int sl = inputstr.length();
    char str[sl];
    for (int i = 0; i < sl; ++i)
        str[i] = inputstr[i];
    if (sscanf(str, "%d.%d.%d %d:%d:%d %d", &year, &month, &day, &hour, &minute, &sec, &deg) == 7) {
        isvalid = true;
        setyear();
        setmonth();
        setday();
        sethour();
        setminute();
        setsec();
    } else {
        isvalid = false;
    }
}
void Temperature::setyear()
{
    if (year > 2017)
        isvalid = false;
    return;
}
void Temperature::setmonth()
{
    if (month > 12)
        isvalid = false;
    return;
}
void Temperature::setday()
{
    if (day > 31)
        isvalid = false;
    return;
}
void Temperature::sethour()
{
    if (hour > 23)
        isvalid = false;
    return;
}
void Temperature::setminute()
{
    if (minute > 59)
        isvalid = false;
    return;
}
void Temperature::setsec()
{
    if (sec > 59)
        isvalid = false;
    return;
}
string Temperature::get()
{
    char r[30];
    sprintf(r, " %d.%2d.%2d  %2d:%2d:%2d    %3d", year, month, day, hour, minute, sec, deg);
    return r;
}
