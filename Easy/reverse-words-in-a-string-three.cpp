class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string ans = "";
        
        string temp;
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            ans += temp;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int front = 0;
        
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                reverse(s.begin()+front,s.begin()+i);
                front = i+1;
            }
            else if(i==n-1){
                reverse(s.begin()+front,s.begin()+i+1);
            }
        }
        return s;
    }
};