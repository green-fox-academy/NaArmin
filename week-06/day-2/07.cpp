#include <iostream>
#include <string>

using namespace std;

class Pirate {
    int rum = 0;
  public:
    void drink_rum() {
        rum++;
    }
    string hows_goin_mate() {
        if (rum >= 5)
            return "Arrrr! ";
        else
            return "Nothin'";
    }
    ~Pirate() {
        cout << endl << "1 Pirate has disappeared.";
    }
};
int main() {
    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise
  return 0;
}

