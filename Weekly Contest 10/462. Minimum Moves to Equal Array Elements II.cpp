class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==1) return 0;
        int temp1 = nums[n/2];
        int temp2 = nums[n/2-1];
        long long tot1 = 0,tot2 = 0;
        for(auto i :nums){
            tot1+= abs(i-temp1);
            tot2+=abs(i-temp2);
        }
        return min(tot1,tot2);
    }
};
