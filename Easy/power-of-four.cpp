class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        
        int cnt = __builtin_popcount(n);
        int rem = n%10;
        if((rem==4 or rem==6) and cnt==1)
            return true;
        else
            return false;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        return n%4==0 && isPowerOfFour(n/4);
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        long long val = 1;
        
        while(val<n){
            val = val*4;
        }
        return val==n;
    }
};