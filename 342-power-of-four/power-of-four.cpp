class Solution {
public:
    bool isPowerOfFour(int n) {
        for(long long i=1;i<=n;i*=4){
            if(i==n){
                return true;
            }
        }
        return false;
        
    }
};