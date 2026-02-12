class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> postive;
        vector<int> negetive;

        for(int i=0; i<nums.size();i++){
            if(nums[i]<0){
                negetive.push_back(nums[i]);
            }
            else{
                postive.push_back(nums[i]);
            }
        }
        int j=0;
        for(int i=0; i<postive.size();i++){
            nums[j++] = postive[i];
            nums[j++] = negetive[i];
        }
        return nums;
    }
};