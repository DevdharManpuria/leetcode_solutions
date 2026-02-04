class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cnt = 1;
        int layers = (n + 1) / 2;
        for (int layer = 0; layer < layers; layer++) {
            for (int i = layer; i < n - layer; i++)
                ans[layer][i] = cnt++;
            for (int i = layer + 1; i < n - layer; i++)
                ans[i][n - layer - 1] = cnt++;
            for (int i = n - layer - 2; i >= layer; i--)
                ans[n - layer - 1][i] = cnt++;
            for (int i = n - layer - 2; i > layer; i--)
                ans[i][layer] = cnt++;
        }
        return ans;
    }
};