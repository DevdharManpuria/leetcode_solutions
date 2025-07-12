class Solution {
    public int calculate(String s) {
        if(s == null || s.length() == 0){
            return 0;
        }
        char last = '+';
        int calc = 0, tail = 0, curr = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(Character.isDigit(c)){
                curr = curr * 10 + (c - '0');
            }
            if((!Character.isDigit(c) && c != ' ') || i == s.length() - 1){
                if(last == '+'){
                    calc = calc + curr;
                    tail = curr;
                }
                else if(last == '-'){
                    calc = calc - curr;
                    tail = -curr;
                }
                else if(last == '*'){
                    calc = (calc - tail) + (tail * curr);
                    tail = tail * curr;
                }
                else{
                    calc = (calc - tail) + (tail / curr);
                    tail = tail / curr;
                }
                curr = 0;
                last = c;
            }
        }
        return calc;
    }
}