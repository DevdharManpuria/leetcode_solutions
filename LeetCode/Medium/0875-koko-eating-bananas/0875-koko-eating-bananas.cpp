class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi = maxele(piles);
        int lo = 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            long long t = tothr(piles, mid); 
            if(t <= h) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
    int maxele(vector<int>& arr){
        int la = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            la = max(la, arr[i]);
        }
        return la;
    }
    long long tothr(vector<int>& arr, int k){
        long long tot = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            tot += arr[i] / k + (arr[i] % k != 0); 
        }
        return tot; 
    }
};