//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // finding min using min heap as tc of finding min in O(1)
        
        priority_queue<int,vector<int>, greater<int>> pq;
        
        int size = arr.size();
        
        for(int i = 0 ; i<size; i++){  // tc(O(nlogn)) //sc o(n)
            pq.push(arr[i]);
        }
        
        int cost = 0;
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int sum = a+b;
            cost += sum;
            
            pq.push(sum);
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends