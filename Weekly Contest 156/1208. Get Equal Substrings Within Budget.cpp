class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start = 0;
        int end = 0;
        long long cost = 0;
        int ans = 0;
        while(end<n){
            cost+=abs(s[end]-t[end]);
            while(cost>maxCost && start<=end){
                cost-=abs(s[start]-t[start]);
                start++;
            }
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
