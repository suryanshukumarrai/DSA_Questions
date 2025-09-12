class Solution {
public:
    bool doesAliceWin(string s) {
        for (char ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;  // found a vowel
                break;
            }
        }
        return false;  // no vowels found
    }
};
