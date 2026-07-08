class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        vector<int> st;
        int prev = 0;
        for (const string& log : logs) {
            int pos1 = log.find(':');
            int pos2 = log.find(':', pos1 + 1);
            int id = stoi(log.substr(0, pos1));
            string type = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int curr = stoi(log.substr(pos2 + 1));
            if (type == "start") {
                if (!st.empty()) {
                    ans[st.back()] += curr - prev;
                }
                st.push_back(id);
                prev = curr;
            } else {
                ans[st.back()] += curr - prev + 1;
                st.pop_back();
                prev = curr + 1;
            }
        }
        return ans;
    }
};
