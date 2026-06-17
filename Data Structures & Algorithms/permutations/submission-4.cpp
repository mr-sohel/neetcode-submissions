class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& a, vector<bool>& used, vector<int>& curr) {

        if (curr.size() == a.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < a.size(); i++) {

            if (used[i]) continue;

            // Skip duplicates
            if (i > 0 && a[i] == a[i-1] && !used[i-1]) continue;

            used[i] = true;
            curr.push_back(a[i]);

            backtrack(a, used, curr);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        //sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        vector<int> curr;

        backtrack(nums, used, curr);

        return ans;
    }
};