class Solution {
public:
    int reverse(int x) {
        int xc = x;
        long long sum = 0; // this is not allowed
        
        x = abs(x);
        while(x>0){
            int rem = x%10;
            sum = sum*10+rem;
            x = x/10;
        }
        
        if(xc<0)
            sum = -1*sum;
        
        if(sum>INT_MAX or sum<INT_MIN)
            return 0;
        else
            return sum;
    }
};