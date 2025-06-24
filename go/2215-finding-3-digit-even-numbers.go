func findEvenNumbers(digits []int) []int {
    // count digits
    cnt := make([]int, 10)
    for _,d := range digits { cnt[d]++ }
    // try all 3-digit even numbers
    res := make([]int, 0)
    for i:=100; i<1000; i+=2 {
        if can(cnt, i) { res = append(res, i) }
    }
    return res
}
// returns true if number n can be constructed from cnt digits
func can(cnt []int, n int) bool {
    // count digits 0 to 9 in the number
    for d:=0; d<10; d++ {
        dc := 0
        if n / 100 == d { dc++ }
        if (n % 100) / 10 == d { dc++ }
        if n % 10 == d { dc++ }
        // check if cnt has sufficient digits
        if dc > cnt[d] { return false }
    }
    return true
}