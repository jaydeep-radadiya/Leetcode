class Solution {
private:
    vector<string> split(string s){
        vector<string> arr;
        istringstream var(s);
        string temp;
        while(getline(var,temp,' ')){
            arr.push_back(temp);
        }
        return arr;
    }
    
public:
    bool wordPattern(string p, string s) {
        vector<string> arr = split(s);
        unordered_set<char> s1;
        unordered_set<string> s2;
        unordered_map<char,string> ump;
        
        if(p.size()!=arr.size()) return false;
        int pn = p.size();
        for(int i=0;i<pn;i++){
            s1.insert(p[i]);
            s2.insert(arr[i]);
            
            if(ump.find(p[i])==ump.end())
                ump[p[i]] = arr[i];
            else if(ump[p[i]]==arr[i])
                continue;
            else
                return false;
        }
        
        if(s1.size()==s2.size()) return true;
        return false;
    }
};

// second method
class Solution {
private:
    vector<string> split(string s){
        vector<string> arr;
        istringstream var(s);
        string temp;
        while(getline(var,temp,' ')){
            arr.push_back(temp);
        }
        return arr;
    }
    
public:
    bool wordPattern(string p, string s) {
        vector<string> arr = split(s);
        map<char,string> mp;
        map<string,bool> used;
        if(p.size()!=arr.size()) return false;
        
        for(int i=0;i<p.size();i++){
            if(mp.find(p[i])==mp.end()){ // char is unused
                if(used.find(arr[i])==used.end()){ // string is unused
                    mp[p[i]] = arr[i];
                    used[arr[i]] = true;
                }
                else{ // string is used
                    return false;
                }
            }
            else{ // char is used
                if(mp[p[i]]==arr[i]) continue;
                else return false;
            }
        }
        return true;
    }
};