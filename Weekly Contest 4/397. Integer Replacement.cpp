class Solution {
public:
    long long rec(unordered_map<long long,int>& dp,long long n){
        if(n==1){
            dp[n]=0;
            return 0;
        }
        if(dp.find(n)!=dp.end()) return dp[n];
        if(n%2==0){
            return dp[n]=1+rec(dp,n/2);
        }
        long long one = 1+rec(dp,n+1);
        long long two = 1+rec(dp,n-1);
        return dp[n]=min(one,two);

    }
    int integerReplacement(int n) {
        unordered_map<long long,int>dp;
        return rec(dp,n);
    }
};
