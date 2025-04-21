#include <bits/stdc++.h> 
//approach1
int solve(vector<int> &v, int n, int i, int j){
	//base case
	if(i+1==j) return 0;
	int ans = INT_MAX;
	for(int k= i+1; k<j; k++){
		ans= min(ans, v[i]*v[j]*v[k] + solve(v,n,i,k) + solve(v,n,k,j));
	}
	return ans;
}
//approach 2 mem
int solveMem(vector<int> &v, int n, int i, int j,vector<vector<int>> &dp){
	//base case
	if(i+1==j) return 0;

	if(dp[i][j] != -1) return dp[i][j];
	int ans = INT_MAX;
	for(int k= i+1; k<j; k++){
		ans= min(ans, v[i]*v[j]*v[k] + solveMem(v,n,i,k,dp) + solveMem(v,n,k,j,dp));
	}
	dp[i][j] = ans;
	return dp[i][j];
}
//approach3
int solveTab(vector<int> &v, int n){
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i=n-1; i>=0; i--){
		for(int j=i+2; j<n; j++){
			int ans= INT_MAX;
			for(int k= i+1; k<j; k++){
				ans= min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
			}
			dp[i][j] = ans;
		}
	}
	return dp[0][n-1];
}

int minimumTriangleScore(vector<int> &arr, int n){
	// return solve(arr,n,0,n-1);
	
	// vector<vector<int>> dp(n,vector<int>(n,-1));
	// return solveMem(arr,n,0,n-1,dp);

	return solveTab(arr,n);
}






