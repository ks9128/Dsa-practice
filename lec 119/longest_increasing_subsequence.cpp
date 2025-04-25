//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  int solve(int n, vector<int>&arr, int curr, int prev,vector<vector<int>> &dp){
      //bae case
      if(curr == n) return 0;
      if(dp[curr][prev+1] != -1 ) return dp[curr][prev+1];
      //include
      int take = 0;
      if(prev == -1 || arr[curr] > arr[prev]){
          take  = 1 + solve(n,arr, curr+1, curr,dp);
      }
      int nottake = 0+ solve(n,arr,curr+1,prev,dp);
      
      dp[curr][prev+1]=  max(take,nottake);
      return dp[curr][prev+1];
  }
  
  int solveTab(int n, vector<int>&arr){
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
     for(int curr = n-1; curr>=0; curr--){
         for(int prev = curr-1; prev>=-1; prev--){
             //include
              int take = 0;
              if(prev == -1 || arr[curr] > arr[prev]){
                  take  = 1 + dp[curr+1][curr+1];
              }
              int nottake = 0+ dp[curr+1][prev+1];
              
              dp[curr][prev+1]=  max(take,nottake);
         }
     }
     return dp[0][0];
  }
  
   int solveSC(int n, vector<int>&arr){
      vector<int> currRow(n+1,0);
      vector<int> prevRow(n+1,0);
     for(int curr = n-1; curr>=0; curr--){
         for(int prev = curr-1; prev>=-1; prev--){
             //include
              int take = 0;
              if(prev == -1 || arr[curr] > arr[prev]){
                  take  = 1 + prevRow[curr+1];
              }
              int nottake = 0+ prevRow[prev+1];
              
              currRow[prev+1]=  max(take,nottake);
         }
         prevRow = currRow;
     }
     return prevRow[0];
  }
  
    int lis(vector<int>& arr) {
        int n= arr.size();
        // return solve(n,arr,0,-1);
        
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solve(n,arr,0,-1,dp);
        
        // return solveTab(n,arr);
        
        return solveSC(n,arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends