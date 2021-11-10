// iterative solution
class Solution {
public:
    bool isPalindrome(string s,int left,int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return isPalindrome(s,left+1,right) or isPalindrome(s,left,right-1);
            }
        }
        return -1;
    }
};

// recursive solution
class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s,0,s.size()-1,1);
    }
    
    // noc : # character you can delete at most
    bool valid(string &s,int left,int right,int noc){
        if(left>=right) return true;
        
        if(s[left]==s[right])
            return valid(s,left+1,right-1,noc);
        else
            return noc>0 && (valid(s,left+1,right,noc-1) || valid(s,left,right-1,noc-1)); 
    }
};