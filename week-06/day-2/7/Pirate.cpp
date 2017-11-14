#include "Pirate.h"

void Pirate::drink_rum() {
        rum++;
    }
string Pirate::hows_goin_mate() {
        if (rum >= 5)
            return "Arrrr! ";
        else
            return "Nothin'";
    }
Pirate::~Pirate() {
        cout << endl << "1 Pirate has disappeared.";
    }
