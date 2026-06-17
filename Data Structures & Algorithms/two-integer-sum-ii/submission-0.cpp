class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int x = nums[l] + nums[r];
            if(x > target) {
                r--;
            } else if(x < target) {
                l++;
            } else {
                return {l+1, r+1};
            }
        }
        return {};
    }
};
