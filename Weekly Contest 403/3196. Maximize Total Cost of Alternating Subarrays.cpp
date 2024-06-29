#define ll long long
class Solution {
public:
    long long rec(int ind,bool flag, vector<int>& nums,vector<vector<ll>> &dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][flag]!=LLONG_MIN) return dp[ind][flag];
        ll dont_seperate = 0;
        if(flag){
            dont_seperate = nums[ind]+rec(ind+1,!flag,nums,dp);
        }else if(!flag){
            dont_seperate = -nums[ind]+rec(ind+1,!flag,nums,dp);
        }
        ll seperate = nums[ind]+ rec(ind+1,true,nums,dp);
        return dp[ind][flag]=max(seperate,dont_seperate);
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>>dp(n,vector<ll>(2,LLONG_MIN));
        for(int i=0)
    }
};
