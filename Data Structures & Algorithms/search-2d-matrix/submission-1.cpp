class Solution {
public:
    bool bs(vector<int> &nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] > target) {
                hi = mid - 1;
            } else if(nums[mid] < target) {
                lo = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(auto &v : matrix) {
            if(bs(v, target)) {
                return true;
            }
        }
        return false;
    }
};
