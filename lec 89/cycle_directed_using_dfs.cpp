#include<unordered_map>
#include<iostream>
using namespace std;
#include<list>
#include<iostream>
#include<vector>
#include<queue>

bool isCycleDFS(int node ,  unordered_map<int,bool> &visited,unordered_map<int,bool> &DFSvisited,
                unordered_map<int,list<int>> &adj){
    visited[node] = true;
    DFSvisited[node]= true;

    for(auto neighbour : adj[node]){
      if(!visited[neighbour]){
        bool iscycle = isCycleDFS(neighbour,visited,DFSvisited,adj);
        if(iscycle) return true;
      }
      else if(DFSvisited[neighbour]){
        // visited but not dfsvisited
        return true;
      }
    }
    DFSvisited[node] = false;
    return false;

                }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  //convert to adj list
  unordered_map<int,list<int>> adj;
  for(int i = 0; i<edges.size() ;i++){
    int u = edges[i].first;
    int v= edges[i].second;

    adj[u].push_back(v);
  }

  // main part
  unordered_map<int,bool> visited;
  unordered_map<int,bool> DFSvisited;
  // if disconnected graph
  for(int i=1 ;i<=n;i++){
    if(!visited[i]){
      bool CycleDeteced = isCycleDFS(i,visited,DFSvisited,adj);
      if(CycleDeteced) return true;
    }
  }
  return false;
}