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
    string line;

    vector<string> loggedtemps;
    bool portopen = false;
    bool logging = false;
    bool run = true;
    usageprint();
    while(run){
        if (portopen)
            serial->readLineFromPort(&line);
        if (logging && (line.length() > 0))
             loggedtemps.push_back(line);
        switch (getchar()) {
        case 'e':
            run = false;
            break;
        case 'l':
            cout << "Recorded temperatures:\n--- Date ------ Time ------ Degrees" << endl;
            for (unsigned int i = 0; i < loggedtemps.size(); ++i)
                cout << loggedtemps[i] << endl;
            break;
        case 'o':
            if (!portopen) {
                serial->openPort();
                portopen = true;
                cout << "Port opened." << endl;
            } else {
                cout << "Port is already open!" << endl;
            }
            break;
        case 's':
            if (portopen)
                if (!logging) {
                    logging = true;
                    cout << "Logging started." << endl;
                } else {
                    logging = false;
                    cout << "Logging stopped." << endl;
                }
            else
                cout << "Port is not open!" << endl;
            break;
        case 'c':
            if (portopen) {
                serial->closePort();
                portopen = false;
                logging = false;
                cout << "Port closed." << endl;
            } else {
                cout << "Port is already closed!" << endl;
            }
            break;
        case 'h':
            usageprint();
            break;
        }
    }
    if (portopen)
        serial->closePort();
    delete serial;
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
