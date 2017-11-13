#include <iostream>
#include <iomanip>

using namespace std;

// An average Green Fox attendee codes 6 hours daily
// The semester is 17 weeks long
//
// Print how many hours is spent with coding in a semester by an attendee,
// if the attendee only codes on workdays.
//
// Print the percentage of the coding hours in the semester if the average
// work hours weekly is 52

int main()
{
    float hoursday = 6;
    int weeks = 17;
    float avghrs_w = 52;
    cout << weeks * 5 * hoursday << " hours spent with coding." << endl;
    cout << setprecision(3) << 100 * hoursday * 5 / 52 << " average percent of coding time to working time." << endl;

    return 0;
}

