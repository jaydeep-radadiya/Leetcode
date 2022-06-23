// tc : O(n) sc : O(n)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,pair<int,int>> ump;
        
        int n1 = list1.size();
        for(int i=0;i<n1;i++){
            ump[list1[i]].first = 1;
            ump[list1[i]].second = i;   
        }
        
        int n2 = list2.size();
        for(int i=0;i<n2;i++){
            ump[list2[i]].first += 1;
            ump[list2[i]].second += i;   
        }
        
        int mn = INT_MAX;
        for(auto &t : ump){
            if(t.second.first==2){
                mn = min(mn,t.second.second);
            }
        }
        
        vector<string> ans;
        for(auto &t : ump){
            if(t.second.first==2 && t.second.second==mn){
                ans.push_back(t.first);
            }
        }
        return ans;
    }
};