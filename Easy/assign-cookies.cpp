class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n1 = g.size();
        int n2 = s.size();
        
        int cnt = 0;
        for(int i=0,j=0;i<n1 && j<n2;){
            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }
            else if(g[i]>s[j]){
                j++;
            }
        }
        return cnt;
    }
};