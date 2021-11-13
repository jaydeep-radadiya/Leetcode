// similar to next greater element

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,-1);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(temperatures[j]>temperatures[i]){
                    ans[i] = j-i;
                    break;
                }
            }
            if(ans[i]==-1){
                ans[i] = 0;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans;
        stack<int> s;
        
        for(int i=n-1;i>=0;i--){
            if(s.size()==0)
                ans.push_back(0);
            else if(s.size()>0 and temperatures[s.top()]>temperatures[i])
                ans.push_back(s.top()-i);
            else if(s.size()>0 and temperatures[s.top()]<=temperatures[i]){
                while(s.size()>0 and temperatures[s.top()]<=temperatures[i])
                    s.pop();
                if(s.size()==0)
                    ans.push_back(0);
                else
                    ans.push_back(s.top()-i);
            }
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};