class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> a;
        for(char c : s) a.push_back(c - '0'); 

        while(a.size() > 2) {
            vector<int> temp;
            for(int i = 0; i < a.size() - 1; i++) {
                temp.push_back((a[i] + a[i+1]) % 10);
            }
            a = temp;
        }

        return a[0] == a[1];
    }
};
