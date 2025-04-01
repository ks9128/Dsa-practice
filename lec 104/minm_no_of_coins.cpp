int n = nums.size();
    vector<int> dp(n+1,-1);
    int ans = solveRec(nums,n-1,dp);
    return ans;