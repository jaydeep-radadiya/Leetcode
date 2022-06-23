// tc : O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};

// tc : O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> ans(n+1,0);
        ans[1] = 1;
        for(int i=2;i<=n;i++){
            ans[i] = ans[i/2]+i%2;
        }
        return ans;
    }
};

// tc : (n)
// find the pattern
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int j = 1;
        for(int i=1;i<=n;i++){
            if(2*j==i){
                j = 2*j;
            }
            ans[i] = ans[i-j]+1;
        }
        return ans;
    }
};