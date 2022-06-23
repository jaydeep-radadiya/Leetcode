class Solution {
public:
    int findComplement(int num) {
        long long p = 1;
        int sum = 0;
        while(num>0){
            sum += (num%2==0?1:0)*p;
            num = num/2;
            p = 2*p;
        }
        return sum;
    }
};