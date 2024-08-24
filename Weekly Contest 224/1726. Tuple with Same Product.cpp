class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,int>mp;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                int prod = nums[i]*nums[j];
                ans+=8*mp[prod];
                mp[prod]++;
            }
        }
        return ans;
        
    }
};
