// cs : O(k)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> maxh;
        
        int n = points.size();
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            maxh.push({x*x+y*y,{x,y}});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        
        while(maxh.size()>0){
            int x = maxh.top().second.first;
            int y = maxh.top().second.second;
            ans.push_back({x,y});
            maxh.pop();
        }
        return ans;
    }
};