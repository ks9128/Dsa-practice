class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
        int pivot = -1;
        for(int i=n; i>0; i--){
            if(nums[i-1]< nums[i]){
                pivot = i-1;
                break;
            }
        }
        if(pivot ==-1) 
        {
            sort(nums.begin(),nums.end()); return;}
        sort(nums.begin() + pivot +1,nums.end());
        for(int i = pivot+1; i<=n; i++){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }

    }
};