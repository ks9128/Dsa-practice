// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> postive;
//         vector<int> negetive;

//         for(int i=0; i<nums.size();i++){
//             if(nums[i]<0){
//                 negetive.push_back(nums[i]);
//             }
//             else{
//                 postive.push_back(nums[i]);
//             }
//         }
//         int j=0;
//         for(int i=0; i<postive.size();i++){
//             nums[j++] = postive[i];
//             nums[j++] = negetive[i];
//         }
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        
        
        int pos=0,neg=1;
        

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[pos] = nums[i];
                pos+=2;
            }else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};
