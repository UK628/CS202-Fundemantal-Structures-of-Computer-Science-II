#ifndef REQUEST_H
#define REQUEST_H

/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: request object header
*/
class Request
{
    public:
        Request(int id, int priority, int requestTime, int processTime);
        Request();
        int getId() {return id;};
        int getPriority() {return priority;};
        int getRequestTime() {return requestTime;};
        int getProcessTime() {return processTime;};

    private:
        int id;
        int priority;
        int requestTime;
        int processTime;
};

#endif // REQUEST_H
