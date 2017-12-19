#include <iostream>
#include <fstream>
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
    int portn;
    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\t" << i + 1 << ".: Port name: " << ports.at(i) << endl;
    }
    cout << "Select port number: ";
    cin >> portn;
    ofstream tlogfile("tempslog.txt");
    ifstream tlogfile_in("tempslog.txt");

    // connection

    SerialPortWrapper *serial = new SerialPortWrapper(ports.at(portn - 1), 115200);
    string line;
    //FILE* fptr;

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
            if (!tlogfile_in.is_open()) {
                cout << "File not found!" << endl;
            } else {
                loggedtemps.clear();
                while (!tlogfile_in.eof()) {
                    tlogfile_in >> finput;
                    if (tlogfile_in.fail())
                        continue;
                    Temperature tf(finput);
                    loggedtemps.push_back(tf);
                }
                cout << "Data loaded." << endl;
            }
            tlogfile_in.close();
            break;
        case 'f':

            for (unsigned int i = 0; i < loggedtemps.size(); ++i) {
                tlogfile << loggedtemps.at(i).get() << endl;
                //fputc('\n', fptr);
            }
            tlogfile.close();
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
