//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    // int solve(vector<vector<int>>& mat,int i, int j, int &maxi){
    //     //base case
    //     if(i>=mat.size() || j>=mat[0].size() ) return 0;
        
    //     int right = solve(mat,i,j+1,maxi);
    //     int diagonal = solve(mat,i+1,j+1,maxi);
    //     int left = solve(mat,i+1,j,maxi);
    //   if(mat[i][j] == 1){
    //     int ans = 1 + min(right,min(left,diagonal));
    //     maxi = max(maxi,ans);
    //     return ans;
    //   }
    //   else{
    //       return 0;
    //   }
    // }
    // int maxSquare(vector<vector<int>>& mat) {
    //     int maxi = 0;
    //     return solve(mat,0,0,maxi);
    // }
    
    
    //  int solve(vector<vector<int>>& mat,int i, int j, int &maxi, vector<vector<int>> &dp){
    //     //base case
    //     if(i>=mat.size() || j>=mat[0].size() ) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int right = solve(mat,i,j+1,maxi,dp);
    //     int diagonal = solve(mat,i+1,j+1,maxi,dp);
    //     int left = solve(mat,i+1,j,maxi,dp);
    //   if(mat[i][j] == 1){
    //     dp[i][j] = 1 + min(right,min(left,diagonal));
    //     maxi = max(maxi,dp[i][j]);
    //     return dp[i][j];
    //   }
    //   else{
    //       return dp[i][j]=0;
    //   }
    // }
    
    //   int maxSquare(vector<vector<int>>& mat) {
    //     int maxi = 0;
    //     int n = mat.size();
    //     int m = mat[0].size();
    //     vector<vector<int>> dp(n, vector<int>(m,-1));
    //     solve(mat,0,0,maxi,dp);
    //     return maxi;
    // }
    //appraoch 3
    //  int solve(vector<vector<int>>& mat,int & maxi){
    //     int row = mat.size();
    //     int col = mat[0].size();
        
    //     vector<vector<int>> dp(row+1, vector<int>(col+1,0));
    //     for(int i = row-1; i>=0;i--){
    //         for(int j= col-1; j>=0; j--){
    //             int right = dp[i][j+1];
    //           int diagonal = dp[i+1][j+1];
    //           int left = dp[i+1][j];
               
    //           if(mat[i][j]==1){
    //               dp[i][j] = 1 + min(right,min(diagonal,left));
    //               maxi = max(maxi,dp[i][j]);
    //           }
    //           else dp[i][j] = 0;
    //         }
    //   }
    //     return dp[0][0]; //koi mtlb nhi kuch bhi main ans is maxi
    // }
    
    //   int maxSquare(vector<vector<int>>& mat) {
    //     int maxi = 0;
    //     int n = mat.size();
    //     int m = mat[0].size();
    //     solve(mat,maxi);
    //     return maxi;
    // }
    
    //approach 4
     int solve(vector<vector<int>>& mat,int & maxi){
        int row = mat.size();
        int col = mat[0].size();
        
        
        vector<int> curr(col+1,0);
        vector<int> next(col+1,0);
        for(int i = row-1; i>=0;i--){
            for(int j= col-1; j>=0; j--){
                int right = curr[j+1];
               int diagonal = next[j+1];
               int left = next[j];
               
               if(mat[i][j]==1){
                   curr[j] = 1 + min(right,min(diagonal,left));
                   maxi = max(maxi,curr[j]);
               }
               else curr[j] = 0;
            }
            next = curr;
       }
        return curr[0]; //koi mtlb nhi kuch bhi main ans is maxi
    }
    
      int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0;
        int n = mat.size();
        int m = mat[0].size();
        solve(mat,maxi);
        return maxi;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends