func getLongestSubsequence(words []string, groups []int) []string {
    var result []string
    last := -1
    for i := 0; i < len(words); i++ {
        if groups[i] != last {
            result = append(result, words[i])
            last = groups[i]
        }
    }
    return result
}