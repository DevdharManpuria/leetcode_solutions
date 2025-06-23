class Solution {
    public static int digSum(int i)
    {
        int sum = 0;
        while(i != 0)
        {
            sum += (i%10);
            i/=10;
        }
        return sum;
    }
    public int countLargestGroup(int n) {
        if(n < 10)
            return n;
        int freq[] = new int[37];
        for(int i=1;i<=n;i++)
        {
            int sum = digSum(i);
            freq[sum]++;
        }
        int max = Integer.MIN_VALUE;
        for(int x : freq)
        {
            if(x > max)
                max = x;
        }
        int count = 0;
        for(int x : freq)
        {
            if(x == max)
                count++;
        }
        return count;
    }
}