class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9 || (sum == 0 && num > 1)) 
            return "";
        string ans(num, '0');
        for (int i = 0; i < num && sum > 0; ++i) {
            int add = min(9, sum);
            ans[i] = '0' + add;
            sum -= add;
        }
        return ans;
    }
};