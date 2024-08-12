#include "Request.h"
/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: request object
*/
Request::Request() {
        id = 0;
        priority= 0;
        requestTime = 0;
        processTime = 0;
}

Request::Request(int id, int priority, int requestTime, int processTime)
{
    this->id = id;
    this->priority = priority;
    this->requestTime = requestTime;
    this->processTime = processTime;
}

