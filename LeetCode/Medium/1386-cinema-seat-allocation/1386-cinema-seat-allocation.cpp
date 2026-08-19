class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int,int> mp;
        for(auto& it:res){
            int a = it[0];
            int b = it[1];
            mp[a] |= (1 << b);
        }
        int max = 2 * n;
        for(auto& [r,m] : mp){
            max -=2;
            bool l = (60 & m) == 0;
            bool mi = (240 & m) == 0;
            bool ri = (960 & m) == 0;
            if(l&&ri) max+=2;
            else if (l || ri || mi) max+=1;
        } 
        return max;
    }
};