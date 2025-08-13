class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        // If last digit is already odd, return whole number
        if ((num[n - 1] - '0') % 2 != 0) {
            return num;
        } else {
            int no = -1; // index of the rightmost odd digit

            for (int i = 0; i < n; i++) {
                int digit = num[i] - '0';
                if (digit % 2 != 0) {
                    no = i; // update whenever we find an odd digit
                }
            }

            if (no >= 0) {
                return num.substr(0, no + 1);
            } else {
                return "";
            }
        }
    }
};
