class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 and s[i]<=90){
                s[i] = s[i]+32;
            }
        }
        
        string ans = "";
        for(int i=0;i<s.size();i++){
            if((s[i]>=97 and s[i]<=122) or (s[i]>=48 and s[i]<=57)){
                ans.push_back(s[i]);
            }
        }
        
        int left = 0;
        int right = ans.size()-1;
        while(left<right){
            if(ans[left]!=ans[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};