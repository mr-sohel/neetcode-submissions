class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int i, int rem, vector<int>& nums) {
        if (rem == 0) {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (nums[j] > rem) break;  // pruning

            curr.push_back(nums[j]);
            dfs(j, rem - nums[j], nums);  // reuse allowed
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, target, nums);
        return ans;
    }
};