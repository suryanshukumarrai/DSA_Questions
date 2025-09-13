class Solution {
public:
    int maxFreqSum(string s) {
        int hash[26] = {0};
        int n = s.size();   // fixed 'inr' -> 'int'
        
        for (int i = 0; i < n; i++) {
            hash[s[i] - 'a']++;
        }

        // // You had duplicate declarations (arr[5] and arr[21]), I kept them valid
        // int arr1[5] = {0};
        // int arr2[21] = {0};

        int temp = 0;
        int t = 0;
        
        for (int i = 0; i < 26; i++) {
            // fixed invalid conditions (= instead of ==, and wrong comparisons)
            if ((i == 0 && hash[i] > temp) || 
                (i == 4 && hash[i] > temp) || 
                (i == 8 && hash[i] > temp) || 
                (i == 14 && hash[i] > temp) || 
                (i == 20 && hash[i] > temp)) {
                temp = hash[i];
            }
            else if ((i != 0 && i != 4 && i != 8 && i != 14 && i != 20) && hash[i] > t) {
        t = hash[i];
    }
        }
        return temp + t;
    }
};
