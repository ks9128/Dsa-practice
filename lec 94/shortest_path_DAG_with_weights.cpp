#include<iostream>
#include<list>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<limits.h>

#include<vector>
using namespace std;
 class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;//u ,v, dist
    void addElement(int u, int v, int weight){
        pair<int,int> p =make_pair(v,weight);
        adj[u].push_back(p);
    }
    //print list
    void print(){
        for(auto i: adj){
            cout<<i.first<< "->";
            for(auto j:i.second){
                cout<< "["<< j.first <<","<<j.second<<"],";
            }cout<<endl;
        }
    }

    // use dfs
    void dfs(int node,unordered_map<int,bool> &visited,stack<int> &s ){
        visited[node] = true;
        
        for(auto i: adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,s);
            }
        }
        s.push(node);
    }

    void getshortestPath(int src, vector<int> & dist, stack<int> &topo){
        dist[src] = 0; 
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();
            if(dist[top] != INT_MAX){
                for(auto i: adj[top]){
                    if(dist[top] + i.second < dist[i.first]){ // top =u , i.first =v, i.second = dist
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
 };
 int main(){
    Graph g;
    g.addElement(0, 1, 5);
    g.addElement(1, 2, 2);
    g.addElement(2, 3, 3);
    g.addElement(3, 4, 4);
    g.addElement(0, 2, 4);
    g.addElement(4, 5, 2);
    g.addElement(1, 4, 6);
    g.print();
    //toplogical sort
    //dfs
    int n=4;
    unordered_map<int,bool> visited;
    stack<int> s; // store topo
    for(int i=0 ;i<n; i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    //create distance vector
    int src =0;
    vector<int> distance(n);
    // initailize with max val
    for(int i= 0 ; i<n; i++){
        distance.push_back(INT_MAX);
    }
    g.getshortestPath(src, distance, s);
    
    for(int i=0 ; i<n; i++){
        cout<<distance[i]<<"";
    }
    return 0;
 }