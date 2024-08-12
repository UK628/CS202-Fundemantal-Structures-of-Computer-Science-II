#include "Graph.h"

/*
* Title: CS202 Spring 2022
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 4
* Description: Undirected weighted graph, adjacency list representation used.
* And Dijkstra's shortest Path and Primps algorithm used in this class.
*/
Graph::Graph(const int n)
{
    graph = new Vertice[n];
    //numberOfEdges = 0;

    for(int i = 0; i < n; i++) {
        //graph[i].name = i;
        graph[i].size = 0;
        graph[i].head = NULL;
        //graph[i].visited = false;
    }

    numVertices = n;
}

Graph::~Graph()
{
    for(int i = 0; i < numVertices; i++) {
        GraphNode* currPtr = graph[i].head;
        GraphNode* prevPtr;

        while(currPtr != NULL) {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode;

            delete prevPtr;
        }
    }

    delete[] graph;
}

int Graph::numFlight(int v1) {
    return graph[v1].size;
}


void Graph::insertEdge(int v1, int v2, int weight, bool done) {

    graph[v1].size++;
    GraphNode* nodePtr = graph[v1].head;

    //first node
    if(nodePtr == NULL) {
        graph[v1].head = new GraphNode;
        graph[v1].head->name = v2;
        graph[v1].head->weight = weight;
        graph[v1].head->from = v1;
        graph[v1].head->nextNode = NULL;

        //undirected graph
        if(done != 1) {
        insertEdge(v2, v1, weight, 1);
        }

        return;
    }


    //add the new node to the begging of the linked list
    graph[v1].head = new GraphNode;
    graph[v1].head->name = v2;
    graph[v1].head->weight = weight;
    graph[v1].head->from = v1;
    graph[v1].head->nextNode = nodePtr; //connect old head


    //undirected graph
    if(done != 1) {
        insertEdge(v2, v1, weight, 1);
    }
}


void Graph::listEdges(int v) {

    GraphNode* nodePtr = graph[v].head;
    if (nodePtr == NULL) {
        cout << "no flight from " << v << "." << endl;
        return;
    }

    cout << "List of flights from " << v << ":" << endl;

    //first node
    cout << "   " << v << " to " << nodePtr->name;
    cout << " with a duration of " <<  nodePtr->weight;
    cout << "." << endl;

    while(nodePtr->nextNode != NULL) {
        cout << "   " << v  << " to " << nodePtr->nextNode->name;
        cout << " with a duration of " <<  nodePtr->nextNode->weight;
        cout << "." << endl;

        nodePtr = nodePtr->nextNode;
    }

    cout<< "   Total numbers of flights: " << graph[v].size << endl;
}

void Graph::shortestPath(int v1, int v2) {

    const int DUMMY_INFINITY = 2000000000;
    int* weightArr = new int[numVertices];
    bool* vertexSet = new bool[numVertices];
    GraphNode* previousArr = new GraphNode[numVertices];

    GraphNode* nodePtr = graph[v1].head;
    int smallest;
    int smallestIndex;

    for(int i = 0; i < numVertices; i++) {
        vertexSet[i] = 0; // initially vertexSet is empty
        if(graph[i].size == 0) {
            //disconnected node mark it as visited
            vertexSet[i] = 1;
        }
    }

    vertexSet[v1] = 1; //v1 in vertexSet


    //initialize the weight array, assume that we have no edge at first.
    for(int i = 0; i < numVertices; i++) {
        weightArr[i] = DUMMY_INFINITY;
    }

    weightArr[v1] = 0;


    //check for the edges
    while(nodePtr != NULL) {
        if(nodePtr->weight < weightArr[nodePtr->name]) {
            weightArr[nodePtr->name] = nodePtr->weight;
            previousArr[nodePtr->name] = *nodePtr;
        }

        nodePtr = nodePtr->nextNode;
    }


    /*
    //print weight arr
    for(int i = 0; i < numVertices; i++) {
        cout << weightArr[i] << ", ";

    }
    cout<< endl;
    */

    for(int x = 2; x < numVertices; x++) {

        smallest = DUMMY_INFINITY;
        smallestIndex = -1;
        for(int i = 0; i < numVertices; i++) {
            if( (weightArr[i] < smallest) & (vertexSet[i] == 0))  {
                smallest = weightArr[i];
                smallestIndex = i;
            }
        }

        if(smallestIndex == -1) {
            continue;
        }

        //add the smallest to vertexSet
        vertexSet[smallestIndex] = 1;
        nodePtr = graph[smallestIndex].head;


        //check for the edges
        while(nodePtr != NULL) {
            if((vertexSet[nodePtr->name] == 0) && ( weightArr[nodePtr->name] > (weightArr[smallestIndex] + nodePtr->weight))) {
                previousArr[nodePtr->name] = *nodePtr;
                weightArr[nodePtr->name] = weightArr[smallestIndex] + nodePtr->weight;
            }

            nodePtr = nodePtr->nextNode;
        }
    }

    /*
    //print weight arr
    for(int i = 0; i < numVertices; i++) {
        cout << weightArr[i] << ", ";

    }
    cout<< endl;
    */

    if(weightArr[v2] == DUMMY_INFINITY) {

        cout<< "No paths from " << v1 << " to " << v2 <<endl;

        delete[] weightArr;
        delete[] vertexSet;
        delete[] previousArr;
        return;
    }

    cout << "The shortest path from " << v1 << " to " << v2 << ": " << endl;

    //display shortestPath
    display(previousArr, v1, v2);

    cout << "   Total shortest path duration: " << weightArr[v2] << endl;

    delete[] weightArr;
    delete[] vertexSet;
    delete[] previousArr;
}

