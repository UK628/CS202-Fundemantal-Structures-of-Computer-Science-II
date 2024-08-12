#include "Simulator.h"

/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: a simulator class to simulate how much time would it take to execute given requests
* and find the minimum number of computers to reach a wanted average waiting time
*/
Simulator::Simulator(string fileName)
{
    currentTime = 0;
    ifstream input_file(fileName.c_str());
    if(!input_file.is_open()) {
        cout << "Could not open the file: " << fileName << " !!!" << endl;
    }
    else{
        int number;
        int index = 0;
        if(input_file >> number) {
            numberOfRequests = number;

            requestArr = new Request[numberOfRequests];
            //cout << number << " " << endl;

            while(input_file >> number) {
                int id = number;

                //cout << number << " ";

                input_file >> number;
                int priority = number;

                //cout << number << " ";

                input_file >> number;
                int requestTime = number;

                //cout << number << " ";

                input_file >> number;
                int processTime = number;

                //cout << number << " " << endl;

                Request aRequest(id,priority,requestTime,processTime);
                requestArr[index] = aRequest;
                index++;
                //requests.pqInsert(aRequest);
            }
        }
    }

    input_file.close();
}

Simulator::~Simulator() {
    delete[] requestArr;
}


void Simulator::calculateMinComputers(double maxTime) {

    double avgTime;
    int numberOfComputers = 1;

    do{
        avgTime = Simulate(numberOfComputers);
        numberOfComputers++;
    }while(avgTime > maxTime);

    numberOfComputers--;

    cout << "Minimum number of computers required: " << numberOfComputers << endl;
    cout << endl;
    cout << "Simulation with " << numberOfComputers << " computers :" << endl;
    cout << endl;

    printSimulate(numberOfComputers);

    cout<< "Average waiting time: " << avgTime << " ms." << endl;
}

double Simulator::Simulate(int const computerNumber) {

    if(computerNumber <= 0) {
        cout << "it is not possible to simulate with 0 or less computer" << endl;
        return -1;
    }

    if(numberOfRequests == 0) {
        return 0;
    }


    Computer* computers = new Computer[computerNumber];
    double totalWaitingTime = 0;

    //requests.pqInsert(requestArr[0]);
    currentTime = requestArr[0].getRequestTime();
    int smallest;

    for(int i = 0; i < numberOfRequests; i++) {

        if(requestArr[i].getRequestTime() <= currentTime){
            requests.pqInsert(requestArr[i]);
            //cout << "request " << i + 1 << " arrived." << endl;
        }
        else {

            while(!requests.pqIsEmpty() && requestArr[i].getRequestTime() > currentTime) {
                Request nextRequest;
                requests.pqDelete(nextRequest);
                totalWaitingTime += selectComputer(computers, computerNumber, nextRequest);
                currentTime = findShortestTime(computers, computerNumber);
            }

            requests.pqInsert(requestArr[i]);
            //cout << "request " << i + 1 << " arrived." << endl;
        }
    }


    while(!requests.pqIsEmpty()) {
        Request nextRequest;
        requests.pqDelete(nextRequest);
        totalWaitingTime += selectComputer(computers, computerNumber, nextRequest);
    }


    delete[] computers;
    currentTime = 0;
    return totalWaitingTime/numberOfRequests; //average waiting time
}


double Simulator::printSimulate(int const computerNumber) {

    if(computerNumber <= 0) {
        cout << "it is not possible to simulate with 0 or less computer" << endl;
        return -1;
    }

    if(numberOfRequests == 0) {
        return 0;
    }


    Computer* computers = new Computer[computerNumber];
    double totalWaitingTime = 0;

    //requests.pqInsert(requestArr[0]);
    currentTime = requestArr[0].getRequestTime();
    int smallest;

    for(int i = 0; i < numberOfRequests; i++) {

        if(requestArr[i].getRequestTime() <= currentTime){
            requests.pqInsert(requestArr[i]);
            //cout << "request " << i + 1 << " arrived." << endl;
        }
        else {

            while(!requests.pqIsEmpty() && requestArr[i].getRequestTime() > currentTime) {
                Request nextRequest;
                requests.pqDelete(nextRequest);
                totalWaitingTime += selectComputerPrint(computers, computerNumber, nextRequest);
                currentTime = findShortestTime(computers, computerNumber);
            }

            requests.pqInsert(requestArr[i]);
            //cout << "request " << i + 1 << " arrived." << endl;
        }
    }


    while(!requests.pqIsEmpty()) {
        Request nextRequest;
        requests.pqDelete(nextRequest);
        totalWaitingTime += selectComputerPrint(computers, computerNumber, nextRequest);
    }


    delete[] computers;
    currentTime = 0;
    return totalWaitingTime/numberOfRequests; //average waiting time
}


int Simulator::selectComputer(Computer* arr , int compSize, Request aRequest) {

    int requestTime = aRequest.getRequestTime();
    int indexShortestTime;
    int shortestTime;

    for(int i = 0; i < compSize; i++) {

        if(i == 0) {
            shortestTime = arr[i].getCurrentTime();
            indexShortestTime = 0;
        }
        else if(arr[i].getCurrentTime() < shortestTime) {
            shortestTime = arr[i].getCurrentTime();
            indexShortestTime = i;
        }

        //if you found a idle computer, give the duty to it
        if(arr[i].getCurrentTime() <= requestTime) {
            return arr[i].giveDuty(aRequest); //It will return 0, no waiting time
        }
    }

    //if you came here, this means all computers are working,
    //find which one will finish it's work first, and give the duty to it.

    //the one with the shortest currentTime will finish it's work first
    //we already find the index of it.

    return arr[indexShortestTime].giveDuty(aRequest);
}

int Simulator::selectComputerPrint(Computer* arr , int compSize, Request aRequest) {

    int requestTime = aRequest.getRequestTime();
    int indexShortestTime;
    int shortestTime;
    int waitingTime;


    for(int i = 0; i < compSize; i++) {

        if(i == 0) {
            shortestTime = arr[i].getCurrentTime();
            indexShortestTime = 0;
        }
        else if(arr[i].getCurrentTime() < shortestTime) {
            shortestTime = arr[i].getCurrentTime();
            indexShortestTime = i;
        }

        //if you found a idle computer, give the duty to it
        if(arr[i].getCurrentTime() <= requestTime) {
            waitingTime = arr[i].giveDuty(aRequest); //It will return 0, no waiting time
            cout << "Computer " << i << " takes request " << aRequest.getId() << " at ms " << requestTime;
            cout << " (wait: "<< waitingTime << " ms)" << endl;
            return waitingTime;
        }
    }

    //if you came here, this means all computers are working,
    //find which one will finish it's work first, and give the duty to it.

    //the one with the shortest currentTime will finish it's work first
    //we already find the index of it.


    int temp = arr[indexShortestTime].getCurrentTime();
    waitingTime =  arr[indexShortestTime].giveDuty(aRequest);
    cout << "Computer " << indexShortestTime << " takes request " << aRequest.getId() << " at ms " << temp;
    cout << " (wait: " << waitingTime << " ms)" << endl;

    return waitingTime;
}


int Simulator::findShortestTime(Computer* arr , int compSize) {

    int shortestTime;
    for(int i = 0; i < compSize; i++) {
        if(i == 0) {
            shortestTime = arr[i].getCurrentTime();
        }
        else if(arr[i].getCurrentTime() < shortestTime) {
            shortestTime = arr[i].getCurrentTime();
        }
    }

    return shortestTime;
}
