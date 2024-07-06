class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>temp = colors;
        for(int i=0;i<k-1;i++){
            temp.push_back(colors[i]);
        }
        int ans = 0;
        int t = 1;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i]!=temp[i+1]) t++;
            else t =1;
            if(t>=k) ans++;
        }
        return ans;
    }
};
