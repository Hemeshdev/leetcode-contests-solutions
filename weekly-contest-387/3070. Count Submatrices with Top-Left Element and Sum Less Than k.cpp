class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if(grid[0][0]>k) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>>temp(n,vector<long long>(m,0));
        temp[0][0] = grid[0][0];
        for(int i=1;i<m;i++) temp[0][i] = grid[0][i]+temp[0][i-1];
        for(int i=1;i<n;i++) temp[i][0] = grid[i][0]+temp[i-1][0];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                temp[i][j] = temp[i-1][j] +temp[i][j-1]+grid[i][j]-temp[i-1][j-1];
            }
        }
        int count =0;
        for(auto i:temp){
            for(auto j:i){
                if(j<=k) count++;
            }
        }
        return count;

    }
};
