// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         long long count=0;

//       int n=nums.size();
//       for(int i=0;i<n;i++){
//         int sum =0;
//         for(int j=i;j<n;j++){
//             sum+=nums[j];
//             if(sum==0){
//                 count++;
//             }
//         }

//     }  
//     return count;
//     }
// };
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, streak = 0;
        for (int num : nums) {
            if (num == 0) {
                streak++;
                cnt += streak;
            } else {
                streak = 0;
            }
        }
        return cnt;
    }
};