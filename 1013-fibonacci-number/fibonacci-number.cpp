class Solution {
public:
    //int abb(int num, vector<int>& arr) {
        // if (num == 0 || num == 1) {
        //     return num;
        // }

        // if (arr[num] != -1) {
        //     return arr[num];
        // }

        // return arr[num] = fib(num - 1) + fib(num - 2);
        
    //}
    int fib(int num) {

        vector<int> arr(num + 1,0);
        if(num==0)return 0;
        
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<=num;i++){
            arr[i]=arr[i-1]+arr[i-2];

        }
        return arr[num];
    }
};