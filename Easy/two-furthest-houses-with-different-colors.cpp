// tc : O(n^2)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                if(colors[i]!=colors[j]){
                    ans = max(ans,j-i);
                }
            }
        }
        return ans;
    }
};

// tc : O(n)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        
        int i = 0; // n-1 idx is fixed
        while(colors[i]==colors[n-1]) i++; // dist : n-1-i
        
        int j = n-1; // 0 idx is fixed
        while(colors[0]==colors[j]) j--; // dist : j
        
        return max(j,n-1-i);
    }
};