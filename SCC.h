#pragma once
#include "Graph.h"
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class SCC{
public:
  /**
   * @brief Construct a new Strongly Connected Component(SCC) object
   * 
   * @param g the graph used for traversal (passed as a pointer)
   */
  SCC(Graph* g);
  
  /**
   * @brief Get the size of an unordered map for a graph
   * 
   * @param map  unordered map for a graph
   * @return int  size of the unordered map
   */
  int getSize(unordered_map<int,Node*> map);
  
  /**
   * @brief Find a vector of strongly connected components in the form of vector. 
   * 
   * @return vector<vector<int>>  vector of a group of strongly connected components in vector form. For example, if we have
   * a group of strongly connected components as 1,2,3; 4,5,7; 8,10,12, then we will have an output of <<1,2,3>,<4,5,7>,<8,10,12>>
   */
  vector<vector<int>> findSccs();
  
  /**
   * @brief Do a DFS traversal of the graph to find the stongly connected components
   * 
   * @param i  id for the starting item
   * @param low  vector of low number for all the items
   * @param sccCount  counter of strongly connected components in the graph
   */
  void DFS(int & i, vector<int> & low, int & sccCount);
  
private:
  Graph* graph;
  stack<int> s;
};