class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        backtrack(candidates, target, 0, temp, result);
        return result;
    }
    private void backtrack(int[] candidates, int target, int start, List<Integer> temp, List<List<Integer>> result) {
        if (target == 0) {
            result.add(new ArrayList<>(temp));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (target < candidates[i]) continue;
            temp.add(candidates[i]);
            backtrack(candidates, target - candidates[i], i, temp, result);
            temp.remove(temp.size() - 1);
        }
    }
}