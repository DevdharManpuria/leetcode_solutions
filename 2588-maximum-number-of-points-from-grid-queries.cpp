
class Solution {
public:
    #define pii pair<int,int>
    vector<int> maxPoints(vector<vector<int>>& arr, vector<int>& queries) {
        int n = arr.size(), m = arr[0].size(), len = queries.size();
        queue<int> q;
        priority_queue<pii, vector<pii>, greater<pii>> pq; // {val, node}
        vector<bool> vis(n*m, false), pqvis(n*m, false);
        vector<int> ans(len);
        vector<pii> tempqueries(len);
        for (int i = 0; i < len; i++) {
            tempqueries[i] = {queries[i], i};
        }
        sort(tempqueries.begin(), tempqueries.end());
        pq.push({arr[0][0], 0});
        pqvis[0] = 1;
        int delx[4] = {-1,0,1,0}, dely[4] = {0,1,0,-1};
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            int ind = tempqueries[i].second;
            int val = tempqueries[i].first;
            while(!pq.empty() && pq.top().first < val) {
                q.push(pq.top().second);
                vis[pq.top().second] = 1;
                pq.pop();
            }
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                cnt++;
                int x = node/m, y = node%m;
                for (int k = 0; k < 4; k++) {
                    int newx = x + delx[k];
                    int newy = y + dely[k];
                    int newnode = newx * m + newy;
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && vis[newnode] == 0) {
                        int newval = arr[newx][newy];
                        if(newval < val) {
                            vis[newnode] = 1;
                            q.push(newnode);
                        }
                        else if(pqvis[newnode] == 0) {
                            pq.push({newval, newnode});
                            pqvis[newnode] = 1;
                        }
                    }
                }
            }
            ans[ind] = cnt;
        }
        return ans;
    }
};
