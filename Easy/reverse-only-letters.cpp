// tc : O(n) sc : O(n)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        string temp = "";
        for(int i=0;i<n;i++){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                temp.push_back(s[i]);   
            }
        }
        
        for(int i=0;i<n;i++){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                s[i] = temp.back();
                temp.pop_back();
            }
        }
        return s;
    }
};

// using stack
// tc : O(n) sc : O(n)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                st.push(s[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};

// two pointer
// if both are alpha then swap
// tc : O(n) sc : O(1)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        for(int i=0,j=n-1;i<j;){
            if(not isalpha(s[i]))
                i++;
            else if(not isalpha(s[j]))
                j--;
            else
                swap(s[i++],s[j--]);
        }
        return s;
    }
};

// if both are alpha then swap
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        
        while(left<right){
            if(isalpha(s[left]) && isalpha(s[right]))
                swap(s[left++],s[right--]);
            else if(not isalpha(s[left]))
                left++;
            else if(not isalpha(s[right]))
                right--;
        }
        return s;
    }
};