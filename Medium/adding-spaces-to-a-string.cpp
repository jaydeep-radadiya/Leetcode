class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        
        string ans = "";
        for(int i=0,idx=0;i<s.size();){
            if(idx<n && i==spaces[idx]){
                ans += ' ';
                idx++;
            }
            else{
                ans += s[i++];   
            }
        }
        return ans;
    }
};