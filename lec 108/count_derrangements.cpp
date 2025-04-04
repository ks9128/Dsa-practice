#include<vector>
#include<iostream>
using namespace std;
#define MOD 1000000007

// long long int countDerangements(int n) {
//     // Write your code here.
//     if(n==1) return 0;
//     if(n==2)
//         return 1;
    
//     long long int ans = ((n-1)*(countDerangements(n-1)%MOD + countDerangements(n-2)%MOD))%MOD;
//     return ans;
// }

//aproach 2 - memorizaion
// long long int solve(int n,vector<long long int> &dp){
//     if(n==1) return 0;
//     if(n==2)
//         return 1;
//     if(dp[n] != -1)
//         return dp[n];
    
//     dp[n] = ((n-1)*(solve(n-1,dp)%MOD + solve(n-2,dp)%MOD))%MOD;
//     return dp[n];
// }

// long long int countDerangements(int n) {
//     // Write your code here.
//     vector<long long int> dp(n+1,-1);
//     return solve(n,dp);
// }

// approah 3 tabulation

// long long int solve(int n){
//     vector<long long int> dp(n+1);
//     dp[1] = 0;
//     dp[2] = 1;
//     for(int i= 3; i<n+1; i++){
//         dp[i] =((i-1)*(dp[i-1]%MOD + dp[i-2]%MOD))%MOD;
//     }
//     return dp[n];
// }

// long long int countDerangements(int n) {
//     // Write your code here.
//     return solve(n);
// }

//approach 4: space optimization

long long int solve(int n){
    vector <long long int> dp(n+1);
    long long int prev2 = 0;
    long long int prev1 = 1;
    for(int i= 3; i<n+1; i++){
        long long int ans =((i-1)*(prev1%MOD + prev2%MOD))%MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int countDerangements(int n) {
    // Write your code here.
    return solve(n);
}









