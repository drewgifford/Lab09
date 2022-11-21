#include "Edge.h"
#include <tuple>

using namespace std;

Edge::Edge(int i, int j) : i(i), j(j){}

Edge::Edge(tuple<int, int> coordinates) {

    tie(i, j) = coordinates;

}

int Edge::getI() { return i; }
int Edge::getJ() { return j; }

tuple<int, int> Edge::getTuple() {
    return make_tuple(i, j);
}

string Edge::toString(){
    return "(" + to_string(i) + ", " + to_string(j) + ")";
}