class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        int xc = x;
        long long sum = 0;
        while(x>0){
            sum = sum*10+x%10;
            x = x/10;
        }
        
        if(sum==xc)
            return true;
        else
            return false;
    }
};