// tc : (n) sc : O(n)
class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        vector<int> arr(n,0);
        
        for(int i=0;i<n;i++){
            if(s[i]=='R') arr[i] = 1;
            else arr[i] = -1;
        }
        
        for(int i=1;i<n;i++){
            arr[i] = arr[i]+arr[i-1];
        }
        
        int cnt = 0;
        for(int &ele : arr){
            if(ele==0){
                cnt++;
            }
        }
        return cnt;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int cnt = 0;
        
        int sum = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='R') sum++;
            else sum--;
            if(sum==0){
                cnt++;
            }
        }
        return cnt;
    }
};