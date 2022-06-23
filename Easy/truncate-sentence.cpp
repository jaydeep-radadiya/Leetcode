class Solution {
private:
    vector<string> split(string s,int k){
        vector<string> arr;
        istringstream var(s);
        string temp;
        while(getline(var,temp,' ')){
            arr.push_back(temp);
            if(arr.size()==k) return arr;
        }
        return arr;
    }
    
    string joinWithSpace(vector<string> &arr){
        string ans;
        for(string s : arr){
            ans.append(s + ' ');
        }
        ans.pop_back();
        return ans;
    }
    
public:
    string truncateSentence(string s, int k) {
        vector<string> arr = split(s,k);
        return joinWithSpace(arr);
    }
};

// simple & best approach
class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int cnt = 0;
        for(char c : s){
            if(c==' '){
                cnt++;
                if(cnt==k) return ans;
            }
            ans.push_back(c);
        }
        return ans;
    }
};