void Graph::display(GraphNode* arr, int sourceIndex, int index) {

    //base case
    if(index == sourceIndex) {
        return;
    }

    //display in reverse order
    display(arr, sourceIndex, arr[index].from);
    GraphNode curr = arr[index];

    cout << "   " << curr.from << " to " << curr.name;
    cout << " with a duration of " <<  curr.weight;
    cout << "." << endl;
}

void Graph:: minimizeCost() {

    cout << "Total cost of operations before minimization: " << calculateCost() << endl;
    primsAlgorithm();
    cout << "Total cost of operations after minimization: " << calculateCost() << endl;

}


int Graph:: calculateCost() {

    int totalCost = 0;

    for(int i = 0; i < numVertices; i++) {
        GraphNode* nodePtr = graph[i].head;

        while(nodePtr != NULL) {
            totalCost += nodePtr->weight;
            nodePtr = nodePtr->nextNode;
        }
    }

    return totalCost/2;
}

void Graph::primsAlgorithm() {
    const int DUMMY_INFINITY =2000000000;
    bool* vertexSet = new bool[numVertices];
    Vertice* newGraph;
    int currSize = 0;
    GraphNode* smallestPtr;
    GraphNode DummyNode;
    DummyNode.weight = DUMMY_INFINITY;


    for(int i = 0; i < numVertices; i++) {
        vertexSet[i] = 0; // initially vertexSet is empty
    }

    //add first vertex to the vertexset(vertex v)(means visited and in the graph)
    vertexSet[0] = 1;
    currSize++;//number of visited noods(current vertices in the arr)

    //since I need to maintain the order of the vertices in the Vertice arr, I have to add all vertices in here,
    //but I won't count all as visited( in spanning tree) yet.
    newGraph = new Vertice[numVertices];
    for(int i = 0; i < numVertices; i++) {
        newGraph[i].head = NULL; // no edge at the beginning
        newGraph[i].size = 0;
    }


    //while there are unvisited vertices
    for(int x = 1; x < numVertices; x++) {

        smallestPtr = &DummyNode;

        //find least-cost edge(from v to u)
        for(int i = 0; i < numVertices; i++) {
            GraphNode* nodePtr = graph[i].head;

            while((nodePtr != NULL) && (vertexSet[i] == 1)) {
                if((vertexSet[nodePtr->name] == 0) & (nodePtr->weight < smallestPtr->weight) ) {
                    smallestPtr = nodePtr;
                }

                nodePtr = nodePtr->nextNode;
            }
        }

        if(smallestPtr == &DummyNode) {
            //no edge remained
            break;
        }

        //mark u as visited
        vertexSet[smallestPtr->name] = 1;

        //add vertex u and the edge to the new graph
        addEdge(newGraph,smallestPtr,0);
        currSize++;
    }

    //delete old graph
    for(int i = 0; i < numVertices; i++) {
        GraphNode* currPtr = graph[i].head;
        GraphNode* prevPtr;

        while(currPtr != NULL) {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode;

            delete prevPtr;
        }
    }

    delete[] graph;
    delete[] vertexSet;

    //give the address of new graph to the "graph"
    graph = newGraph;
}

void Graph::addEdge(Vertice* arr, GraphNode* edge, bool done) {
    arr[edge->from].size++;
    GraphNode* nodePtr = arr[edge->from].head;

    if(nodePtr == NULL) {
        arr[edge->from].head = new GraphNode;
        arr[edge->from].head->name = edge->name;
        arr[edge->from].head->weight = edge->weight;
        arr[edge->from].head->from = edge->from;
        arr[edge->from].head->nextNode = NULL;

        //undirected graph
        if(done != 1) {
            GraphNode* reverseEdge = new GraphNode;
            reverseEdge->weight = edge->weight;
            reverseEdge->from = edge->name;
            reverseEdge->nextNode = NULL;
            reverseEdge->name = edge->from;

            addEdge(arr, reverseEdge, 1);
            delete reverseEdge;
        }

        return;
    }


    arr[edge->from].head = new GraphNode;
    arr[edge->from].head->name = edge->name;
    arr[edge->from].head->weight = edge->weight;
    arr[edge->from].head->from = edge->from;
    arr[edge->from].head->nextNode = nodePtr;

    //undirected graph
    if(done != 1) {
            GraphNode* reverseEdge = new GraphNode;
            reverseEdge->weight = edge->weight;
            reverseEdge->from = edge->name;
            reverseEdge->nextNode = NULL;
            reverseEdge->name = edge->from;

            addEdge(arr, reverseEdge , 1);
            delete reverseEdge;
    }

}

