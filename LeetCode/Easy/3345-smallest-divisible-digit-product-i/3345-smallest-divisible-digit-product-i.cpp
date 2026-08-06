class Solution {
public:
    int smallestNumber(int n, int t) {
        for (; ; n++) {
            int p = 1, k = n;
            for (; k > 0; k /= 10) p *= (k % 10);
            if (p % t == 0) return n;
        }
    }
};