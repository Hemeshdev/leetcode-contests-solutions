class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            if(nums[i]-1==nums[i-1]){
                dp[i] = dp[i-1]+1;
            }else{
                dp[i] = 0;
            }
        }
        vector<int>ans;
        int i=0;
        int j = k-1;
        while(j<n){
            if(dp[j]-dp[i]+1==k) ans.push_back(nums[j]);
            else{
                ans.push_back(-1);
            }
            j++;
            i++;
        }
        return ans;
    }
};
