class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        set<int>s1;
        set<int>s2;
        for(int i =0;i<n;i++){
            s1.insert(nums1[i]);
        }
        for(int i =0;i<m;i++){
            s2.insert(nums2[i]);
        }
        int ans1 =0;
        int ans2 =0;
        for(int i =0;i<n;i++){
            if(s2.find(nums1[i])!=s2.end()) ans1++;
        }
        for(int i =0;i<m;i++){
            if(s1.find(nums2[i])!=s1.end()) ans2++;
        }
        return {ans1,ans2};
    }
};
