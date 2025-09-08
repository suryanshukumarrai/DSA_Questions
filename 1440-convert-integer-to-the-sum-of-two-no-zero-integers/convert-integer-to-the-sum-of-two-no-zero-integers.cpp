class Solution {
public:
bool check(int num){
    int temp = num;
    while(temp){
        int digit = temp%10;
        if(digit == 0) return false;
        temp /= 10;
    }

    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i = 1 ; i<n ; i++){
            if(check(n-i) && check(i)){
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }

        return ans;
    }
};