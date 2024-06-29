class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int temp = nums[i]%3;
            ans+=min(3-temp,temp);
        }
        return ans;
    }
};
