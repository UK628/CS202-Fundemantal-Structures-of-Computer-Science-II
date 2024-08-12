#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
//#include "PriorityQueue.h"
using namespace std;


/*
* Title: CS202 Spring 2022
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 4
* Description: Undirected weighted graph, adjacency list representation used.
* And Dijkstra's shortest Path and Primps algorithm used in this class.
*/
class Graph
{
    public:
        //friend class heap
        Graph(const int numberOfVertices);
        ~Graph();

        void insertEdge(int v1, int v2, int weight, bool done);
        void listEdges(int v);
        //void delete
        void shortestPath(int v1, int v2);
        void minimizeCost();
        int  numFlight(int v1);

    private:
        struct GraphNode {
            //friend class Graph;
            int from;
            int name;
            int weight;
            GraphNode* nextNode;
        };

        struct Vertice {
            //int name;
            GraphNode* head;
            int size;
            //bool visited; //for shortest path alg.
            //int weight;   //for shortest path alg.
        };

        void display(GraphNode* arr, int sourceIndex, int index); //helper method for shortestPath
        void primsAlgorithm();
        int calculateCost();
        void addEdge(Vertice* arr, GraphNode* edge, bool done); //helper method

        Vertice* graph;
        int numVertices;
        //int numberOfEdges;
};

#endif // GRAPH_H
