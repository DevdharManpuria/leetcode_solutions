func subsetXORSum(nums []int) int {
    var dfs func(int, int) int
    dfs = func(index, currentXOR int) int {
        if index == len(nums) {
            return currentXOR
        }
        with := dfs(index+1, currentXOR^nums[index])
        without := dfs(index+1, currentXOR)
        return with + without
    }
    return dfs(0, 0)
}
