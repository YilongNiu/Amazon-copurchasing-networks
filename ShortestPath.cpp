#include "ShortestPath.h"
#include <vector>


using namespace std;

ShortestPath::ShortestPath(Graph* g){
  graph = g;
}

int ShortestPath::getShortestDistance(int node1, int node2){
  BFS bfs(graph);
  vector<int> temp = bfs.traversal(node1);
  return graph->nodeMap.find(node2)->second->_depth;
}

vector<int> ShortestPath::getShortestPath(int node1, int node2){
  BFS bfs(graph);
  vector<int> temp = bfs.traversal(node1);
  vector<int> out;
  if(graph->nodeMap.find(node2)->second->_depth == -1){
    return out;
  }
  int parent = graph->nodeMap.find(node2)->second->_parent;
  int curr = node2;
  while(parent != -1){
    out.push_back(curr);
    curr = parent;
    parent = graph->nodeMap.find(parent)->second->_parent;
  }
  out.push_back(curr);
  reverse(out.begin(),out.end());
  return out;
}