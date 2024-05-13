class Solution {
public:
    
    int rec(vector<int>& energy, int idx, int k, vector<int> &dp){
        int n = energy.size();
        if(idx >= n) return 0;
        if(dp[idx] != INT_MIN) return dp[idx];  
        int ans = energy[idx] + rec(energy, idx + k, k, dp);       
        return dp[idx] = ans;
    }
    
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans, rec(energy, i, k, dp));
        }
        return ans;
    }
};
