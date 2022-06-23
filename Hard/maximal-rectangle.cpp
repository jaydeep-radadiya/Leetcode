// tc : O(r*c)
class Solution {
public:
    vector<int> findNSL(vector<int> &arr,int n){
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++){
            if(st.size()==0) ans.push_back(-1);
            else if(st.size()>0 && st.top().first<arr[i])
                ans.push_back(st.top().second);
            else if(st.size()>0 && st.top().first>=arr[i]){
                while(st.size()>0 && st.top().first>=arr[i])
                    st.pop();
                if(st.size()==0)
                    ans.push_back(-1);
                else
                    ans.push_back(st.top().second);
            }
            st.push({arr[i],i});
        }
        return ans;
    }
    
    vector<int> findNSR(vector<int> &arr,int n){
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=n-1;i>=0;i--){
            if(st.size()==0) ans.push_back(n);
            else if(st.size()>0 && st.top().first<arr[i])
                ans.push_back(st.top().second);
            else if(st.size()>0 && st.top().first>=arr[i]){
                while(st.size()>0 && st.top().first>=arr[i])
                    st.pop();
                if(st.size()==0)
                    ans.push_back(n);
                else
                    ans.push_back(st.top().second);
            }
            st.push({arr[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    // maximum area of histogram
    int mah(vector<int> &arr,int n){
        vector<int> left = findNSL(arr,n);
        vector<int> right = findNSR(arr,n);
        
        vector<int> width(n);
        for(int i=0;i<n;i++)
            width[i] = right[i]-left[i]-1;
        
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,width[i]*arr[i]);
        }
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r==0) return 0;
        int c = matrix[0].size();
        
        vector<int> arr(c);
        for(int j=0;j<c;j++)
            arr[j] = (matrix[0][j]-'0');
        int mx_area = mah(arr,c);
        
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1')
                    arr[j] += 1;
                else
                    arr[j] = 0;
            }
            mx_area = max(mx_area,mah(arr,c));
        }
        return mx_area;
    }
};