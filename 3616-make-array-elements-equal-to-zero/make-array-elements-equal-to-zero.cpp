class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    long long total = prefix[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            long long left = prefix[i];
            long long right = total - prefix[i + 1];

            if (left == right) {
                count += 2;
            } else if (abs(left - right) == 1) {
                count += 1;
            }
        }
    }

    return count;
}
};