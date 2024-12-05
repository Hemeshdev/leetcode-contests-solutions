//TC : O(n*(r-l+1))
//SC : O(1)

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for(int i=l;i<=r;i++){
            int temp = 0;
            for(int j=0;j<i;j++){
                temp+=nums[j];
            }
            if(min(ans,temp)>0){
                ans = min(ans,temp);
            }
            int k = 0;
            int a = i;
            while(a<nums.size()){
                temp+=nums[a];
                temp-=nums[k];
                if(min(ans,temp)>0){
                    ans = min(ans,temp);
                }
                a++;
                k++;
            }
        }
        if(ans ==INT_MAX) return -1;
        return ans;
    }
};
