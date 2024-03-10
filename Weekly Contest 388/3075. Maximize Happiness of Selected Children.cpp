class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end(),greater<int>());
        long long ans =0;
        int temp = 0;
        int index =0;
        for(int i=0;i<k;i++){
            int t = h[index];
            index++;
            t-=temp;
            ans+=max(t,0);
            temp++;
        }
        return ans;
    }
};
