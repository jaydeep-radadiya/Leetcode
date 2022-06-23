class Solution {
public:
    int mostWordsFound(vector<string>& arr) {
        int n = arr.size();
        int mx_words = INT_MIN;
        
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==' '){
                    cnt++;
                }
            }
            mx_words = max(mx_words,cnt+1);
        }
        return mx_words;
    }
};

// same as above
class Solution {
public:
    int mostWordsFound(vector<string>& arr) {
        int n = arr.size();
        int mx_words = INT_MIN;
        
        for(string s : arr){
            int cnt = count(s.begin(),s.end(),' ')+1;
            mx_words = max(mx_words,cnt);
        }
        return mx_words;
    }
};