class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        string ans = "";
        
        for(int i=0;i<n;i++){
            if(i%2==1)
                ans.push_back(s[i-1]+(s[i]-'0')); // (s[i]-'0') jump
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};

// simple
class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for(int i=1;i<n;i+=2){
            s[i] = s[i-1]+(s[i]-'0');
        }
        return s;
    }
};