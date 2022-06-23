class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.size();
        int upper = 0, lower = 0;
        for(int i=0;i<n;i++){
            if(s[i]>=65 && s[i]<=90) upper++;
            else lower++;
        }
        if(upper==n or lower==n) return true;
        else if(upper==1 && s[0]>=65 && s[0]<=90) return true;
        else return false;
    }
};