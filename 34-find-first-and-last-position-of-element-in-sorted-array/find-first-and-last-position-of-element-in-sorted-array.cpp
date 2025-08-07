class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const auto upper = upper_bound(nums.begin(),nums.end(),target);
        const auto lower = lower_bound(nums.begin(),nums.end(),target);
        if(lower == nums.end()) return {-1,-1};
        if(nums[lower-nums.begin()] != target) return {-1,-1};
        return {static_cast<int>(lower-nums.begin()), static_cast<int>(upper - nums.begin() -1)};

    }
};