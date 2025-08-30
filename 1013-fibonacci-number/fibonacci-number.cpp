class Solution {
public:
    int abb(int num, vector<int>& arr) {
        if (num == 0 || num == 1) {
            return num;
        }

        if (arr[num] != -1) {
            return arr[num];
        }

        return arr[num] = fib(num - 1) + fib(num - 2);
    }
    int fib(int num) {

        vector<int> arr(num + 1, -1);

        return abb(num, arr);
    }
};