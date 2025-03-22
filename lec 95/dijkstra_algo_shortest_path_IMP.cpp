#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <climits>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create adj list
    unordered_map<int,list<pair<int,int>>> adj; // u.v,weight
    for(int i=0; i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    //creaete distance and intiaize with infinity
    vector<int> distance(vertices);
    for(int i=0; i<vertices; i++){
        distance[i]=INT_MAX;
    }
    //create set of pair (distance, node) 
    // set gives the smallest distance as front node at logn tc
    set<pair<int,int>> s;
    //initialze set and distance;
    distance[source] = 0;
    s.insert(make_pair(0,source));

    while(!s.empty()){
        auto top = *(s.begin());
        s.erase(s.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //visit neighbour
        for(auto neighbour : adj[topNode]){ // u,v,weight
            if(nodeDistance + neighbour.second < distance[neighbour.first]){
                // remove same element of set if found then push new one with updated dist
                auto record = s.find(make_pair(distance[neighbour.first],neighbour.first));
                if(record != s.end()){
                    s.erase(record);
                }
                // distance update
                distance[neighbour.first] = nodeDistance + neighbour.second;
                // push record
                s.insert(make_pair(distance[neighbour.first],neighbour.first));
                
            }
        }
    }
    return distance;
}
