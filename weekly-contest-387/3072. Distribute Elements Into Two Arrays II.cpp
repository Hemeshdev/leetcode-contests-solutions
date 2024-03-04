//we are using upper bound to find the values that are greater than k
// then simple simulation
class Solution {
public:
    int greaterCount(vector<int>& arr, int val) {
        return arr.end() - upper_bound(arr.begin(), arr.end(), val);
    }

    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> left, right, ll, rr;
        left.push_back(nums[0]);
        right.push_back(nums[1]);
        ll.push_back(nums[0]);
        rr.push_back(nums[1]);
        
        int l = 0, r = 0;
        
        for (int i = 2; i < n; i++) {
            int x = greaterCount(left, nums[i]);
            int y = greaterCount(right, nums[i]);
            
            if (x > y) {
                
                left.insert(left.end() - x , nums[i]);
                ll.push_back(nums[i]);
                l++;
            } else if (x < y) {
                
                right.insert(right.end() - y, nums[i]);
                rr.push_back(nums[i]);
                r++;
            } else {
                if (l <= r) {
                    
                    left.insert(left.end() - x, nums[i]);
                    ll.push_back(nums[i]);
                    l++;
                } else {
                    
                    right.insert(right.end() - y, nums[i]);
                    rr.push_back(nums[i]);
                    r++;
                }
            }
        }
        
        
        ll.insert(ll.end(), rr.begin(), rr.end());
        return ll;
    }
};
