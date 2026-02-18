#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
       
        for(int num : nums) {
            st.insert(num);
        }

        int longest = 0;

        
        for(int num : st) {
            //check if prev dont exist
            if(st.find(num - 1) == st.end()) {
                int current = num;
                int count = 1;
                while(st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};
