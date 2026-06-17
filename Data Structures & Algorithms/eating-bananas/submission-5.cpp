class Solution {
public:
    bool ok(int k, vector<int>& piles, int h) {
        long long need = 0;
        for (int x : piles) {
            need += (x + k - 1) / k;
            if (need > h) return false; // early exit
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid, piles, h)) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};