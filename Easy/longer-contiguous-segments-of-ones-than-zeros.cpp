class Solution {
public:
    int solve(string s,char val){
        int n = s.size();
        int cnt = 0;
        int mx = 0;
        
        for(int i=0;i<n;i++){
            if(s[i]==val)
                mx = max(mx,++cnt);
            else
                cnt = 0;
        }
        return mx;
    }
    
    bool checkZeroOnes(string s) {
        int one = solve(s,'1');
        int zero = solve(s,'0');
        
        if(one>zero)
            return true;
        else
            return false;
    }
};