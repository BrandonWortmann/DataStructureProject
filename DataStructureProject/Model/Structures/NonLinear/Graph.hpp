//
//  Graph.hpp
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 3/19/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool adjacencyMatrix [MAXIMUM][MAXIMUM];
    int weightCostMatrix [MACXIMUM][MAXIMUM];
    Type graphData[MAXIMUM];
    int vertexCount;
    void depthFistTraveersal(Graph<Type> & graph, int vertex, bool markedVertices[]);
public:
    Graph()
    
    void addVertex(const Type& value);
    
    void addEdge(int source, int target);
    void addEdgeUndirected(int source, int target);
    void addEdgeCost(int source, int target, int cost);
    
    void removeEdge(int source, int target);
    void removeEdgeUndirected(int source, int target);
    void removeEdgeCost(int source, int target, int cost);
    
    Type& operator [] (int vertex);
    Type operator[](int vertex) const;
    int size() const;
    
    bool hasUndiretedConnection(int source, int target) const;
    bool areConneted(int source, int target) const;
    std::set<int> neighbors(int vertex) const;
    
    void depthFirstTraversal(Graph<Type>  & graph, int vertex);
    void breadthFirstTraversal(Graph<Type> & graph, int vertex);
    int costTraversal(Graph<Type> & grph, int vertex;)
};

#endif /* Graph_hpp */
