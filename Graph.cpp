#include "Graph.h"
using namespace std;

Edge::Edge(int node1, int node2) {
  _from = node1; // set id for source node
  _to = node2; // set id for destination node
  _isVisited = false; // initially set all edges as unvisited
}

int Edge::getNext() {
  return _to;
}

Node::Node() {
  _isNodeVisited = false; // initially set all nodes as unvisited
  _depth = -1; // preset depth for all nodes as -1
}

Node::~Node() {
  for (size_t i = 0; i < adjEdges.size(); i++) {
    delete adjEdges[i];
  }
}

Graph::Graph() {
 
}

Graph::~Graph() {
  for (auto it = nodeMap.begin(); it != nodeMap.end();) {
    delete it->second;
    it->second = NULL;
    it = nodeMap.erase(it);
  }
}

void Graph::nodeInit() {
  for (auto it = nodeMap.begin(); it != nodeMap.end(); it++) {
    it->second->_isNodeVisited = false;
    it->second->_depth = -1;
  }
}

void Graph::setNodeLabel(int node, bool status) {
  if (nodeMap.find(node) != nodeMap.end())
    nodeMap.find(node)->second->_isNodeVisited = status; 
}

bool Graph::getNodeLabel(int node) {
    return nodeMap.find(node)->second->_isNodeVisited;  
}


void Graph::addEdge(int node1, int node2) {
  if(node1 > 30000 || node2 > 30000){
    return;
  }
  Edge* edge = new Edge(node1, node2);
  if (nodeMap.find(node1) == nodeMap.end()) { // set new node and edge accordingly
    Node* fromNode = new Node();
    fromNode->adjEdges.push_back(edge);
    fromNode->adjNodes.push_back(node2);
    nodeMap.insert(make_pair(node1, fromNode));
  } else {
    Node* fromNode = nodeMap.find(node1)->second;
    fromNode->adjEdges.push_back(edge);
    fromNode->adjNodes.push_back(node2);
  }
  if (nodeMap.find(node2) == nodeMap.end()) {
    Node* toNode = new Node();
    nodeMap.insert(make_pair(node2, toNode));
  }
}

vector<Edge*> Graph::getAdjEdges(int node) {
  if (nodeMap.find(node) == nodeMap.end()) return vector<Edge*>();
  else {
    return nodeMap.find(node)->second->adjEdges;
  }
}

vector<int> Graph::getAdjNodes(int node) {
  if (nodeMap.find(node) == nodeMap.end()) return vector<int>();
  else {
    return nodeMap.find(node)->second->adjNodes;
  }
}