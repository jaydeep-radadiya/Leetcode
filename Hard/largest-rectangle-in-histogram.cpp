class Solution {
public:
    vector<int> findNSL(vector<int> &heights,int n){
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++){
            if(st.size()==0) ans.push_back(-1);
            else if(st.size()>0 && st.top().first<heights[i])
                ans.push_back(st.top().second);
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i])
                    st.pop();
                if(st.size()==0)
                    ans.push_back(-1);
                else
                    ans.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        return ans;
    }
    
    vector<int> findNSR(vector<int> &heights,int n){
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=n-1;i>=0;i--){
            if(st.size()==0) ans.push_back(n);
            else if(st.size()>0 && st.top().first<heights[i])
                ans.push_back(st.top().second);
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i])
                    st.pop();
                if(st.size()==0)
                    ans.push_back(n);
                else
                    ans.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = findNSL(heights,n);
        vector<int> right = findNSR(heights,n);
        
        vector<int> width;
        for(int i=0;i<n;i++)
            width.push_back(right[i]-left[i]-1);
        
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,width[i]*heights[i]);
        }
        return mx;
    }
};