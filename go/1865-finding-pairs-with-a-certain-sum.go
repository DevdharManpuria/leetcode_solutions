type FindSumPairs struct {
    nums1 []int
    nums2 []int
    dp map[int]int
}
func Constructor(nums1 []int, nums2 []int) FindSumPairs {
    fs:=FindSumPairs{nums1:nums1,nums2:nums2}
    fs.dp=make(map[int]int)
    for i:=0; i<len(nums2); i++{
        fs.dp[fs.nums2[i]]++
    }
    return fs
}
func (this *FindSumPairs) Add(index int, val int)  {
    old:=this.nums2[index]
    this.nums2[index]=val+old
    this.dp[old]--
    if this.dp[old]==0{
        delete(this.dp,old)
    }
    this.dp[val+old]++
}
func (this *FindSumPairs) Count(tot int) int {
    count:=0
    for i:=0; i<len(this.nums1); i++{
        remainVal:=tot-this.nums1[i]
        if v,ok:=this.dp[remainVal]; ok{
            count+=v
        }
    }
    return count
}