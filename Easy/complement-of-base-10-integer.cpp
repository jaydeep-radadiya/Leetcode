class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int sum = 0;
        int p = 1;
        while(n>0){
            sum += ((n%2==1)?0:1)*p;
            p = 2*p;
            n = n/2;
        }
        return sum;
    }
};