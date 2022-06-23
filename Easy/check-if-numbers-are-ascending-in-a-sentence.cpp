// brute force tc : O(n) sc : O(n)
class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream var(s);
        string temp;
        int x = 0;
        
        vector<int> arr;
        while(var>>temp){
            stringstream geek(temp);
            geek>>x; // convert string to int
            if(x!=0){
                arr.push_back(x);
            }
        }
        
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i-1]>=arr[i]){
                return false;
            }
        }
        return true;
    }
};

// brute force tc : O(n) sc : O(n)
class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream ss(s);
        string word;
        int prev = -1;
        
        while(ss>>word){
            if(isdigit(word[0])){
                int n = stoi(word);
                if(n<=prev){
                    return false;
                }
                prev = n;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        vector<int> arr;
        
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                string temp = "";
                while(i<n && isdigit(s[i])){
                    temp.push_back(s[i]);
                    i++;
                }
                arr.push_back(stoi(temp));
            }
        }
        
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>=arr[i]){
                return false;
            }
        }
        return true;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        int curr = 0;
        for(auto ch : s){
            if(isdigit(ch)){
                curr = curr*10+(ch-48);
            }
            else if(curr!=0){
                if(prev>=curr) return false;
                prev = curr;
                curr = 0;
            }
        }
        return prev<curr || curr==0;
    }
};