#include "Graph.h"
#include "Edge.h"

#include <string>
#include <iostream>
#include <tuple>
#include <fstream>
#include <sstream>

using namespace std;


static string MESSAGE =
"Press 1 to add an edge to graph.\n\
Press 2 remove an edge from graph.\n\
Press 3 Find an edge in the graph.\n\
Press 4 Find the out edges of a vertices\n\
Press 5 Find the in edges of a vertices\n\
Press 6 To Print out Adjacency Matrix\n\
Press 7 to quit.";

Edge getEdgeFromInput(){
    int i, j;

    cout << "I coordinate: ";
    cin >> i;
    cout << "J coordinate: ";
    cin >> j;

    return Edge(i, j);
}

Graph importGraph(int size, ifstream * file){

    Graph graph(size);

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            int d;
            (*file) >> d;

            if (d == 1) graph.addEdge(Edge(i,j));
        }
    }

    return graph;
}



int userInterface(Graph graph){

    while(true){

        cout << MESSAGE << endl;

        int input;
        cin >> input;

        Edge edge(0,0);
        vector<int> vec;

        switch(input){

            case 1: // ADD EDGE
                edge = getEdgeFromInput();
                graph.addEdge(edge);
                break;

            case 2:
                edge = getEdgeFromInput();
                graph.removeEdge(edge);
                break;

            case 3:
                edge = getEdgeFromInput();
                
                if (graph.hasEdge(edge)){
                    cout << "Graph has the edge " << edge.toString() << endl;
                } else {
                    cout << "Graph does not have the edge " << edge.toString() << endl;
                }
                break;

            case 4:
                int i;
                cout << "I Coordinate to get Out Edges: ";
                cin >> i;

                vec = graph.outEdges(i);

                cout << "Out edges of I = " << i << ": ";
                for(int j : vec){
                    cout << j << " ";
                }
                cout << endl;
                break;

            case 5:
                int j;
                cout << "J Coordinate to get In Edges: ";
                cin >> j;

                vec = graph.inEdges(j);

                cout << "Out edges of J = " << j << ": ";
                for(int i : vec){
                    cout << i << " ";
                }
                cout << endl;
                break;

            case 6:
                cout << "Adjacency Matrix:" << endl;
                graph.printAdjacencyMatrix();
                break;

            case 7:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                continue;

        }
        cout << endl;
    }

    cout << "Goodbye!" << endl;

}


int main(int argc, char** argv){

    Graph graph(10);

    // File flag used
    if (argc > 1 && (string) argv[1] == "-f"){

        ifstream file;
        string fileLocation = argv[2];

        file.open(fileLocation);

        string sizeString;
        file >> sizeString;

        cout << sizeString << endl;

        int size = stoi(sizeString);

        graph = importGraph(size, & file);
    }

    userInterface(graph);


}