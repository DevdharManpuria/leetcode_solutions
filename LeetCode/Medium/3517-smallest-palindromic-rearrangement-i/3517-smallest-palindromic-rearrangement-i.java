class Solution {
    public String smallestPalindrome(String s) {
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }        
        String l = "";
        String m = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            char ch = (char) (i + 'a');
            if (freq[i] % 2 != 0) {
                m = String.valueOf(ch);
            }
            l += String.valueOf(ch).repeat(freq[i] / 2);
        }
        String r = new StringBuilder(l).reverse().toString();
        return l + m + r;
    }
}
