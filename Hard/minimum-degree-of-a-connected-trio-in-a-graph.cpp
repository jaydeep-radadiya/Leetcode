// tc : O(n^3)
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // build 1 based array
        vector<int> degree(n+1,0);
        vector<vector<int>> adj(n+1,vector<int>(n+1,0));
        
        for(auto &t : edges){
            adj[t[0]][t[1]] = 1;
            adj[t[1]][t[0]] = 1;
            degree[t[0]]++;
            degree[t[1]]++;
        }
        
        int res = INT_MAX;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(adj[i][j]==1 && adj[j][k]==1 && adj[k][i]==1){
                        res = min(res,degree[i]+degree[j]+degree[k]-6);
                    }
                }
            }
        }
        
        if(res==INT_MAX) return -1; // no trio present
        return res;
    }
};

// tc : O(n^3)
// little bit optimised
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // build 1 based array
        vector<int> degree(n+1,0);
        vector<vector<int>> adj(n+1,vector<int>(n+1,0));
        
        for(auto &t : edges){
            adj[t[0]][t[1]] = 1;
            adj[t[1]][t[0]] = 1;
            degree[t[0]]++;
            degree[t[1]]++;
        }
        
        int res = INT_MAX;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(adj[i][j]==1){ // this condition is added
                    for(int k=j+1;k<=n;k++){
                        if(adj[j][k]==1 && adj[k][i]==1){
                            res = min(res,degree[i]+degree[j]+degree[k]-6);
                        }
                    }   
                }
            }
        }
        
        if(res==INT_MAX) return -1; // no trio present
        return res;
    }
};