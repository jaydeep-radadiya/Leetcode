// brute force
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int rank = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt = 0;
                for(auto &t : roads){
                    if(t[0]==i || t[0]==j || t[1]==i || t[1]==j){
                        cnt++;
                    }
                }
                rank = max(rank,cnt);
            }
        }
        return rank;
    }
};

// accepted tc : O(n^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n,0);
        vector<vector<int>> direct(n,vector<int>(n,0));
        
        for(auto &t : roads){
            cnt[t[0]]++;
            cnt[t[1]]++;
            direct[t[0]][t[1]] = 1;
            direct[t[1]][t[0]] = 1;
        }
        
        int rank = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                rank = max(rank,cnt[i]+cnt[j]-direct[i][j]);
            }
        }
        return rank;
    }
};

// tc : O(n) not possible