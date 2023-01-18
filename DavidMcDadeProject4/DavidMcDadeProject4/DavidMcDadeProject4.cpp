// DavidMcDadeProject4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program does a Breadth-first search of the 10.10.2 graph. The graph is implemented with a 2D array.
// The only output is a list of the vertex names in order from least to greatest distance from the starting 
// vertex with their distance to the starting vertex printed next to it.

#include <iostream>
#include <cctype>
#include "arrqueue.h"

using namespace std;
const int NumVertex = 7;



void BreadthFirstSearch(int Graph[NumVertex][NumVertex], int startVertex, string VertexNames[]);

int main(void)
{
    int Graph[NumVertex][NumVertex] =           // The Graph from 10.10.2 represented in an adjacency matrix
    {
    0, 1, 1, 0, 0, 0, 0,
    1, 0, 0, 0, 1, 0, 0,
    1, 0, 0, 1, 1, 0, 0,
    0, 0, 1, 0, 0, 1, 0,
    0, 1, 1, 0, 0, 1, 0,
    0, 0, 0, 1, 1, 0, 1,
    0, 0, 0, 0, 0, 1, 0
    };

    string VertexNames[NumVertex] = { "Joe", "Eva", "Taj", "Chen", "Lily", "Jun", "Ken"};     
    string startName = "";
    int startVertex = -1;
    while (startVertex == -1) {
        cout << "Enter A Person As The Starting Point(Joe, Eva, Taj, Chen, Lily, Jun, or Ken): ";
        cin >> startName;
        for (int x = 0; x < NumVertex; x++) {
            if (VertexNames[x] == startName)
                startVertex = x;
        }
        if (startVertex == -1)
            cout << "Please use a name from the list." << endl;
    }
    
    BreadthFirstSearch(Graph,startVertex,VertexNames);
    
    return 0;
}

// Given: A graph's adjacency matrix, a starting vertex, and an array of names associated with the vertexes
// Task: To perform a Breadth First Search through the graph, meaning to search through the vertexes in order 
//       from least distance to most distance from the start vertex, and print out a list with the information on the distances of each vertex, in order from least to greatest distance.
// Return: An output showing the vertexes in order from least to greatest distance.
void BreadthFirstSearch(int Graph[NumVertex][NumVertex], int startVertex, string VertexNames[]) {
    ArrQueClass frontierQueue;
    int currentV = -1;
    int VertexDistance[NumVertex] = { 0, 0, 0, 0, 0, 0, 0 };
    frontierQueue.Insert(startVertex);
    bool discoveredSet[NumVertex] = { false, false, false, false, false, false, false };
    discoveredSet[startVertex] = true;

    while (frontierQueue.Empty() == false) {
        frontierQueue.Remove(currentV);         //removes the first vertex in the queue and places it in currentV
        for (int n=0; n < NumVertex; n++) {     
            if (Graph[currentV][n] == 1) {      // if there exists an edge between the current vertex another vertex
                if (discoveredSet[n] == false) {    // and the other vertex has not been visited yet
                    frontierQueue.Insert(n);     // insert the new vertex onto the frontierQueue to be later searched
                    discoveredSet[n] = true;     // update the discovered set to say we have visited this vertex
                    VertexDistance[n] = VertexDistance[currentV] + 1;  // set the vertex's distance from the starting point which is equal to the current vertex's distance + 1
                }
            }
        }
    }
    cout << "Breadth-first search traversal\nStart Vertex: " << VertexNames[startVertex] << endl;  // print out the distance information in least distance to greatest distance order
    cout << VertexNames[startVertex] << ": " << VertexDistance[startVertex] << endl;
    for (int x = 1; x <= VertexDistance[currentV]; x++) {
        for (int y = 0; y < NumVertex; y++) {
            if (VertexDistance[y] == x)
                cout << VertexNames[y] << ": " << VertexDistance[y] << endl;
        }
    }
}


