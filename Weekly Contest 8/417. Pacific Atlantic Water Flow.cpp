class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<bool>>&ocean,vector<vector<int>>& h){
        int n = h.size();
        int m = h[0].size();
        int row[4] = {-1,0,0,1};
        int col[4] = {0,-1,1,0};
        while(q.size()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+row[i];
                int ncol = c+col[i];
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || h[nrow][ncol]<h[r][c] || ocean[nrow][ncol]!=false) continue;
                q.push({nrow,ncol});
                ocean[nrow][ncol] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        queue<pair<int,int>>atl;
        queue<pair<int,int>>pac;

        for(int i=0;i<m;i++){
            pacific[0][i] = true;
            pac.push({0,i});
            atlantic[n-1][i] = true;
            atl.push({n-1,i});
        }
        for(int i=0;i<n;i++){
            pacific[i][0] = true;
            pac.push({i,0});
            atlantic[i][m-1] = true;
            atl.push({i,m-1});
        }
        bfs(atl,atlantic,h);
        bfs(pac,pacific,h);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
            }
        }
        return ans;

    }
};
