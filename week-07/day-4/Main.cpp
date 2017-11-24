#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <conio.h>
#include "SerialPortWrapper.h"
#include "Temperature.h"

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
    FILE* fptr;

    vector<Temperature> loggedtemps;
    bool portopen = false;
    bool logging = false;
    bool run = true;
    usageprint();
    while(run){
        if (portopen)
            serial->readLineFromPort(&line);
        if (logging && (line.length() > 0)) {
            Temperature tp(line);
            if (tp.isvalid)
                loggedtemps.push_back(tp);
        }
        if (kbhit()) {
        switch (getchar()) {
        case 'e':
            run = false;
            break;
        case 'l':
            cout << "Recorded temperatures:\n--- Date ----- Time -- Degrees -" << endl;
            for (unsigned int i = 0; i < loggedtemps.size(); ++i)
                cout << loggedtemps[i].get() << endl;
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
        case 'r':
            char finput[30];
            fptr = fopen("tempslog", "r");
            if (!fptr) {
                cout << "File not found!" << endl;
            } else {
                loggedtemps.clear();
                while (!feof(fptr)) {
                    fgets(finput, 30, fptr);
                    Temperature tf(finput);
                    loggedtemps.push_back(tf);
                }
                cout << "Data loaded." << endl;
            }
            fclose(fptr);
            break;
        case 'f':
            fptr = fopen("tempslog", "w");
            for (unsigned int i = 0; i < loggedtemps.size(); ++i) {
                fputs(loggedtemps[i].get(), fptr);
                fputc('\n', fptr);
            }
            fclose(fptr);
            break;
        case 'h':
            usageprint();
            break;
        }
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
 e        Exit from the program\n\
 f        Store datas in a file\n\
 r        Read datas from a file\n\n";
}
