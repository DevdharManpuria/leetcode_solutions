class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),lo=0,hi=n*m-1;
        while(lo<=hi){
            int mi=lo+(hi-lo)/2,ro=mi/m,co=mi%m;
            if(matrix[ro][co]==target) return true;
            else 
                matrix[ro][co]<target ? lo++ : hi--;
        }
        return false;
    }
};