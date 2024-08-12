#include "Simulator.h"
#include <stdlib.h>
#include <cstdlib>
/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: main class, it takes two parameter from the command line,
* file name and maxavaragetime
*/
int main(int argc, char** argv) {

    //char** dummy;
    string file_name = argv[1];
    //double number = strtod(argv[2], dummy);
    double number = atof(argv[2]);
    Simulator sim(file_name);

    //cout << sim.printSimulate(3);
    sim.calculateMinComputers(number);


    return 0;
}
