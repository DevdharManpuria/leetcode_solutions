class Solution {
public:
    int calculate(string s) {
        long result = 0, last = 0, curr = 0;
        char op = '+';                  
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                curr = curr * 10 + (c - '0');
            }
            if ((!isdigit(c) && !isspace(c)) || i == n - 1) {
                switch (op) {
                    case '+':
                        result += last;   
                        last = curr;      
                        break;
                    case '-':
                        result += last;
                        last = -curr;
                        break;
                    case '*':
                        last = last * curr;
                        break;
                    case '/':
                        last = last / curr; 
                        break;
                }
                op = c;    
                curr = 0;  
            }
        }
        result += last;  
        return (int)result;
    }
};