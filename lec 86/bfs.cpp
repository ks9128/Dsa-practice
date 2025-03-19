#include<unordered_map>
#include<list>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
  
  void bfs(vector<vector<int>> &adj, unordered_map<int,bool> &visited,
            vector<int> &ans, int node){
                queue<int> q;
                q.push(node);
                visited[node] = 1;
                
                while(!q.empty()){
                    int frontNode = q.front();
                    q.pop();
                    
                    ans.push_back(frontNode);
                    /// traverse adj nodese
                    for(auto i: adj[frontNode]){
                        if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                        }
                    }
                }
            }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int vertex = adj.size();
        vector<int> ans;
        
unordered_map<int,bool> visited;
        
        // for(int i= 0; i<vertex; i++){
        //     if(!visited[i]){
                bfs(adj,visited,ans,0);
        //     }
        // }
        return ans;
    }
};