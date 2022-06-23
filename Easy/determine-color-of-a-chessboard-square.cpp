class Solution {
public:
    bool squareIsWhite(string s) {
        int c1 = s[0]-'a'+1;
        int c2 = s[1]-'0';
        if(c1%2==c2%2) return false;
        else return true;
    }
};