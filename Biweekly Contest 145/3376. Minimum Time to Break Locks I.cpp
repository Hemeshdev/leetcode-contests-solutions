//TC : O(N^2);
//SC : O(N);

class Solution {
public:
    int fun(vector<int>strength, int k){
        int minites = 0;
        int x =1;
        for(int i=0;i<strength.size();i++){
            minites += ceil(((float)strength[i])/x);
            x+=k;
        }
        return minites;
    }
    int findMinimumTime(vector<int>& strength, int K) {
        vector<int>temp = strength;
        int ans;    
        ans = fun(strength,K);
        next_permutation(strength.begin(),strength.end());
        while(strength!=temp){
            int mini = fun(strength,K);
            ans = min(mini,ans);
            next_permutation(strength.begin(),strength.end());
        }
        
        return ans;
    }
};
