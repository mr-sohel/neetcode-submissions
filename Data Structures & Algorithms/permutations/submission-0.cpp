class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> ans;
    vector<int> curr;

    void f(vector<int> &nums) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int j = 0; j < nums.size(); j++) {
            if(!vis[j]) {
                vis[j] = true;
                curr.push_back(nums[j]);
                f(nums);
                curr.pop_back();
                vis[j] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(100, false);
        f(nums);
        return ans;
    }
};
