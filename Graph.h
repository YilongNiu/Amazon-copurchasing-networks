#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

class Edge {
  public :
    Edge(int node1, int node2);
    int getNext();
  private:
    int _from;
    int _to;
    bool _isVisited;
};

struct Node {
  Node();
  ~Node();
  vector<Edge*> adjEdges;
  vector<int> adjNodes;
  bool _isNodeVisited;
  int _depth;
  int _parent;
  int _id;
  bool _onstack;
};

class Graph{
public:
  Graph();
  ~Graph();

  /**
   * @brief nodeInit is a function that initialize the graph
   * for our traversal. It marks every node in the graph as
   * unvisited.
   */
  void nodeInit();

  /**
   * @brief Set the Node Label (Visited or Unvisited)
   * 
   * @param node input node as integer
   * @param status boolean status (true = visited , false = unvisited)
   */
  void setNodeLabel(int node, bool status);

  /**
   * @brief Get the Node Label (Visited or Unvisited)
   * 
   * @param node input node
   * @return true if visited
   * @return false if unvisited
   */
  bool getNodeLabel(int node);
  


  /**
   * @brief addEdge is used to build graph from the dataset
   * each edege is represented by two nodes, source node and destination node. 
   * the edge starts from source node and points to destination node.
   * @param node1 source node of of an edge
   * @param node2 destination node of an edge
   */
  void addEdge(int node1, int node2);

  /**
   * @brief Get the Adjcent Edges of a Given Node
   * 
   * @param node input node as integer
   * @return vector<Edge*> a vector of edge pointers, each starting from the input node  
   */
  vector<Edge*> getAdjEdges(int node);


  /**
   * @brief Get the Adjcent Nodes of a Given Node
   * 
   * @param node input node as integer
   * @return vector<int> a vector of integers, each representing a neighbor of the input node
   */
  vector<int> getAdjNodes(int node);

  /**
   * @brief Unordered map for the whole graph. It couples the id of an item with its corresponding node
   */
  unordered_map<int, Node*> nodeMap;

};

