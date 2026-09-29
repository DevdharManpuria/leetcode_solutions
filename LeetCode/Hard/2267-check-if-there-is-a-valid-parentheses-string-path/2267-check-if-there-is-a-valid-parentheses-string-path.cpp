class Solution {
    int m, n;
    bool vis[105][105][105];
public:
    bool f(int r, int c, int b, vector<vector<char>>& a) {
        b += (a[r][c] == '(' ? 1 : -1);
        if (b < 0 || b > (m + n) / 2) return false;
        if (r == m - 1 && c == n - 1) return b == 0;
        if (vis[r][c][b]) return false;
        vis[r][c][b] = true;
        if (r + 1 < m && f(r + 1, c, b, a)) return true;
        if (c + 1 < n && f(r, c + 1, b, a)) return true;
        return false;
    }
    bool hasValidPath(vector<vector<char>>& a) {
        m = a.size(), n = a[0].size();
        if ((m + n - 1) % 2 != 0 || a[0][0] == ')' || a[m - 1][n - 1] == '(')
            return false;
        for (int i = 0; i < 105; ++i) {
            for (int j = 0; j < 105; ++j) {
                for (int k = 0; k < 105; ++k) {
                    vis[i][j][k] = false;
                }
            }
        }
        return f(0, 0, 0, a);
    }
};