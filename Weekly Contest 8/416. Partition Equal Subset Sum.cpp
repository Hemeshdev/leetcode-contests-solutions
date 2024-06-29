class Solution {
public:
    bool rec(vector<int>& nums,int ind,int target,vector<vector<int>>& dp){
        if(ind==0){
            if(nums[0]==target) return true;
            else{
                return false;
            }
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool not_pick = rec(nums,ind-1,target,dp);
        bool pick = false;
        if(nums[ind]<=target){
            pick = rec(nums,ind-1,target-nums[ind],dp);
        }
        return dp[ind][target]= not_pick || pick;
    }
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(),nums.end(),0);
        if(tot%2!=0) return false;
        vector<vector<int>>dp(nums.size(),vector<int>(tot/2+1,-1));
        return rec(nums,nums.size()-1,tot/2,dp);
    }
};
