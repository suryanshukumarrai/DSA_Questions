class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        // Keep reducing until only one element left
        while (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            n--; // shrink size
        }

        return nums[0]; // final result
    }
};
