class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; ++i) 
            jobs[i] = {difficulty[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int res = 0, i = 0, best = 0;
        for (int w : worker) {
            while (i < n && w >= jobs[i].first) {
                best = max(best, jobs[i].second);
                i++;
            }
            res += best;
        }
        return res;
    }
};