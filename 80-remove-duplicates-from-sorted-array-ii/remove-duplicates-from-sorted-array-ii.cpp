class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int writeIndex = 1; // index to write next valid element
        int count = 1;      // count of current number

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) { // allow at most two duplicates
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }

        return writeIndex; // new length of array
    }
};
