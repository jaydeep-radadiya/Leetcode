// tc : O(3^n)
class Solution {
public:
    int tribonacci(int n) {
        if(n<=1)
            return n;
        else if(n==2)
            return 1;
        else
            return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};

// tc : O(n) sc : O(n)
class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        
        vector<int> arr(n+1);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        for(int i=3;i<=n;i++){
            arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
        }
        return arr[n];
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        int a = 0, b = 1, c = 1, d;
        for(int i=3;i<=n;i++){
            d = a+b+c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};