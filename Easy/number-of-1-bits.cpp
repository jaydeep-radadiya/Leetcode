class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n>0){
            if(n&1){
                cnt++;
            }
            n = n>>1;
        }
        return cnt;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n==0)
            return 0;
        else
            return (n&1) + hammingWeight(n>>1);
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n>0){
            cnt++;
            n = (n)&(n-1);
        }
        return cnt;
    }
};