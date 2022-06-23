class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int ans = 1;
        
        for(int i=0;i<n;i++){
            int cnt = 1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    ans = max(ans,++cnt);
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int ans = 1;
        int p = 1;
        
        for(int i=1;i<n;i++){
            char curr = s[i];
            char prev = s[i-1];
            if(curr==prev){
                ans = max(ans,++p);
            }
            else{
                p = 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int res = 0;
        int i = 0;
        
        while(i<n){
            int j = i+1;
            while(j<n && s[i]==s[j]){
                j++;
            }
            res = max(res,j-i);
            i = j;
        }
        return res;
    }
};