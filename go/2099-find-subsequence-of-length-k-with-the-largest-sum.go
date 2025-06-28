import (
    "sort"
)

func maxSubsequence(nums []int, k int) []int {
    type Pair struct {
        val int
        idx int
    }

    valueWithIndex := make([]Pair, len(nums))
    for i, num := range nums {
        valueWithIndex[i] = Pair{val: num, idx: i}
    }

    sort.Slice(valueWithIndex, func(i, j int) bool {
        return valueWithIndex[i].val > valueWithIndex[j].val
    })

    topK := valueWithIndex[:k]

    sort.Slice(topK, func(i, j int) bool {
        return topK[i].idx < topK[j].idx
    })

    result := make([]int, k)
    for i, p := range topK {
        result[i] = p.val
    }
    return result
}
