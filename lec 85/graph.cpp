#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
template <typename T >

class graph{
    public:

    unordered_map<T, list<T>> adj;

    void addEdge(T u, int v, bool direction){\
    //let 0 undirected and 1 means directed
        adj[u].push_back(v);
        if(direction == 0){
            //undirected
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first <<"->";
            for(auto j:i.second){
                cout<<j<< ",";
            }
            cout<<endl;

        }
    }

};

int main(){
    int n ;
    cout<<"enter the no of nodes"<<endl;
    cin>> n;
    int m;
    cout<<"enter the no of edges"<<endl;
    cin>> m;

    graph<int> g;  // used template so u can use int char or other used by adding here
    for(int i=0; i<m; i++){
        int u,v;
        cin>> u>> v;
        g.addEdge(u,v,0); //let undirected graph(0);
    }

    g.printAdjList();
    

}