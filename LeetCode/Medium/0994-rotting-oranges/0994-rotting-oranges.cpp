class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i,j}); 
            }
        }
        if (fresh == 0) return 0;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int si = q.size();
            bool pushed = false;
            while(si>0){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r+dirs[i][0];
                    int nc = c+dirs[i][1];
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        if(grid[nr][nc] == 1){
                            grid[nr][nc] = 2;
                            fresh--;
                            q.push({nr,nc});
                            pushed = true;
                        }
                    }
                }
                si--;
            }
            if(pushed) ans++;
        }
        return fresh == 0 ? ans : -1;
    }
};