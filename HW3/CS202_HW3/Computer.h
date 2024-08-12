#ifndef COMPUTER_H
#define COMPUTER_H
#include "Request.h"

/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: a Computer Class,I give requests to computer objects
*/
class Computer
{
    public:
        Computer();
        int getCurrentTime(){return currentTime;};
        int giveDuty(Request aRequest);

    private:
        int currentTime;
};

#endif // COMPUTER_H
