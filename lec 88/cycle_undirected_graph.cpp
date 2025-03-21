#include<unordered_map>
#include<iostream>
using namespace std;
#include<list>
#include<iostream>
#include<vector>
#include<queue>

bool isCycle(int src, unordered_map<int,bool> &visited,
    vector<vector<int>>& edges, unordered_map<int,list<int>> &adj ){
        unordered_map<int,int> parent;

        queue<int> q;
        q.push(src);
        visited[src] = 1;
        parent[src]=-1;

        while(!q.empty()){
            int front= q.front();
            q.pop();

            for(auto neighbour: adj[front]){
                if(visited[neighbour]== true &&  neighbour != parent[front]){
                    return true;
                }
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=1;
                    parent[neighbour]=front;
                }
            }
        }
        return false;
    }

bool isCycleDFS(int node,int parent, unordered_map<int,bool> &visited,
     unordered_map<int,list<int>> &adj ){
    visited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCycleDFS(neighbour,node,visited,adj);
            if(cycleDetected) return true;
            
        }
        else if(neighbour!= parent){ // means visited  bhi hai par parent neighbour 
                //cycle present
                return true;
        } 
    }
    return false;
    }
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   //create adj list
   unordered_map<int,list<int>> adj;
   for(int  i= 0; i<m ; i++){
       int u = edges[i][0];
       int v= edges[i][1];

       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   //to handle disconnected graph
   unordered_map<int,bool> visited;
   for(int i=0; i<n;i++){
       if(!visited[i]){
           bool ans= isCycleDFS(i,-1,visited,adj);
           if(ans==1) return "Yes";
       }
    
   }
   return "No";
}
