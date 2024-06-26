class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minlen = INT_MAX,maxlen=0;
        int minwid = INT_MAX,maxwid=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    minlen = min(minlen,i+1);
                    minwid = min(minwid,j+1);
                    maxlen = max(maxlen,i+1);
                    maxwid = max(maxwid,j+1);
                }
            }
        }
        return (maxlen-minlen+1)*(maxwid-minwid+1);
    }
};
