class Solution {
public:
    bool rotateString(string s, string g) {
        int n1 = s.size();
        int n2 = g.size();
        if(n1!=n2) return false;
        if(s==g) return true;
        
        for(int i=1;i<=n1-1;i++){
            char temp = s[0];
            for(int j=1;j<n1;j++){
                s[j-1] = s[j];
            }
            s[n1-1] = temp;
            if(s==g){
                return true;
            }
        }
        return false;
    }
};