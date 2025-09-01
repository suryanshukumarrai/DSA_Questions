class Solution {
public:
    int fn(vector<int>& nums,int n,vector<int> &dp){
        if(n<0)return 0;
        if(n==0)return nums[0];
        if(dp[n]!=-1){
            return dp[n];
        }
        int p1=nums[n]+ fn(nums,n-2,dp);
        int p2=fn(nums,n-1,dp);
        return dp[n]=max(p1,p2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return fn(nums,n-1,dp);

        

    }
};