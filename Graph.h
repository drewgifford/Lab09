#pragma once

#include "Edge.h"
#include <vector>

using namespace std;

class Graph {

    public:

        Graph(int size);
        ~Graph();

        void addEdge(Edge edge);
        void removeEdge(Edge edge);
        vector<int> outEdges(int i);
        vector<int> inEdges(int i);

        bool hasEdge(Edge edge);

        void printAdjacencyMatrix();

    private:
        vector<vector<int>> m_matrix;
        int m_size;


};