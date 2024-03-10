class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int ans =0;
        int tot = accumulate(apple.begin(),apple.end(),0);
        for(int i=0;i<capacity.size();i++){
            if(tot>0){
                tot-=capacity[i];
                ans++;
            }else break;
        }
        return ans;
    }
};
