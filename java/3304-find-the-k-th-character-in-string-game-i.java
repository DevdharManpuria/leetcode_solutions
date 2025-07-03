class Solution {
    public char kthCharacter(int k) {
        int length = 1;
        char ch = 'a';
        while (length < k) {
            length *= 2;
        }
        while (length > 1) {
            int half = length / 2;
            if (k > half) {
                k -= half;
                ch = (char)((ch - 'a' + 1) % 26 + 'a');
            }
            length = half;
        }
        return ch;
    }
}