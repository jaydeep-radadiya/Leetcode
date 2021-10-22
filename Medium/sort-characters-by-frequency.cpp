class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> ump;
        for(int i=0;i<s.size();i++)
            ump[s[i]]++;
        
        priority_queue<pair<int,char>> maxh;
        for(auto it=ump.begin();it!=ump.end();it++)
            maxh.push({it->second,it->first});
        
        string ans = "";
        while(not maxh.empty()){
            char ch = maxh.top().second;
            int freq = maxh.top().first;
            
            while(freq--){
                ans.push_back(ch);
            }
            maxh.pop();
        }
        return ans;
    }
};