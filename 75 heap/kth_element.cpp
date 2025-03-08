//{ Driver Code Starts
// Initial function template for C++

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    
    //aproach 1:
    // sort array in inc order O(nlog(n)) then position k
    
    // approach 2: heap
    // 1. create a max heap for first k elements 
    // 2. for res eltemt k-(n-1) th element if element<top : top.pop() and push element;
    int kthSmallest(vector<int> &arr, int k) {
    
    int n= arr.size();
    
    priority_queue<int> pq;
    //step1
    for(int i = 0; i<k;i++){
        pq.push(arr[i]);
    }
    //step 2 ;
    for (int i = k ;i<n; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //step3: top elemt is kth one
    int ans=pq.top();
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends