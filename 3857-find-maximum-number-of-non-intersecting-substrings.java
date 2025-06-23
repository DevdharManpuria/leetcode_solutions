class Solution {
    public int maxSubstrings(String word) {
       int n = word.length();
        List<Integer>[] pos = new ArrayList[26];
        for (int i = 0; i < 26; i++) pos[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) pos[word.charAt(i) - 'a'].add(i);
        List<int[]> intervals = new ArrayList<>();
        for (int i = 0; i <= n - 4; i++) {
            List<Integer> lst = pos[word.charAt(i) - 'a'];
            int idx = Collections.binarySearch(lst, i + 3);
            if (idx < 0) idx = -idx - 1;
            if (idx < lst.size()) intervals.add(new int[]{lst.get(idx), i});
        }
        intervals.sort(Comparator.comparingInt(a -> a[0]));
        int count = 0, lastEnd = -1;
        for (int[] iv : intervals) {
            if (iv[1] > lastEnd) {
                count++;
                lastEnd = iv[0];
            }
        }
        return count;
    }
}

