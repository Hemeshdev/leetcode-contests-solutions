class Solution {
public:
    int rec(int ind,int m,int n,vector<string>&strs,vector<vector<vector<int>>>&dp){
        if(ind==0){
            int ones = count(strs[0].begin(),strs[0].end(),'1');
            int zeroes = strs[0].size()-ones;
            return ones<=n && zeroes<=m;
        }
        if(m<0 || n<0) return 0;
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];
        int not_pick = rec(ind-1,m,n,strs,dp);
        int pick = 0;
        int ones = count(strs[ind].begin(),strs[ind].end(),'1');
        int zeroes = strs[ind].size()-ones;
        if(ones<=n && zeroes<=m){
            pick = 1+rec(ind-1,m-zeroes,n-ones,strs,dp);
        }
        return dp[ind][m][n]=max(pick,not_pick);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<vector<int>>>dp(k,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return rec(k-1,m,n,strs,dp);
    }
};
