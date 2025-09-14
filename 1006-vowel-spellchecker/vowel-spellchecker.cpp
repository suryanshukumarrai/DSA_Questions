#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string toLowerStr(const string &s) {
        string t = s;
        for (char &ch : t) ch = tolower((unsigned char)ch);
        return t;
    }
    string devowel(const string &s) {
        string t = toLowerStr(s);
        for (char &ch : t)
            if (isVowel(ch)) ch = '*';
        return t;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string,string> caseMap;   // lowercase -> first original word
        unordered_map<string,string> vowelMap;  // devowelized -> first original word

        exact.reserve(wordlist.size()*2);
        caseMap.reserve(wordlist.size()*2);
        vowelMap.reserve(wordlist.size()*2);

        for (const string &w : wordlist) {
            exact.insert(w);
            string low = toLowerStr(w);
            if (caseMap.find(low) == caseMap.end()) caseMap[low] = w;
            string dev = devowel(w);
            if (vowelMap.find(dev) == vowelMap.end()) vowelMap[dev] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());
        for (const string &q : queries) {
            if (exact.find(q) != exact.end()) {
                ans.push_back(q);
                continue;
            }
            string low = toLowerStr(q);
            if (caseMap.find(low) != caseMap.end()) {
                ans.push_back(caseMap[low]);
                continue;
            }
            string dev = devowel(q);
            if (vowelMap.find(dev) != vowelMap.end()) {
                ans.push_back(vowelMap[dev]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
