class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count =0;
        int tot = 0;
        for(auto i:nums){
            tot+=i;
            if(tot==0) count++;
        }
        return count;
    }
};

//Simple to solve
