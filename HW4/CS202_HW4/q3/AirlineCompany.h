#ifndef AIRLINECOMPANY_H
#define AIRLINECOMPANY_H
#include "Graph.h"


/*
* Title: CS202 Spring 2022
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 4
* Description: The Company Class, (The methods implemented in the underlying graphs)
*/
class AirlineCompany
{
    public:
        AirlineCompany(int numberOfAirports);
         ~AirlineCompany();

         void insertNewFlight(int airport1, int airport2, int duration);
         void listFlights(int airport);
         void findShortestPath(int from, int to);
         void minimizeTotalCost();

    private:
        Graph* theGraph;
};

#endif // AIRLINECOMPANY_H
