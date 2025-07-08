func finalPrices(prices []int) []int {
    j := 1
    for i := 0; i < len(prices)-1; i++ {
        if prices[j] <= prices[i] {
            prices[i] = prices[i] - prices[j]
            j = i+2
        } else if j+1 == len(prices) {
            j = i+2
        } else {
            i--
            j++
        }
    }
    return prices
}