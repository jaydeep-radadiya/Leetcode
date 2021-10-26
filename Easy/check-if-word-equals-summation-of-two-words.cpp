class Solution {
public:
    int ascii(string s){
        int ans = 0;
        for(int i=0;i<s.size();i++){
            ans = ans*10+((int)s[i]-97);
        }
        return ans;
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int v1 = ascii(firstWord);
        int v2 = ascii(secondWord);
        int v3 = ascii(targetWord);
        
        if(v1+v2==v3)
            return true;
        else
            return false;
    }
};