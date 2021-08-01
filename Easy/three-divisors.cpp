class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for(int i=1;i<=sqrt(n);i++){
            if(i*i==n)
                cnt += 1;
            else if(n%i==0)
                cnt += 2;
        }
        
        if(cnt==3)
            return true;
        else
            return false;
    }
};