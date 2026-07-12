class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> cp(arr);
        sort(cp.begin(),cp.end());
        cp.erase(unique(cp.begin(),cp.end()),cp.end());
        for(int i = 0;i<arr.size();i++) 
            arr[i] = lower_bound(cp.begin(),cp.end(),arr[i]) - cp.begin() + 1;
        return arr;
    }
};