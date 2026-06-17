class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void f(int i, vector<int> &nums) {
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        f(i+1, nums);
        curr.push_back(nums[i]);
        f(i+1, nums);
        curr.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        f(0, nums);
        return ans;
    }
};
