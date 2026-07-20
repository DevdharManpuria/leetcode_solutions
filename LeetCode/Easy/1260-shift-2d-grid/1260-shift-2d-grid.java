import java.util.*;

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length, total = m * n;
        Integer[][] ans = new Integer[m][n];
        k %= total;
        for (int i = 0; i < total; i++) {
            int next = (i + k) % total;
            ans[next / n][next % n] = grid[i / n][i % n];
        }
        List<List<Integer>> result = new ArrayList<>();
        for (Integer[] row : ans) result.add(Arrays.asList(row));
        return result;
    }
}
