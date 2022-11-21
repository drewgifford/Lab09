// tests.cpp
#include <gtest/gtest.h>

#include "Graph.h"

TEST(Graph, AddEdge1){
    Graph graph(10);

    graph.addEdge(Edge(1,1));

    ASSERT_TRUE(graph.hasEdge(Edge(1,1)));
}
TEST(Graph, AddEdge2){
    Graph graph(10);

    graph.addEdge(Edge(5,7));
    graph.addEdge(Edge(2,3));

    ASSERT_TRUE(graph.hasEdge(Edge(5,7)));
    ASSERT_TRUE(graph.hasEdge(Edge(2,3)));
}


TEST(Graph, RemoveEdge1){
    Graph graph(10);

    graph.addEdge(Edge(1,1));
    graph.removeEdge(Edge(1,1));

    ASSERT_FALSE(graph.hasEdge(Edge(1,1)));
}
TEST(Graph, RemoveEdge2){
    Graph graph(10);

    graph.addEdge(Edge(5,7));
    graph.addEdge(Edge(2,3));

    graph.removeEdge(Edge(5,7));

    ASSERT_FALSE(graph.hasEdge(Edge(5,7)));
    ASSERT_TRUE(graph.hasEdge(Edge(2,3)));
}


TEST(Graph, OutEdges1){
    Graph graph(10);

    graph.addEdge(Edge(5,7));
    graph.addEdge(Edge(2,3));

    ASSERT_EQ(graph.outEdges(5), vector<int>{7});
}
TEST(Graph, OutEdges2){
    Graph graph(10);

    graph.addEdge(Edge(5,3));
    graph.addEdge(Edge(2,7));

    ASSERT_EQ(graph.outEdges(2), vector<int>{7});
}

TEST(Graph, InEdges1){
    Graph graph(10);

    graph.addEdge(Edge(5,7));
    graph.addEdge(Edge(2,3));

    ASSERT_EQ(graph.inEdges(7), vector<int>{5});
}
TEST(Graph, InEdges2){
    Graph graph(10);

    graph.addEdge(Edge(5,3));
    graph.addEdge(Edge(2,7));

    ASSERT_EQ(graph.inEdges(7), vector<int>{2});
}


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}