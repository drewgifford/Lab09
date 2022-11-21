#include "Graph.h"
#include "Edge.h"

#include <vector>
#include <iostream>

using namespace std;

Graph::Graph(int size) : m_size(size) {

    for(int i = 0; i < m_size; i++){
        m_matrix.push_back(vector<int>(m_size));
    }


}

Graph::~Graph() {};

void Graph::addEdge(Edge edge){

    int i,j;
    tie(i,j) = edge.getTuple();

    if (i > m_size || j > m_size) throw "Edge index out of range";
    m_matrix[i][j] = 1;

}

void Graph::removeEdge(Edge edge){
    
    int i,j;
    tie(i,j) = edge.getTuple();

    if (i > m_size || j > m_size) throw "Edge index out of range";
    m_matrix[i][j] = 0;

}

vector<int> Graph::outEdges(int i){
    
    if (i > m_size) throw "Edge index out of range";

    vector<int> edges;
    for(int j = 0; j < m_size; j++){
        if (m_matrix[i][j] == 1) edges.push_back(j);
    }

    return edges;

}

vector<int> Graph::inEdges(int j){
    
    if (j > m_size) throw "Edge index out of range";

    vector<int> edges;
    for(int i = 0; i < m_size; i++){
        if (m_matrix[i][j] == 1) edges.push_back(i);
    }

    return edges;

}

bool Graph::hasEdge(Edge edge){

    int i,j;
    tie(i,j) = edge.getTuple();

    if (i > m_size || j > m_size) throw "Edge index out of range";
    return m_matrix[i][j] == 1;


}

void Graph::printAdjacencyMatrix(){

    for(int i = 0; i < m_size; i++){

        for (int j = 0; j < m_size; j++){
            cout << to_string(m_matrix[i][j]) << " ";
        }

        cout << endl;
    }

}