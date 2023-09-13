#include "Graph.h"
#include "BFS.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

BFS::BFS(Graph* g){
  graph = g;
}


vector<int> BFS::traversal(int source){
  
  graph->nodeInit(); 

  graph->setNodeLabel(source, true); // set the source node accordingly
  setNodeDepth(source,0);
  setNodeParent(source,-1);
  q.push(source);
  vector<int> trav;
  
  while(!q.empty()){ // bfs traversal
    int current = q.front();
    int parentDepth = getNodeDepth(current);
    trav.push_back(current);

    q.pop();
    vector<int> adjNodes = graph->getAdjNodes(current);
    for(auto it = adjNodes.begin(); it != adjNodes.end(); ++it){
      if (graph->getNodeLabel(*it) == false) {
        graph->setNodeLabel(*it, true);
        setNodeDepth(*it,parentDepth + 1);
        setNodeParent(*it,current);
        q.push(*it);
      }
    }
  }
  return trav;
}

void BFS::setNodeDepth(int node, int depth) {
  if (graph->nodeMap.find(node) != graph->nodeMap.end())
    graph->nodeMap.find(node)->second->_depth = depth;
}

int BFS::getNodeDepth(int node) {
  return graph->nodeMap.find(node)->second->_depth;
}

void BFS::setNodeParent(int node, int parent) {
  if (graph->nodeMap.find(node) != graph->nodeMap.end())
    graph->nodeMap.find(node)->second->_parent = parent;
}

int BFS::getNodeParent(int node) {
  return graph->nodeMap.find(node)->second->_parent;
}