class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<vector<int>>> dp(target + 1);

        // Base case: one way to make 0 (empty set)
        dp[0].push_back({});

        for (int x : nums) {
            for (int s = x; s <= target; s++) {
                for (auto comb : dp[s - x]) {
                    comb.push_back(x);
                    dp[s].push_back(comb);
                }
            }
        }

        return dp[target];
    }
};