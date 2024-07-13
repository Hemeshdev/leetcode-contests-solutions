class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
            
        unordered_map<int,int>mp;
        int n = nums.size();
        int maxi =0;
        int start =0;
        int end =0;
        while(end<n){
            mp[nums[end]]++;
            while(mp[nums[end]]>k){
                mp[nums[start]]--;
                start++;
            }
            maxi= max(maxi,end-start+1);
            end++;
        }
        return maxi;

    }
};
