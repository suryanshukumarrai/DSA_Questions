class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (int num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) {
                lis.push_back(num);  // Extend the LIS
            } else {
                *it = num;  // Replace to maintain the lowest possible tail
            }
        }

        return lis.size();
    }
};
