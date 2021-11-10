class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        unordered_map<char,int> ump;
        for(int i=0;i<s.size();i++){
            ump[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(ump.find(t[i])==ump.end()){
                return false;   
            }
            else{
                ump[t[i]]--;
                if(ump[t[i]]==0){
                    ump.erase(t[i]);
                }
            }
        }
        
        if(ump.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        int n = s.size();
        vector<int> count(26,0);
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;
    }
};