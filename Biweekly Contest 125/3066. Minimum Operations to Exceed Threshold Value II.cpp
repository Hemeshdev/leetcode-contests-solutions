class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        int count =0;
        while(pq.top()<k && pq.size()){
            long long temp1 = pq.top();
            pq.pop();
            long long temp2 = pq.top();
            pq.pop();
            pq.push(temp1*2+temp2);
            count++;
            
        }
        return count;
    }
};

//simple question with no extra meaning just simulation
