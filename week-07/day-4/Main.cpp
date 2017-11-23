#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "SerialPortWrapper.h"

using namespace std;

void usageprint();

int main()
{
    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }

    // connection

    SerialPortWrapper *serial = new SerialPortWrapper("COM19", 115200);
    serial->openPort();
    string line;

    vector<string> loggedtemps;
    char c;
    bool portopen;
    bool logging;
    bool run = true;
    usageprint();
    while(run){
        serial->readLineFromPort(&line);
        if (line.length() > 0){
             loggedtemps.push_back(line);
        }
        c = getchar();
        switch (c) {
        case 'e' :
            run = false;
            break;
        case 'l' :
            for (unsigned int i = 0; i < loggedtemps.size(); ++i)
                cout << loggedtemps[i] << endl;
        }
    }
        serial->closePort();
    return 0;
}
void usageprint()
{
cout << "\
Temperature Logger Application\n\
==============================\n\
Commands:\n\
 h        Show command list\n\
 o        Open port\n\
 s        Start logging / Stop logging\n\
 c        Close port\n\
 l        List after error handling\n\
 e        Exit from the program\n\n";
}
