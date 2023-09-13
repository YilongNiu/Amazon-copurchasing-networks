#pragma once
#include <queue>
#include "Graph.h"
#include <vector>
#include <unordered_map>

using namespace std;

class BFS{
  public:
    /**
     * @brief Construct a new BFS object
     * 
     * @param g the graph used for traversal (passed as a pointer)
     */
    BFS(Graph* g);

    /**
     * @brief Traverse the graph using BFS. It will print out the result of the traversal on the screen
     * 
     * @param node starting node for the traversal
     * @return vector<int>  vector of the traversed path 
     */
    vector<int> traversal(int node);
    
    /**
     * @brief Set the depth for a node
     * 
     * @param node  node that needs to be set depth
     * @param depth  depth that we want to set to the node
     */
    void setNodeDepth(int node, int depth);
    
    /**
     * @brief Get the depth of a node
     * 
     * @param node  node that we want the depth from
     * @return int  depth of the node  
     */
    int getNodeDepth(int node);
    
    /**
     * @brief Set the parent for a node 
     * 
     * @param node  node that needs to be set parent
     * @param parent  parent that we want to set to the node
     */
    void setNodeParent(int node, int parent);
    
    /**
     * @brief Get the parent of a node 
     * 
     * @param node  node that we want the parent from
     * @return int  id of the parent of the node 
     */
    int getNodeParent(int node);
    
      
  private:
    Graph* graph;
    std::queue<int> q;
};