class Solution {
public:
    int countConsistentStrings(string s, vector<string>& arr) {
        int n = arr.size();
        unordered_set<char> ss(s.begin(),s.end());
        int ans = 0;
        
        for(string &t : arr){
            int cnt = 0;
            for(char c : t){
                if(ss.find(c)!=ss.end())
                    cnt++;
                else
                    break;
            }
            if(cnt==t.size()) ans++;
        }
        return ans;
    }
};