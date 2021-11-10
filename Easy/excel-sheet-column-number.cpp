class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char,int> ump;
        
        for(int i=65;i<=90;i++){
            ump[i] = i-64;
        }
        
        int val = 0;
        for(int i=0;i<columnTitle.size();i++){
            val = val*26+ump[columnTitle[i]];
        }
        return val;
    }
};

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int val = 0;
        for(int i=0;i<columnTitle.size();i++){
            val = val*26+(columnTitle[i]-64);
        }
        return val;
    }
};