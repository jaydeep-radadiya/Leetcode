class Solution {
private:
    bool is_prime(int n){
        if(n<=1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i=left;i<=right;i++){
            int set_bits = __builtin_popcount(i);
            if(is_prime(set_bits)){
                cnt++;
            }
        }
        return cnt;
    }
};