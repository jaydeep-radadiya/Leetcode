class Solution {
public:
    int reverse(int x) {
        long long int sum = 0;
        
        if(x/10==0)
            return x;
        
        while(x!=0){
            sum = sum*10+x%10;  // -12%10 --> -2
            x /= 10;            // -12/10 --> -1
        }
        
        if(sum<INT_MIN || sum>INT_MAX)
            return 0;
        else
            return sum;
    }
};