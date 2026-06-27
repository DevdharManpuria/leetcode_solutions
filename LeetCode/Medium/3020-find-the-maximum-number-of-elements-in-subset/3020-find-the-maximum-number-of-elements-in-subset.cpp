class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> hm;
        int max_len = 1;
        for(int i : nums)
            hm[i]++;
        for(int i : nums) {
            if(i == 1) {
                int len = hm[1];
                if(len % 2 == 0) len--;
                max_len = max(max_len, len);
                continue;
            }
            long long curr = i;
            int curr_len = 0;
            for(int j=0; j<=9; j++) {
                if(hm.find(curr) != hm.end() && hm[curr] >= 2) {
                    curr_len += 2;
                    curr = curr * curr;
                } 
                else if(hm.find(curr) != hm.end() && hm[curr] > 0) {
                    curr_len += 1;
                    break;
                } 
                else {
                    curr_len -= 1;
                    break;
                }
            }
            max_len = max(max_len, curr_len);
        }
        return max(1, max_len);
    }
};