//longest arithmetic subsequence
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    public:
    //recursive soln
    int solve(int index,int diff,vector<int> &arr){
        //base case
        if(index<0) return 0;
        
        int ans = 0;
        for(int j=index-1; j>=0; j--){
            if(arr[index]-arr[j] == diff){
                ans = max(ans, 1+ solve(j,diff,arr));
            }
        }
        return ans;
    }
    //second method : top down approach
    int solvemem(int index,int diff,vector<int> &arr,unordered_map<int,int> dp[]){
        //base case
        if(index<0) return 0;
        if(dp[index].count(diff)) return dp[index][diff];
        int ans = 0;
        for(int j=index-1; j>=0; j--){
            if(arr[index]-arr[j] == diff){
                ans = max(ans, 1+ solvemem(j,diff,arr,dp));
            }
        }
        return dp[index][diff]=ans;
    }
      // int lengthOfLongestAP(vector<int>& arr) {
      //     int n = arr.size();
      //     if(n<=2) return n;
      //     int ans = 0;
          
      //     unordered_map<int,int> dp[n+1];
          
      //     for(int i=0; i<n; i++){
      //         for(int j= i+1; j<n; j++){
      //             // ans= max(ans,2+ solve(i,arr[j]-arr[i],arr));
      //              ans= max(ans,2+ solvemem(i,arr[j]-arr[i],arr,dp));
      //         }
      //     }
      //     return ans;
      // }
      
      //third method: botttom topapproach: tabulation approah
        int lengthOfLongestAP(vector<int>& arr) {
          int n = arr.size();
          if(n<=2) return n;
          int ans = 0;
          
          unordered_map<int,int> dp[n+1];
          for(int i=1; i<n; i++){
              for(int j= 0; j<i; j++){
                  int diff = arr[i] - arr[j];
                  int cnt = 1;
                  if(dp[j].count(diff))
                      cnt = dp[j][diff];
                  
                  dp[i][diff]= 1+ cnt;
                  ans = max(ans,dp[i][diff]); //max fcn
              }
          }
          return ans;
      }
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
  };