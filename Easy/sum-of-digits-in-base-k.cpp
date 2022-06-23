// tc : O(log(n base k)) sc : O(1)
class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        while(n>0){
            int rem = n%k;
            sum += rem;
            n = n/k;
        }
        return sum;
    }
};

// recursive solution
class Solution {
public:
    int sumBase(int n, int k) {
        if(n==0) return 0;
        return n%k+sumBase(n/k,k);
    }
};