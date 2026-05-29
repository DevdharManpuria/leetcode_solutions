class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) 
            swap(a, b);
        int total = a.size() + b.size();
        int l = 0;
        int r = a.size(); 
        int leftPartitionSize = (total + 1) / 2; 
        while (l <= r) {
            int midA = l + (r - l) / 2;
            int midB = leftPartitionSize - midA;
            int aleft = (midA > 0) ? a[midA - 1] : INT_MIN;
            int aright = (midA < a.size()) ? a[midA] : INT_MAX;
            int bleft = (midB > 0) ? b[midB - 1] : INT_MIN;
            int bright = (midB < b.size()) ? b[midB] : INT_MAX;
            if (aleft <= bright && bleft <= aright) {
                if (total % 2 != 0) 
                    return max(aleft, bleft);
                return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            }
            else if (aleft > bright)    r = midA - 1;
            else    l = midA + 1;
        }
        return 0.0;
    }
};