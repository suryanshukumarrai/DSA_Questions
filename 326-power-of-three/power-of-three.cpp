class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        // while(n%3==0){
        //     n/=3;

        // }
        // return n==1;
    //     double logValue = log10(n) / log10(3);

    // // Check if logValue is close to an integer
    // return fabs(logValue - round(logValue)) < 1e-10;
    int num = 0;
        for(int i = 0; pow(3,i) <= n; i++){
            num = pow(3,i);
            if(num == n) return true;
        }
        return false;
    }
};