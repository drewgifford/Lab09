#pragma once
#include <tuple>
#include <string>
using namespace std;

class Edge {
    public:

        Edge(int, int);
        Edge(tuple<int, int>);

        int getI();
        int getJ();

        tuple<int, int> getTuple();

        string toString();

    private:
        int i;
        int j;
};