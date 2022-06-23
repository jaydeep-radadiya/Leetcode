// first
class Solution {
public:
    string interpret(string s) {
        int n = s.size();
        string ans = "";
        
        for(int i=0;i<n;){
            if(s[i]=='G'){
                ans.push_back('G');
                i += 1;
            }
            else if(i+1<n && s[i+1]==')'){
                ans.push_back('o');
                i += 2;
            }
            else if(i+3<n && s[i+3]==')'){
                ans.push_back('a');
                ans.push_back('l');
                i += 4;
            }
        }
        return ans;
    }
};

// second
class Solution {
public:
    string interpret(string s) {
        string ans = "";
        int n = s.size();
        
        for(int i=0;i<n;){
            if(s[i]=='('){
                if(s[i+1]==')'){
                    ans.push_back('o');
                    i += 2;
                }
                else{
                    ans += "al";
                    i += 4;
                }
            }
            else{
                ans.push_back('G');
                i += 1;
            }
        }
        return ans;
    }
};

// third
class Solution {
public:
    string interpret(string str) {
        unordered_map<string,string> ump = {{"G", "G"},{"()", "o"},{"(al)", "al"}};
        
        string ans = "";
        string temp = "";
        for(char &c : str){
            temp += c;
            if(ump.find(temp)!=ump.end()){
                ans += ump[temp];
                temp = "";
            }
        }
        return ans;
    }
};