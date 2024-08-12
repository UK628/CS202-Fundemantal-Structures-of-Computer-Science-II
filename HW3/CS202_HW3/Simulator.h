#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <fstream>
#include "Computer.h"
#include "PriorityQueue.h"
#include <fstream>



/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: simulator header, more detailed explanation is in the cpp file
*/
class Simulator
{
    public:
        Simulator(string fileName);
        ~Simulator();
        void calculateMinComputers(double averageWaitingTime);
        double Simulate(int computerNumber);
        double printSimulate(int computerNumber);
        int selectComputer(Computer* arr ,int compSize,Request aRequest);
        int selectComputerPrint(Computer* arr ,int compSize,Request aRequest);
        int findShortestTime(Computer* arr ,int compSize);

    private:
        PriorityQueue requests;
        Request* requestArr;
        int numberOfRequests;
        int currentTime;
};

#endif // SIMULATOR_H
