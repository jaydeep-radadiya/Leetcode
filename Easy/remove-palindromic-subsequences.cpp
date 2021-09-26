class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;
        else if(isPalindrome(s)==true)
            return 1;
        else
            return 2;
    }
    
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size()-1;
        
        while(left<right){
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};