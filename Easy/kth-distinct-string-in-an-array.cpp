class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string,int> ump;
        for(string s : arr){
            ump[s]++;
        }
        
        int cnt = 1;
        for(int i=0;i<n;i++){
            if(ump[arr[i]]==1){
                if(cnt==k) return arr[i];
                else cnt++;
            }
        }
        return "";
    }
};

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string,int> ump;
        for(string s : arr){
            ump[s]++;
        }
        
        for(string s : arr){
            if(ump[s]==1 && --k==0){
                return s;
            }
        }
        return "";
    }
};