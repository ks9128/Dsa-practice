#include<unordered_map>
#include<iostream>
using namespace std;
#include<list>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>

//approach1 
void topoSort(int node, stack<int> &s, vector<bool> &visited, unordered_map<int,list<int>> &adj){
    visited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,s,visited,adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0 ;i<e; i++){
        int u= edges[i][0];
        int v= edges[i][1];
         
        adj[u].push_back(v);
    }
    //call dfs topological sort until func for al comp
    // unordered_map<int,bool> visited;
    vector<bool> visited(v) ;
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,s,visited,adj);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}