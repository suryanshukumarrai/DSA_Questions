class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> a(101, 0);  

        // count frequency
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]]++;
        }

        int temp = 0;
        for (int i = 0; i < 101; i++) {
            if (a[i] > temp) {
                temp = a[i];  // max frequency
            }
        }

        int ans = 0;
        for (int i = 0; i < 101; i++) {
            if (a[i] == temp) ans += a[i]; // sum of elements with max freq
        }

        return ans;
    }
};
