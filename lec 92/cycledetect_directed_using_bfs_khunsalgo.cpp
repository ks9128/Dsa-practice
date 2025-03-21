#include<unordered_map>
#include<iostream>
using namespace std;
#include<list>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>


int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
  // Write your code here 
    unordered_map<int,list<int>> adj;
    for(int i=0 ;i<edges.size(); i++){
        int u= edges[i].first -1; // as this code was for nodes starting from 0 here its start from 1
        int v= edges[i].second -1;
         
        adj[u].push_back(v);
    }
   
    
    //calc in degree
    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    //0 indegree walo ko push kro
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0) q.push(i);
    }

    // do bfs
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
    //inc cnt
        cnt++;
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }

    }
    if(cnt == v) // means no cycle 
      return false;
    return true; //cycle detected;

}