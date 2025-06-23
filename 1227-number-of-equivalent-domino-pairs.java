class Solution {
    public static int numEquivDominoPairs(int[][] dominoes) {
        int[] counter = new int[100]; 
        for (int[] domino : dominoes) {
            int a = domino[0], b = domino[1];
            int normalized = a < b ? a * 10 + b : b * 10 + a;
            counter[normalized]++;
        }
        int totalPairs = 0;
        for (int count : counter) {
            totalPairs += count * (count - 1) / 2;
        }
        return totalPairs;
    }
}
