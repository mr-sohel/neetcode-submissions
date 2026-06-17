class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int x = nums[l] + nums[r];
            if(x == target) {
                return {l+1, r+1};
            } else if(x < target) {
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};
