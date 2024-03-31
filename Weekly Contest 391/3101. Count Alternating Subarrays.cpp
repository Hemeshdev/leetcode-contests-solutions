class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans =1;
        long long count =1;
        for(int i=1;i<n;i++){
            count++;
            if(nums[i]==nums[i-1]){
                count =1;
            }
            ans+=count;
        }
        return ans;
    }
};
