class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int need = target - nums[i];
            if(mp.count(need)) {
                if(mp[need] != i) {
                    return {mp[need], i};
                }
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
