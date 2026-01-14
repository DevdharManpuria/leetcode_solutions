class Solution {
    public double separateSquares(int[][] squares) {
        ArrayList<Integer> xc = new ArrayList<>();
        ArrayList<Integer> yc = new ArrayList<>();
        for (int[] s : squares) {
            int x = s[0], y = s[1], len = s[2];
            xc.add(x);
            xc.add(x + len);
            yc.add(y);
            yc.add(y + len);
        }
        Collections.sort(xc);
        Collections.sort(yc);
        ArrayList<Integer> xs = new ArrayList<>();
        xs.add(xc.get(0));
        for (int i = 1; i < xc.size(); i++) {
            if (!xc.get(i).equals(xc.get(i - 1)))    xs.add(xc.get(i));
        }
        ArrayList<Integer> ys = new ArrayList<>();
        ys.add(yc.get(0));
        for (int i = 1; i < yc.size(); i++) {
            if (!yc.get(i).equals(yc.get(i - 1)))    ys.add(yc.get(i));
        }
        int m = xs.size(), n = ys.size();
        boolean[][] cov = new boolean[m - 1][n - 1];
        for (int[] s : squares) {
            int x = s[0], y = s[1], len = s[2];
            for (int i = 0; i < m - 1; i++) {
                if (xs.get(i + 1) <= x || xs.get(i) >= x + len)    continue;
                for (int j = 0; j < n - 1; j++) {
                    if (ys.get(j + 1) <= y || ys.get(j) >= y + len)    continue;
                    cov[i][j] = true;
                }
            }
        }
        double tot = 0.0;
        for (int i = 0; i < m - 1; i++) {
            double wid = (double) (xs.get(i + 1) - xs.get(i));
            for (int j = 0; j < n - 1; j++) {
                if (cov[i][j]) {
                    double ht = (double) (ys.get(j + 1) - ys.get(j));
                    tot += wid * ht;
                }
            }
        }
        double div = tot / 2.0;
        double l = ys.get(0), h = ys.get(n - 1);
        for (int i = 0; i < 60; i++) {
            double mid = (l + h) / 2.0;
            double abv = 0.0;
            for (int k = 0; k < m - 1; k++) {
                double wid = (double) (xs.get(k + 1) - xs.get(k));
                for (int j = 0; j < n - 1; j++) {
                    if (!cov[k][j])    continue;
                    double bot = ys.get(j);
                    double top = ys.get(j + 1);
                    if (top <= mid)    continue;
                    if (bot >= mid)    abv += wid * (top - bot);
                    else    abv += wid * (top - mid);
                }
            }
            if (abv > div)    l = mid;
            else    h = mid;
        }
        return h;
    }
}
