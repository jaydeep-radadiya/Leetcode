class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // to be a town judge node has : indegree : n-1 && outdegree : 0
        if(n==1) return 1;
        vector<int> in(n+1);
        vector<int> out(n+1);
        
        for(auto temp : trust){
            out[temp[0]]++;
            in[temp[1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(in[i]==n-1 and out[i]==0){
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int> count(n+1,0);
        
        for(auto temp : trust){
            count[temp[0]]--; // outgoing edge
            count[temp[1]]++; // incoming edge
        }
        
        for(int i=0;i<=n;i++){
            if(count[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};