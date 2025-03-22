
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <algorithm> //
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int> > adjlist;
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;
            
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        
        unordered_map<int,bool>visited;
        unordered_map<int,int> parent;
        queue<int>q;
        q.push(s);
        visited[s]=true;
        parent[s]=-1;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto i:adjlist[front]){
                if(!visited[i]){
                    visited[i]=true;
                    parent[i]=front;
                    q.push(i);
                }
            }
        }

		int currNode=t;
		vector<int> ans;
		ans.push_back(currNode);
		while(currNode!=s){
			currNode=parent[currNode];
			ans.push_back(currNode);
		}
		reverse(ans.begin(),ans.end());
		return ans;
	
	
}
