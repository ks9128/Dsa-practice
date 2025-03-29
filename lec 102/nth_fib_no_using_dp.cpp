#include<bits/stdc++.h>
using namespace std;
// approach 1 using dp - top to bottom approach
// int fib(int n,vector<int> dp){
//         //base case
//         if(n==0) return 0;
//         if(n==1) return 1;

//         if(dp[n]!=-1){
//                 return dp[n];
//         }

//         dp[n] = fib(n-1,dp)+fib(n-2,dp);
//         return dp[n];
// }
// int main()
// {
//         int n;
//         cin>>n;
//         vector<int> dp(n+1,-1);
//         cout<<fib(n,dp);
// }

//approach 2- bottom to top approach
// int main()
// {
//         int n;
//         cin>>n;
//         vector<int> dp(n+1);
//         dp[0]=0;
//         dp[1]=1;

//         for(int i=2; i<=n;i++){
//                 dp[i]=dp[i-1]+dp[i-2];
//         }
//         cout<<dp[n];
// }


//aproach 3 space optimization
int main()
{
        int n;
        cin>>n;
        vector<int> dp(n+1);
        int prev1 = 1;
        int prev2 = 0;

        for(int i=2; i<=n;i++){
              int curr = prev1 + prev2;
              //shifting logic
                prev2 = prev1;
                prev1 = curr;
        }
        cout<<prev1;
}





















