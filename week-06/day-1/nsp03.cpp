#include <iostream>
#include <ctime>

// Use your costume namespace from the last exercise
// Create a function, which takes the age as a parameter
// and returns the year when you were born

using namespace std;
namespace Person {
    string name = "Nagymihaly Armin";
    int age = 33;
    int favnum = 12;
    }
int yearofbirth(int age);

int main()
{
    using namespace Person;

    cout << "Write your age! ";
    cin >> age;
    cout << name << endl << "Age: " << age << endl << "Fav. number: " << favnum;
    cout << endl << "Year of birth: " << yearofbirth(age);
    return 0;
}
int yearofbirth(int age)
{
    time_t uxtime;
    struct tm *ptm;
    time(&uxtime);
    ptm = gmtime(&uxtime);
    return ptm->tm_year - age + 1900;
}

