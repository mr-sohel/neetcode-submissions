class Solution {
public:
    bool check(int mid, int h, vector<int> &piles) {
        long long sum = 0;
        for(int i : piles) {
            sum += (i + mid - 1) / mid;
            if(sum > h) return false;
        }
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long lo = 1, hi = *max_element(piles.begin(), piles.end());
        long long ans = hi;
        while(lo <= hi) {
            long long mid = (lo + hi) / 2;
            if(check(mid, h, piles)) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
