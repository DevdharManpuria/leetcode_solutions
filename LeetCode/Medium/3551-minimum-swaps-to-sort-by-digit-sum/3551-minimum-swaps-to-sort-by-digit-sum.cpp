class Solution {
public:
    int sumdigits(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> target_indices(n);
        iota(target_indices.begin(), target_indices.end(), 0);
        sort(target_indices.begin(), target_indices.end(), [&](int i, int j) {
            int sumI = sumdigits(nums[i]);
            int sumJ = sumdigits(nums[j]);
            if (sumI != sumJ) {
                return sumI < sumJ; 
            }
            return nums[i] < nums[j]; 
        });
        vector<bool> visited(n, false);
        int total_swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || target_indices[i] == i) {
                continue;
            }
            int cycle_size = 0;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = target_indices[current];
                cycle_size++;
            }
            if (cycle_size > 1) {
                total_swaps += (cycle_size - 1);
            }
        }
        return total_swaps;
    }
};
