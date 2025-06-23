vector<int> bucket[256]; 
void radix_sort(vector<int>& nums) {
    auto [m, M]=minmax_element(nums.begin(), nums.end());
    unsigned xrange=*M-*m+1;
    int round = max(1, int(32-countl_zero(xrange)+7)/8), xmin=*m;
    for (int& x : nums) {
        x-=xmin; 
        bucket[x & 255].push_back(x);
    }
    int i = 0;
    for (auto& B : bucket) {
        for (auto v : B)
            nums[i++] = v+(round==1?xmin:0);
        B.clear();
    }
    for (int rd=1; rd < round-1; rd++) {
        int shift=rd*8; 
        for (auto& x : nums)
            bucket[(x >> shift) & 255].push_back(x);

        i=0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[i++] = v;
            B.clear(); 
        }
    }
    if (round > 1) {
        int shift =8* (round-1); 
        for (auto& x : nums)
            bucket[x >> shift].push_back(x);

        i=0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[i++] =v+xmin; 
            B.clear();             
        }
    }
}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        const int n = meetings.size(), N=2*n;
        vector<int> info(N);
        int i=0; 
        for (auto& m : meetings) {
            const int s= m[0], e=m[1];
            info[i++]=(s<<1)|1;  
            info[i++]=(e+1)<<1;  
        }
        radix_sort(info);
        int overlap=0, cnt=0, last=1;
        for (int i=0; i<N; i++) {
            const int x=info[i]>>1;    
            const bool isStart=info[i]&1; 
            if (overlap==0 && last<x) 
                cnt+=(x-last);
            overlap+=isStart?1:-1;  
            if(overlap==0) last=x;   
        }
        if (last<=days) 
            cnt+=(days-last+1);

        return cnt;
    }
};