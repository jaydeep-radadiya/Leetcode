// brute force tc : O(n^2) sc : O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        
        for(int i=0;i<n;i++){
            bool found = false;
            for(int j=0;j<n;j++){
                if(s[i]==s[j] && i!=j){
                    found = true;
                    break;
                }
            }
            if(found==false){
                return i;
            }
        }
        return -1;
    }
};

// tc : O(n) sc : O(26)
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char,int> ump;
        for(int i=0;i<n;i++)
            ump[s[i]]++;
        
        for(int i=0;i<n;i++){
            if(ump[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};