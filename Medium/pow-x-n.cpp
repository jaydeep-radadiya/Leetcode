class Solution {
public:
    double solve(double x, int n){
        if(n==0)
            return 1;
        double temp = solve(x, n/2);
        if(n%2==0)
            return temp*temp;
        else
            return temp*x*temp;
    }

    double myPow(double x, int n) {
        double ans = solve(x,abs(n));
        if(n<0)
            return 1/ans;
        else
            return ans;
    }
};