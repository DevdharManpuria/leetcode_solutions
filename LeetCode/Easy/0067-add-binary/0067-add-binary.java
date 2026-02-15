public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() -1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum,t1=0,t2=0;
            if (j >= 0) t1= b.charAt(j--) - '0';
            if (i >= 0) t2= a.charAt(i--) - '0';
            sum=t1+t2+carry;
            if(sum>=2)
            {
                carry=1;
                sum=sum-2;
            }
            else 
             carry = 0;
            sb.append(sum);
        }
        if (carry == 1) sb.append(carry);
        return sb.reverse().toString();
    }
}