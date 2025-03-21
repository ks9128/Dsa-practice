#include<unordered_map>
#include<iostream>
using namespace std;
#include<list>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0 ;i<e; i++){
        int u= edges[i][0];
        int v= edges[i][1];
         
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
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
    //ans store
        ans.push_back(front);
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }

    }
    return ans;

}