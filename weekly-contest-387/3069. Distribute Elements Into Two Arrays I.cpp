class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp1,temp2;
        temp1.push_back(nums[0]);
        temp2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(temp1[temp1.size()-1]>temp2[temp2.size()-1]){
                temp1.push_back(nums[i]);
            }else{
                temp2.push_back(nums[i]);
            }
        }
        temp1.insert(temp1.end(),temp2.begin(),temp2.end());
        return temp1;
    }
};
