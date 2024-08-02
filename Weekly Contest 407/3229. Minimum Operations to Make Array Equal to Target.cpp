class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long ans =0,incre =0 ,decre = 0;
        for(int i=0;i<n;i++){
            long long diff = target[i] - nums[i];
            if(diff>0){
                if(incre<diff){
                    ans+=diff-incre;
                }
                incre = diff;
                decre = 0;
            }else if(diff<0){
                if(decre>diff){
                    ans+=decre-diff;
                }
                decre = diff;
                incre = 0;
            }
            else if(diff==0){
                decre=0;
                incre=0;
            }
        }
        return ans;
    }
};
