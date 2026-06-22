class Solution {
    public int maxNumberOfBalloons(String text) {
        Map<Character, Integer> mp = new HashMap<>();
        for (char c : text.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }
        
        return Math.min(mp.getOrDefault('b', 0), 
               Math.min(mp.getOrDefault('a', 0), 
               Math.min(mp.getOrDefault('l', 0) / 2, 
               Math.min(mp.getOrDefault('o', 0) / 2, 
                        mp.getOrDefault('n', 0)))));
    }
}