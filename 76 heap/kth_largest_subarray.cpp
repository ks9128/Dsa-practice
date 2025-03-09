//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;


// } Driver Code Ends

// User function Template for C++
#include<algorithm>
#include<queue>

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        
        // //aproach 1 - tc (O(n^2logn))   sc-O(n^2)
        // vector <int> sumStore;
        // int n = arr.size();
        
        // for(int i= 0 ;i<n;i++){  //tc O(n^2) 
        //     int sum = 0;
        //     for(int j= i;j<n;j++){
        //         sum +=arr[j];
        //         sumStore.push_back(sum); //sc o(n^2)
        //     }
        // }
        // sort(sumStore.begin(),sumStore.end()); //tc O(n)
        // return sumStore[sumStore.size()-k];
        
        //approacch2 using minheap -- Sc O(k)
        priority_queue<int,vector<int>,greater<int>>mini;
        int n = arr.size();
        for(int i = 0 ;i<n;i++){
            int sum = 0;
            for (int j = i; j<n;j++){
                sum += arr[j];
                //min heap use   //sc- O(k)
                if(mini.size() <k){  
                    mini.push(sum);
                }
                else{
                    if(sum>mini.top()){
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        return mini.top();
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends