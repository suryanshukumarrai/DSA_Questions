class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        bool found = true;

        while (found) {
            found = false;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == o) {
                    o = 2 * o;
                    found = true;
                }
            }
        }

        return o;
    }
};
