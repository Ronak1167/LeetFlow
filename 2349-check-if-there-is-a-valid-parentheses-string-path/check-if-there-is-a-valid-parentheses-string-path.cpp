class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    bool solve(vector<vector<char>>& grid, int i, int j, int bal) {
        if (bal < 0) return false;
        if (i == m - 1 && j == n - 1)
            return bal == 0;
        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];
        bool ans = false;
        if (i + 1 < m) {
            int nb = bal + (grid[i + 1][j] == '(' ? 1 : -1);
            ans |= solve(grid, i + 1, j, nb);
        }
        if (j + 1 < n) {
            int nb = bal + (grid[i][j + 1] == '(' ? 1 : -1);
            ans |= solve(grid, i, j + 1, nb);
        }
        return dp[i][j][bal] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if ((m + n - 1) % 2)
            return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;
        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n, -1)
        ));
        return solve(grid, 0, 0, 1);
    }
};