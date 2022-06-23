// brute force
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> ump1;
        int n1 = words1.size();
        for(int i=0;i<n1;i++)
            ump1[words1[i]]++;
        
        unordered_map<string,int> ump2;
        int n2 = words2.size();
        for(int i=0;i<n2;i++)
            ump2[words2[i]]++;
        
        int cnt = 0;
        for(auto &t : ump1){
            if(t.second==1 && ump2[t.first]==1){
                cnt++;
            }
        }
        return cnt;
    }
};

// optimised
// only one map
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> ump;
        for(auto &t : words1)
            ump[t]++;
        for(auto &t : words2){
            if(ump[t]<=1){
                ump[t]--;   
            }
        }
        
        int cnt = 0;
        for(auto &t : ump){
            if(t.second==0) cnt++;
        }
        return cnt;
    }
};