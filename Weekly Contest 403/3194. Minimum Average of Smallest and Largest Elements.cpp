class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<float>temp;
        int i=0,j=nums.size()-1;
        while(i<j){
            temp.push_back((nums[i]+nums[j])/2.0);
            i++;
            j--;
        }
        return *min_element(temp.begin(),temp.end());

    }
};
