class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0;i<=sqrt(n)+1;i++){
            if(pow(2,i)==n){
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        
        int cnt = __builtin_popcount(n);
        if(cnt==1)
            return true;
        else
            return false;
    }
};