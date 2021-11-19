class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = x^y; // cnt the set bits
        return __builtin_popcount(val);
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> xb(x), yb(y);
        int cnt = 0;
        for(int i=0;i<32;i++){
            if(xb[i]!=yb[i]){
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = x^y;
        int cnt = 0;
        while(val>0){
            cnt++;
            val = (val)&(val-1);
        }
        return cnt;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> ans(x^y);
        return ans.count();
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        for(int i=0;i<32;i++){
            if(((x>>i)&1)!=((y>>i)&1)){
                cnt++;
            }
        }
        return cnt;
    }
};