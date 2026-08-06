class Solution {
    public int smallestNumber(int n, int t) {
        for (int k, p = 1; ; n++, p = 1) {
            for (k = n; k > 0; k /= 10) p *= (k % 10);
            if (p % t == 0) return n;
        }
    }
}