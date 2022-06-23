class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i = 0;
        while(i<n && s[i]=='1'){
            i++;
        }
        
        if(i==n) return true;
        for(int j=i;j<n;j++){
            if(s[j]=='1'){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkOnesSegment(string s) {
        return string::npos==s.find("01");
    }
};

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        
        for(int i=1;i<n;i++){
            if(s[i]=='1' && s[i-1]=='0'){
                return false;
            }
        }
        return true;
    }
};