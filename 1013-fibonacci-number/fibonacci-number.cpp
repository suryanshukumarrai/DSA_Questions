class Solution {
public:
    int a(int n,vector<int>&arr){
        if(n==0 || n==1){
            return n;

        }
        if(arr[n]!=-1){
            return arr[n];
        }
        arr[n]= a(n-1 , arr)+a(n-2 , arr);
        return arr[n];
    }
    int fib(int n) {
        vector<int>arr(n+1,-1);
        return a(n,arr);
    }
};