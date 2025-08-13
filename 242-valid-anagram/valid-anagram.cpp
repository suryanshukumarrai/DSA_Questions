class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26]={0};
        int rash[26]={0};
        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            rash[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]!=rash[i]){
                return false;

            }
        }
        return true;
    }
};