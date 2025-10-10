class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // children's greed factors
        sort(s.begin(), s.end());  // cookie sizes

        int i = 0;  // index for children
        int j = 0;  // index for cookies

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // cookie satisfies this child
                i++;
                j++;
            } else {
                // cookie too small, try next bigger cookie
                j++;
            }
        }

        return i;  // number of content children
    }
};
