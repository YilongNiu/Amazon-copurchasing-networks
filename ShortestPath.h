#pragma once
#include "Graph.h"
#include "BFS.h"
#include <vector>

using namespace std;

class ShortestPath{
public:
  /**
   * @brief Construct a new ShortestPath object
   * 
   * @param g the graph used for traversal (passed as a pointer)
   */
  ShortestPath(Graph* g);
  
  /**
   * @brief Get the shortest distance from node1 to node2
   * 
   * @param node1  node acts as a starting point
   * @param node2  node acts as a destination point
   * @return int  shortest distance between the two nodes 
   */
  int getShortestDistance(int node1, int node2);
  
  /**
   * @brief Get the shortest path from node1 to node2. For example, if the shortest path from
   * @brief 1 to 4 is 1->3->4, then the output will be a vector that contains 1,3,4 in sequence
   * 
   * @param node1  node acts as a starting point
   * @param node2  node acts as a destination point
   * @return vector<int>  a vector that contains the shortest path from node1 to node2 
   */
  vector<int> getShortestPath(int node1, int node2);
  
private:
  Graph* graph;
};