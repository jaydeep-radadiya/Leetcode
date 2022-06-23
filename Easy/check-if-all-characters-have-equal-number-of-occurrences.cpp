class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.size();
        unordered_map<char,int> ump;
        for(int i=0;i<n;i++)
            ump[s[i]]++;
        
        int cnt = ump[s[0]];
        for(auto t : ump){
            if(t.second!=cnt){
                return false;
            }
        }
        return true;
    }
};