class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> dp(26,{INT_MAX,INT_MIN});
        for(int i=0;i<size(s);i++){
            dp[s[i]-'a'].first = min(i,dp[s[i]-'a'].first);
            dp[s[i]-'a'].second = max(i,dp[s[i]-'a'].second);
        }
        sort(dp.begin(),dp.end());
        vector<int> ans;
        int prev_closed = -1;
        int prev_pushed = 0;
        for(int i=0;i<26;i++){
            if(dp[i].first==INT_MAX){
                break;
            }
            if(dp[i].first>=prev_closed){
                if(prev_pushed<dp[i].first){
                    ans.push_back(dp[i].first-prev_pushed);
                }
                prev_pushed = dp[i].first;
                prev_closed = dp[i].second;
            }else{
                prev_closed = max(prev_closed,dp[i].second);
            }
        }
        ans.push_back(size(s)-prev_pushed);
        return ans;
    }
};