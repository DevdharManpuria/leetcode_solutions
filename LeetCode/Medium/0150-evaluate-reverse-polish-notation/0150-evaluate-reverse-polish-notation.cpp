class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int r = st.back(); st.pop_back();
                int l = st.back(); st.pop_back();
                if (t == "+") st.push_back(l + r);
                else if (t == "-") st.push_back(l - r);
                else if (t == "*") st.push_back(l * r);
                else st.push_back(l / r);
            } else {
                st.push_back(stoi(t));
            }
        }
        return st.back();
    }
};
