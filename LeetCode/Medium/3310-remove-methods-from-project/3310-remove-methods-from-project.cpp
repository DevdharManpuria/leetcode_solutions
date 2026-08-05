class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> g(n);
        for (auto& e : inv) g[e[0]].push_back(e[1]);        
        unordered_set<int> s;
        queue<int> q;
        q.push(k);
        s.insert(k);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (!s.count(v)) {
                    s.insert(v);
                    q.push(v);
                }
            }
        }
        for (auto& e : inv) {
            if (!s.count(e[0]) && s.count(e[1])) {
                vector<int> res(n);
                iota(res.begin(), res.end(), 0);
                return res;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!s.count(i)) res.push_back(i);
        }
        return res;
    }
};