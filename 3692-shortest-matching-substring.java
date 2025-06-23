import java.util.*;

class Solution {
    private int[] kmp(String s, int m) {
        int n = s.length();
        int[] lps = new int[n + 1]; // Initialized to 0 by default
        for (int i = 1; i < n; i++) {
            int prev = lps[i - 1];
            while (prev > 0 && s.charAt(i) != s.charAt(prev)) {
                prev = lps[prev - 1];
            }
            lps[i] = prev + (s.charAt(i) == s.charAt(prev) ? 1 : 0);
        }
        return lps;
    }

    public int shortestMatchingSubstring(String s, String p) {
        int n = s.length();
        int m = p.length();

        if (m == 2) {
            return 0;
        }

        List<Integer> v = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            if (p.charAt(i) == '*') {
                v.add(i);
            }
        }

        String a = p.substring(0, v.get(0));
        String b = p.substring(v.get(0) + 1, v.get(1));
        String c = p.substring(v.get(1) + 1);

        int na = a.length();
        int nb = b.length();
        int nc = c.length();

        int[] v1 = kmp(a + "#" + s, na);
        int[] v2 = kmp(b + "#" + s, nb);
        int[] v3 = kmp(c + "#" + s, nc);

        v1 = Arrays.copyOfRange(v1, na + 1, v1.length);
        v2 = Arrays.copyOfRange(v2, nb + 1, v2.length);
        v3 = Arrays.copyOfRange(v3, nc + 1, v3.length);

        int res = Integer.MAX_VALUE;
        int i = 0, j = 0, k = 0;

        while (i + nb + nc < v1.length) {
            while (i < v1.length && v1[i] != na) i++;
            if (i >= v1.length) break;

            while (j < v2.length && (j < i + nb || v2[j] != nb)) j++;
            if (j >= v2.length) break;

            while (k < v3.length && (k < j + nc || v3[k] != nc)) k++;
            if (k >= v3.length) break;

            res = Math.min(res, k - i + na);
            i++;
        }

        return res == Integer.MAX_VALUE ? -1 : res;
    }
}
