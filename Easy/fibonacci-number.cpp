// first method
class Solution {
public:
    int fib(int n) {
        if(n==0 or n==1)
            return n;
        return fib(n-1)+fib(n-2);
    }
};

// second method
class Solution {
public:
    int fib(int n) {
        int a = -1;
        int b = 1;
        int c;
        
        for(int i=0;i<=n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};

// third method
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        vector<int> ans(n+1,-1);
        ans[0] = 0;
        ans[1] = 1;
        
        for(int i=2;i<=n;i++){
            ans[i] = ans[i-1]+ans[i-2];
        }
        return ans[n];
    }
};

// forth method
class Solution {
public:
    int fib(int n) {
        double phi = (sqrt(5)+1)/2;
        int ans = round(pow(phi,n)/sqrt(5));
        return ans;
    }
};