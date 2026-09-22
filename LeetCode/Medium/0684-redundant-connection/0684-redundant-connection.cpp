class Solution {
public:
    int findLeader(int node,vector<int>& parent){
        if(parent[node]==node) return node;
        return parent[node] = findLeader(parent[node],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1,0);
        for(int i=1;i<n+1;i++){
            parent[i] = i;
        }
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(findLeader(u,parent) == findLeader(v,parent)) return edge;
            parent[findLeader(v,parent)] = findLeader(u,parent);
        }
        return {};
    }
};