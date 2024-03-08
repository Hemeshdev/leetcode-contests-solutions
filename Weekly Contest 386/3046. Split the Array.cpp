class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int>temp(101,0);
        for(auto i:nums){
            temp[i]++;
            if(temp[i]>2) return false;
        }
        return true;
    }
};
