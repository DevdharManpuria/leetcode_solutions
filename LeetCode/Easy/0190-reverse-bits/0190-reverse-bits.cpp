class Solution {
public:
    int reverseBits(int n) {
        uint32_t unsigned_n = n; 
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;               
            res |= (unsigned_n & 1); 
            unsigned_n >>= 1;        
        }
        return res; 
    }
};