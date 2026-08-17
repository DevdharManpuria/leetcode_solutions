class Solution {
public:
    bool isInterleave(string s1, string s2, string s3){
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1));
        dp[0][0] = true;
        for (int i=1;i<=s1.size();i++)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for(int j=1;j<=s2.size();j++)
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        for (int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if ((dp[i-1][j] == true && s1[i-1]==s3[i+j-1])
                    || 
                    dp[i][j-1] == true && s2[j-1] == s3[i+j-1])
                    dp[i][j] = true;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};