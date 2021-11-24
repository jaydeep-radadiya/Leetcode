// brute force
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1; // # nodes
        vector<int> arr(n+1,0); // 1 based indexing
        for(auto &t : edges){
            arr[t[0]]++;
            arr[t[1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(arr[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};

// tc : O(1)
// center node must appear in every edge
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0]==edges[1][0])
            return edges[0][0];
        else if(edges[0][0]==edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
    }
};