#include "Graph.h"
#include <fstream>
#include "AirlineCompany.h"
#include <stdlib.h>
#include <cstdlib>

/*
* Title: CS202 Spring 2022
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 4
* Description: The main method. The program takes input from the command line then accesses the provided input file
* and executes the requests one by one.
*/
int main(int argc, char** argv)  {

    string fileName = argv[1];

    ifstream input_file(fileName.c_str());
    if(!input_file.is_open()) {
        cout << "Could not open the file: " << fileName << " !!!" << endl;
    }
    else {
        int number;
        char opcode;
        int numAirport;
        int numRequest;

        input_file >> number;
        numAirport = number;
        input_file >> number;
        numRequest = number;

        cout << "Number Of Airports: " << numAirport << endl;
        cout << "Number Of Requests: " << numRequest << endl;
        cout<< endl;

        AirlineCompany aCompany(numAirport);

        for(int i = numRequest; i > 0; i--) {

            input_file >> opcode;

            switch(opcode){
                case 'I':
                    int a1;
                    int a2;
                    int dur;

                    input_file >> number;
                    a1 = number;

                    input_file >> number;
                    a2 = number;

                    input_file >> number;
                    dur = number;

                    aCompany.insertNewFlight(a1,a2,dur);
                    cout << endl;
                    break;

                case 'L':
                    int a;

                    input_file >> number;
                    a = number;

                    aCompany.listFlights(a);
                    cout << endl;
                    break;

                case 'S':
                    int v1;
                    int v2;

                    input_file >> number;
                    v1 = number;

                    input_file >> number;
                    v2 = number;

                    aCompany.findShortestPath(v1,v2);
                    cout << endl;
                    break;

                case 'M':
                    aCompany.minimizeTotalCost();
                    cout << endl;
                    break;

                default:
                    cout<<"ERROR: invalid opcode!" << endl;
            }
        }
    }

    return 0;
}
