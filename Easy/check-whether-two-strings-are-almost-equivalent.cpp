// brute force
class Solution {
public:
    bool checkAlmostEquivalent(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        for(int i=97;i<=122;i++){
            int c1 = 0;
            for(char ele : s1){
                if(ele==i){
                    c1++;
                }
            }
            
            int c2 = 0;
            for(char ele : s2){
                if(ele==i){
                    c2++;
                }
            }
            
            if(abs(c1-c2)>3){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkAlmostEquivalent(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<int> arr(26);
        for(int i=0;i<n1;i++)
            arr[s1[i]-'a']++;
        for(int i=0;i<n2;i++)
            arr[s2[i]-'a']--;
        
        for(int i=0;i<26;i++){
            if(abs(arr[i])>3){
                return false;
            }
        }
        return true;
    }
};