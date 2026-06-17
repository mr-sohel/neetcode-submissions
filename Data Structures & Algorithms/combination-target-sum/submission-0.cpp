class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void f(int i, int sum, vector<int> &nums, int target) {
        if(i >= nums.size() or sum > target) return;
        if(sum == target) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        f(i, sum + nums[i], nums, target);
        curr.pop_back();
        f(i+1, sum, nums, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        f(0, 0, nums, target);
        return ans;
    }
};
