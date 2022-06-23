class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = words.size();
        string ans = "";
        for(int i=0;i<n;i++){
            ans += words[i];
            if(s==ans){
                return true;
            }
        }
        return false;
    }
};