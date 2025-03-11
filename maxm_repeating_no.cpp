//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Returns maximum repeating element in arr[0..n-1].
    // The array elements are in range from 0 to k-1
    int maxRepeating(int k, vector<int>& arr) {
        //tc O(n) used hashmaps
        unordered_map<int, int> m;
        
        int maxfreq = 0;
        int maxAns = INT_MAX;
        for(int i =0 ; i<arr.size(); i++){
            m[arr[i]]++;
            maxfreq = max(maxfreq,m[arr[i]]);
        }
        for(int i = 0 ; i<arr.size();i++){
            if(maxfreq == m[arr[i]]){
                maxAns =min(maxAns,arr[i]);
            }
        }
        return maxAns;
    }
    
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.maxRepeating(k, arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends