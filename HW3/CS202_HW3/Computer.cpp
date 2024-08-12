#include "Computer.h"
/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: a Computer Class,I give requests to computer objects
*/
Computer::Computer()
{
    currentTime = 0;
}

//returns the waiting time
int Computer::giveDuty(Request aDuty) {

    if(aDuty.getRequestTime() > currentTime) {
        //wait till request comes
        currentTime = aDuty.getRequestTime();

        //update currentTime
        currentTime += aDuty.getProcessTime();

        //no waiting time for the request
        return 0;
    }

    int waitingTime = currentTime - aDuty.getRequestTime();
    currentTime += aDuty.getProcessTime();
    return waitingTime;
}





