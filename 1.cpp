#include<iostream>  //O(1)
#include<map> //O(logn)
#include<unordered_map>
using namespace std;

int main(){
    
    //creation
    unordered_map<string,int> m;
    // insertion

    // 1
    pair<string,int> p = make_pair("khalid",3);
    m.insert(p);

    //2
    pair<string,int> hello("hel",2);
    m.insert(hello);

    //3
    m["mera"] = 1;
    //updated
    m["mera"] = 2;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("khalid")<<endl;

    // cout<<m.at("unknownkey"); //terminate called after throwing an instance of 'std::out_of_range'
    cout<<m["unknownkey"]<<endl;  //will create 0 if not present
    cout<<m.at("unknownkey");  // now will got 0 as above created 0

    //size
    cout<<m.size()<<endl;

    // presnt
    cout<<m.count("bro")<<endl; //0

    //erase
    m.erase("khalid");
    cout<<m.size()<<endl;

    //
    for(auto i:m){
        cout<<i.first <<"->"<< i.second <<" ";
    }cout<<endl;

    //ierators
    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<"->" <<it->second<<" ";  //will print necessorily print in serial ordr. use map for that
        it++;
    }cout<<endl;

    return 0;
}