class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int temp=0;
        for(int i=0;i< nums.size();i++){
            int a=nums[i]-3;
            if(nums[i]-3!=0){
                if(a%3!=0){
                    temp++;
                }
                
            }
        }
        return temp;
    }
};