func nthUglyNumber(n int) int {
    dp := make([]int, n)
    dp[0] = 1
    i2, i3, i5 := 0, 0, 0
    for i := 1; i < n; i++ {
        next2 := 2 * dp[i2]
        next3 := 3 * dp[i3]
        next5 := 5 * dp[i5]
        dp[i] = min(next2, next3, next5)
        if dp[i] == next2 {
            i2++
        }
        if dp[i] == next3 {
            i3++
        }
        if dp[i] == next5 {
            i5++
        }
    }
    return dp[n-1]
}
func min(a, b, c int) int {
    if a < b {
        if a < c {
            return a
        }
        return c
    } else {
        if b < c {
            return b
        }
        return c
    }
}