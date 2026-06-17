class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void f(int idx, int sum, vector<int>& candidates, int target) {

        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (sum > target)
            return;

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (sum + candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            f(i + 1, sum + candidates[i], candidates, target);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        f(0, 0, candidates, target);

        return ans;
    }
};