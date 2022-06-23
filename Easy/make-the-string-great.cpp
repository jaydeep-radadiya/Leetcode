class Solution {
public:
    string makeGood(string s) {
        bool change = true;
        
        while(change){
            change = false;
            string t = s;
            for(int i=0;i<(int)s.size()-1;i++){
                if(s[i]+32==s[i+1] or s[i]-32==s[i+1]){
                    t = s.substr(0,i) + s.substr(i+2);
                    change = true;
                    break;
                }
            }
            s = t;
        }
        return s;
    }
};