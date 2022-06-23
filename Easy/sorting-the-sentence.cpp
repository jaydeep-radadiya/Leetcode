class Solution {
public:
    string sortSentence(string s) {
        vector<string> vec(10);
        istringstream var(s);
        string temp;
        
        while(var>>temp){
            vec[temp[temp.size()-1]-48] = temp;
        }

        string ans = "";
        for(int i=1;i<10;i++){
            if(vec[i]!=""){
                ans.append(vec[i]);
                ans.pop_back(); // remove last digit
                ans.push_back(' ');
            }
        }
        ans.pop_back();
        return ans;
    }
};