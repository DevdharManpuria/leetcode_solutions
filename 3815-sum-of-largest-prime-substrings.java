class Solution {
    public long sumOfLargestPrimes(String s) {
        Set<Long> primes = new HashSet<>();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            long num = 0;
            for (int j = i; j < n && j - i < 15; j++) {
                num = num * 10 + (s.charAt(j) - '0');
                if (num > 999999999999999L) break;
                if (num > 1 && isPrime(num)) {
                    primes.add(num);
                }
            }
        }
        List<Long> list = new ArrayList<>(primes);
        Collections.sort(list, Collections.reverseOrder());
        long sum = 0;
        for (int i = 0; i < Math.min(3, list.size()); i++) {
            sum += list.get(i);
        }
        return sum;
    }
    private boolean isPrime(long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
}