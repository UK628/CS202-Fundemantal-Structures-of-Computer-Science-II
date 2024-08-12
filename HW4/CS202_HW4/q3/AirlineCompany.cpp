#include "AirlineCompany.h"


/*
* Title: CS202 Spring 2022
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 4
* Description: The Company Class, (The methods implemented in the underlying graphs)
*/
AirlineCompany::AirlineCompany(int numberOfAirports)
{
    theGraph = new Graph(numberOfAirports);
}

AirlineCompany::~AirlineCompany()
{
    delete theGraph;
}

void AirlineCompany:: insertNewFlight(int airport1, int airport2, int duration) {
    theGraph->insertEdge(airport1,airport2,duration,0);

    cout<< "Inserted a new flight between " << airport1 << " and " << airport2 << endl;
    cout<< "    The number of flights from " << airport1 << " is " << theGraph->numFlight(airport1) << endl;
}

void AirlineCompany::listFlights(int airport) {
    theGraph->listEdges(airport);
}

void AirlineCompany::findShortestPath(int from, int to) {
    theGraph->shortestPath(from, to);
}

void AirlineCompany::minimizeTotalCost() {
    theGraph->minimizeCost();
}
