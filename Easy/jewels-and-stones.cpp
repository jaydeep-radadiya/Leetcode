class Solution {
public:
    int numJewelsInStones(string p, string s) {
        unordered_set<char> ss(p.begin(),p.end());
        int cnt = 0;
        for(char c1 : ss){
            for(char c2 : s){
                if(c1==c2) cnt++;
            }
        }
        return cnt;
    }
};

// p is unique so no need to make set
class Solution {
public:
    int numJewelsInStones(string p, string s) {
        int cnt = 0;
        for(char c1 : p){
            for(char c2 : s){
                if(c1==c2) cnt++;
            }
        }
        return cnt;
    }
};