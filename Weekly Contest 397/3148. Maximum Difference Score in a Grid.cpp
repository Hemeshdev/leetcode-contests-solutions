class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1)
                    continue;
                int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN;
                if (i + 1 < n) {
                    a = (grid[i + 1][j] - grid[i][j]) + dp[i + 1][j];
                    b = grid[i + 1][j] - grid[i][j];
                }
                if (j + 1 < m) {
                    c = (grid[i][j + 1] - grid[i][j]) + dp[i][j + 1];
                    d = grid[i][j + 1] - grid[i][j];
                }
                dp[i][j] = max(max(a, b), max(c, d));
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
