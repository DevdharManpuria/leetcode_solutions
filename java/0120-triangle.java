class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int row = triangle.size();
        int[] line = new int[row];
        for(int i=0;i<row;i++){
            line[i]=triangle.get(row-1).get(i);
        }
        for(int r=row-2;r>=0;r--){
            for(int c=0;c<=r;c++){
                line[c]=Math.min(line[c],line[c+1])+triangle.get(r).get(c);
            }
        }
        return line[0];
    }
}