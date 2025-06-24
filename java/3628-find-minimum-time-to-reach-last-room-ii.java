class Solution {
    public int minTimeToReach(int[][] mat) {
        int[] D = { 0, -1, 0, 1, 0 };
        int m = mat.length, n = mat[0].length;
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.offer(new int[] {0, 0, 0, 1});
        mat[0][0] = -1;
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int r = top[0], c = top[1], t = top[2], s = top[3];
            for (int i = 0; i < 4; i ++) {
                int nr = r + D[i], nc = c + D[i + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] >= 0) {
                    int nt = Math.max(t, mat[nr][nc]) + s;
                    if (nr == m - 1 && nc == n - 1) {
                        return nt;
                    }

                    pq.add(new int[] { nr, nc, nt, 3 - s});
                    mat[nr][nc] = -1;
                }
            }
        }
        return -1;
    }
}