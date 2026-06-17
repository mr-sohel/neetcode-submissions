class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(auto &v : matrix) {
            if(binary_search(v.begin(), v.end(), target)) {
                return true;
            }
        }
        return false;
    }
};
