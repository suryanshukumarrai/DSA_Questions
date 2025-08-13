class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int openCount = 0; // Keeps track of open parentheses
        
        for (char c : s) {
            if (c == '(') {
                if (openCount > 0) { // Skip outermost '('
                    result += c;
                }
                openCount++;
            } else {
                openCount--;
                if (openCount > 0) { // Skip outermost ')'
                    result += c;
                }
            }
        }
        
        return result;
    }
};
