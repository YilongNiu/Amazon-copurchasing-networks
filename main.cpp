#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include "Graph.h"
#include "BFS.h"
#include "SCC.h"
#include "ShortestPath.h"
 
using namespace std;

int main(int argc, char* argv[]) {
  vector<int> vectorRepr = file_to_vector(argv[1]);
  
  Graph* graph = new Graph();
  int size = vectorRepr.size();
  for(int i = 0; i < size/2; i++){
    graph->addEdge(vectorRepr[i*2],vectorRepr[i*2 + 1]);
  }
  
// ShortestPath
 if(string(argv[2]) == "ShortestPath"){
  ShortestPath sh(graph);
  int temp = sh.getShortestDistance(stoi(argv[3]),stoi(argv[4]));
  cout << temp << endl;
  vector<int> v = sh.getShortestPath(stoi(argv[3]),stoi(argv[4]));
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
 }
 
// BFS traversal

  if(string(argv[2]) == "BFS"){ 
    BFS bfs(graph);
    vector<int> traversal = bfs.traversal(stoi(argv[3]));
    for(int i = 0; i < traversal.size(); i++){
       cout << traversal[i] << " "; 
    }
    cout << endl;
  }


// Strongly Connected Components(SCC) 
if(string(argv[2]) == "SCC"){
  SCC scc(graph);
  vector<vector<int>> out = scc.findSccs();
  for(int i = 0; i < out.size(); i++){
    cout << out[i].size() << " ";
    for(int j = 0; j < out[i].size(); j++){
      cout << out[i][j] << " ";
    }
    cout << endl;
  }
}
  delete graph;
  return 0;

}

