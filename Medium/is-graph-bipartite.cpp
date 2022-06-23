class Solution {
public:
    bool checkBipartite(int node,vector<int> &col,vector<vector<int>> &graph){
        if(col[node]==-1) col[node] = 1;
        
        for(int neighbour : graph[node]){
            if(col[neighbour]==-1){
                col[neighbour] = 1^col[node];
                if(checkBipartite(neighbour,col,graph)==false){
                    return false;
                }
            }
            else if(col[neighbour]!=-1 && col[neighbour]==col[node]){
                // visited and has same color
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(checkBipartite(i,col,graph)==false){ 
                    // graph contain odd length cycle
                    return false;
                }
            }
        }
        return true;
    }
};