class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int c=0;c<s.size();c++){
            if(s[c]!='9'){
                s[c]='9';
                break;

            }
        }
        return stoi(s);
        
    }
};