class Solution {
    public:
      // Approach 1: Recursion
      int findMaxSumRec(vector<int>& arr, int i) {
          if (i < 0) return 0;
          if (i == 0) return arr[0];
          
          int take = arr[i] + findMaxSumRec(arr, i - 2);
          int skip = findMaxSumRec(arr, i - 1);
          
          return max(take, skip);
      }
      
      int findMaxSum(vector<int>& arr) {
          int n = arr.size();
          return findMaxSumRec(arr, n - 1);
      }
  
      // Approach 2: Memoization (Top-Down DP)
      int findMaxSumMemo(vector<int>& arr, int i, vector<int>& dp) {
          if (i < 0) return 0;
          if (i == 0) return arr[0];
          if (dp[i] != -1) return dp[i];
          
          int take = arr[i] + findMaxSumMemo(arr, i - 2, dp);
          int skip = findMaxSumMemo(arr, i - 1, dp);
          
          return dp[i] = max(take, skip);
      }
      
      int findMaxSumMemoization(vector<int>& arr) {
          int n = arr.size();
          vector<int> dp(n, -1);
          return findMaxSumMemo(arr, n - 1, dp);
      }
      
      // Approach 3: Tabulation (Bottom-Up DP)
      int findMaxSumTabulation(vector<int>& arr) {
          int n = arr.size();
          if (n == 0) return 0;
          if (n == 1) return arr[0];
          
          vector<int> dp(n, 0);
          dp[0] = arr[0];
          dp[1] = max(arr[0], arr[1]);
          
          for (int i = 2; i < n; i++) {
              dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
          }
          
          return dp[n - 1];
      }
      
      // Approach 4: Space Optimization
      int findMaxSumOptimized(vector<int>& arr) {
          int n = arr.size();
          if (n == 0) return 0;
          if (n == 1) return arr[0];
          
          int prev2 = 0, prev1 = arr[0];
          
          for (int i = 1; i < n; i++) {
              int take = arr[i] + prev2;
              int skip = prev1;
              int curr = max(take, skip);
              
              prev2 = prev1;
              prev1 = curr;
          }
          
          return prev1;
      }
  };
  