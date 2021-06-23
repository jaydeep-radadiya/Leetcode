class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;
        long long res = -1;

        while(left<=right){
            long long mid = left+(right-left)/2;

            if(mid*mid==x)
                return mid;
            else if(mid*mid>x)
                right = mid-1;
            else if(mid*mid<x){
                res = mid;
                left = mid+1;
            }
        }
        return res;
    }
};