class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int idx = 0;
        
        while(idx<n and s[idx]=='a'){
            idx++;
        }
        
        while(idx<n){
            if(s[idx]=='a'){
                return false;
            }
            idx++;
        }
        return true;
    }
};