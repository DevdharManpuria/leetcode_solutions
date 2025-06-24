class Solution {
public:
    int digSum(int i) {
        int sum = 0;
        while (i != 0) {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        if (n < 10)
            return n;
        vector<int> freq(37, 0); // Maximum digit sum for n <= 10000 is 36
        for (int i = 1; i <= n; ++i) {
            int sum = digSum(i);
            freq[sum]++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int count = count_if(freq.begin(), freq.end(), [maxFreq](int x) { return x == maxFreq; });

        return count;
    }
};
