#include "SCC.h"
#include "Graph.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

SCC::SCC(Graph* g){
  graph = g;
  int size = getSize(g->nodeMap);
  for(int i = 0; i < size; i++){
    graph->nodeMap.find(i)->second->_id = -1;
    graph->nodeMap.find(i)->second->_onstack = false;
  }
}

int SCC::getSize(unordered_map<int,Node*> map){
  return map.size();
}

vector<vector<int>> SCC::findSccs(){
  int size = getSize(graph->nodeMap);
  int sccCount = 0;
  vector<int> low(size);
  for(int i = 0; i < size; i++){
    low[i] = 0;
  }
  for(int i = 0; i < size; i++){
    if(graph->nodeMap.find(i)->second->_id == -1){
      DFS(i,low,sccCount);
    }
  }
  cout << sccCount << endl;
  unordered_map<int,bool> flag;
  for(int i = 0; i < size; i++){
    flag[i] = false;
  }
  vector<vector<int>> sccs;
  int temp;
  for(int i = 0; i < size; i++){
    if(flag.find(i)->second){
      continue;
    }
    vector<int> curr;
    temp = low[i];
    flag.find(i)->second = true;
    curr.push_back(i);
    for(int j = 0; j < size; j++){
      if(temp == low[j] && i != j){
        curr.push_back(j);
        flag.find(j)->second = true;
      }
    }
    sccs.push_back(curr);
  }
  return sccs;
}

void SCC::DFS(int & i, vector<int> & low, int & sccCount){
  s.push(i);
  graph->nodeMap.find(i)->second->_onstack = true;
  low[i] = graph->nodeMap.find(i)->second->_id = i;
  
  
  vector<int> adj = graph->getAdjNodes(i);
  for(auto it = adj.begin(); it != adj.end(); ++it){
    if(graph->nodeMap.find(*it)->second->_id == -1){
      DFS(*it,low,sccCount);
    }
    if(graph->nodeMap.find(*it)->second->_onstack){
      low[i] = min(low[i],low[*it]);
    }
  }
  
  if(graph->nodeMap.find(i)->second->_id == low[i]){
    while(s.top() != i){
      int top = s.top();
      graph->nodeMap.find(top)->second->_onstack = false;
      s.pop();
    }
    
    sccCount++;
  }
  return;
}