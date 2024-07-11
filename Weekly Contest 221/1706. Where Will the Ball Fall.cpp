class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int row = 0;
            int col = i;
            bool flag = true;
            while(row<n && col<m){
                int t = grid[row][col];
                if(col+t>=0 && col+t<m && grid[row][col]!=grid[row][col+t]){
                    ans.push_back(-1);
                    flag = false;
                    break;
                }else if(col+t<0 || col+t>=m){
                    ans.push_back(-1);
                    flag = false;
                    break;
                }
                row++;
                col = col+t;
            }
            if(flag) ans.push_back(col);
        }
        return ans;
    }
};
