class Solution {
private:
    vector<string> split(string s,char ch){
        istringstream var(s);
        vector<string> arr;
        string temp;
        while(getline(var,temp,ch)){
            arr.push_back(temp);
        }
        return arr;
    }
    
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> arr = split(text,' ');
        unordered_set<char> ss(brokenLetters.begin(),brokenLetters.end());
        int cnt = 0;
        
        for(string s : arr){
            bool char_present = false;
            for(char ch : s){
                if(ss.find(ch)!=ss.end()){
                    char_present = true;
                    break;
                }
            }
            if(char_present==false){
                cnt++;
            }
        }
        return cnt;
    }
};