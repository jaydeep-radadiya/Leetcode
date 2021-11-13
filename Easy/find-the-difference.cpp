class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> ump;
        for(int i=0;i<s.size();i++)
            ump[s[i]]++;
        
        for(int i=0;i<t.size();i++){
            if(ump.find(t[i])==ump.end())
                return t[i];
            ump[t[i]]--;
            if(ump[t[i]]==0){
                ump.erase(t[i]);
            }
        }
        return -1;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> arr(26,0);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        
        for(int i=0;i<t.size();i++){
            arr[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return i+97;
            }
        }
        return -1;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int val = 0;
        for(int i=0;i<s.size();i++){
            val = val^s[i];
        }
        
        for(int i=0;i<t.size();i++){
            val = val^t[i];
        }
        return val;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int val1 = 0;
        for(int i=0;i<s.size();i++){
            val1 = val1+s[i];
        }
        
        int val2 = 0;
        for(int i=0;i<t.size();i++){
            val2 = val2+t[i];
        }
        return (char)(val2-val1);
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                return t[i];
            }
        }
        return t[t.size()-1];
    }
};