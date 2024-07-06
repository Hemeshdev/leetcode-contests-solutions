class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        int ans =0;
        int n = colors.size();
        for(int i=0;i<n-2;i++){
            if(colors[i]==colors[i+2] && colors[i+1]!=colors[i]){
                ans++;
            }
        }
        return ans;
    }
};
