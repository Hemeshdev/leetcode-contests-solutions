class Solution {
public:
    unordered_map<int,vector<int>>mp;
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int m  = mp[target].size();
        return mp[target][rand()%m];
    }
};
