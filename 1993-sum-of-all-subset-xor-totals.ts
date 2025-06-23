function subsetXORSum(nums: number[]): number {
    let allBits = 0;
    for (let j = 0; j < nums.length; j++) {
        allBits |= nums[j]
    }
    return allBits << (nums.length - 1)
};