class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==0) return 1;
            else if(nums[0]==1) return 0;
        }
        reverse(nums.begin(),nums.end());
        int ans =0;
        int flag = nums[0];
        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]!=flag){
                ans++;
                flag = nums[i+1];
            }
            i++;
        }
        ans = (flag==0) ? ans+1 :ans;
        return ans;
        
    }
};
