class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false; // need room for two consecutive subarrays

        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; i++) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };

        // check every consecutive pair of size k
        for (int i = 0; i <= n - 2 * k; i++) {
            if (isIncreasing(i) && isIncreasing(i + k))
                return true;
        }

        return false;
    }
};
