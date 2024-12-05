class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int totalsum = 0;
        unordered_map<int,int>mp;
        for(auto i:nums){
            totalsum+=i;
            mp[i]++;
        }
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int temp = totalsum-nums[i];
            int outlier  = temp-nums[i];
            mp[nums[i]]--;
            if(mp.find(outlier)!=mp.end() && mp[outlier]!=0){
                ans = max(ans,outlier);
            }
            mp[nums[i]]++;
        }
        return ans;
        
    }
};
