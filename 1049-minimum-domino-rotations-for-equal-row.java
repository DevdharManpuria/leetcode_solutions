class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1) return rotations;
        return check(bottoms[0], tops, bottoms);
    }
    private int check(int x, int[] tops, int[] bottoms) {
        int topRotations = 0;
        int bottomRotations = 0;
        for (int i = 0; i < tops.length; i++) {
            if (tops[i] != x && bottoms[i] != x) {
                return -1;  
            } else if (tops[i] != x) {
                topRotations++; 
            } else if (bottoms[i] != x) {
                bottomRotations++; 
            }
        }
        return Math.min(topRotations, bottomRotations);
    }
}
