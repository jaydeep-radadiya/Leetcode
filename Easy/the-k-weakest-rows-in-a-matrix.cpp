class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> temp;
        
        int r = mat.size();
        int c = mat[0].size();
        for(int i=0;i<r;i++){
            int cnt = 0;
            for(int j=0;j<c;j++){
                if(mat[i][j]==1) cnt++;
                else break;
            }
            temp.push_back({cnt,i});
        }
        
        sort(temp.begin(),temp.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};

// using priority queue
// tc : O(r*c) sc : O(r)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> maxh;
        
        int r = mat.size();
        int c = mat[0].size();
        for(int i=0;i<r;i++){
            int cnt = 0;
            for(int j=0;j<c;j++){
                if(mat[i][j]==1) cnt++;
                else break;
            }
            maxh.push({cnt,i});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        
        vector<int> ans;
        while(maxh.size()>0){
            int idx = maxh.top().second;
            ans.push_back(idx);
            maxh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// tc : O(r*c) sc : O(r)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> count;
        for(int i=0;i<mat.size();i++){
            int cnt = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) cnt++;
                else break;
            }
            count.push_back(cnt*1000+i);
        }
        
        vector<int> ans;
        sort(count.begin(),count.end());
        for(int i=0;i<k;i++){
            ans.push_back(count[i]%1000);
        }
        return ans;
    }
};

// apply bs to find # one
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> maxh;
        
        int r = mat.size();
        int c = mat[0].size();
        for(int i=0;i<r;i++){
            int cnt = -1;
            int left = 0;
            int right = mat[0].size()-1;
            while(left<=right){
                int mid = left+(right-left)/2;
                if(mat[i][mid]==1){
                    cnt = mid;
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            maxh.push({cnt+1,i});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        
        vector<int> ans;
        while(maxh.size()>0){
            int idx = maxh.top().second;
            ans.push_back(idx);
            maxh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// using lower bound in descending array
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> maxh;
        
        int r = mat.size();
        int c = mat[0].size();
        for(int i=0;i<r;i++){
            int cnt = lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>())-mat[i].begin();
            cout<<cnt<<" ";
            maxh.push({cnt,i});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        
        vector<int> ans;
        while(maxh.size()>0){
            int idx = maxh.top().second;
            ans.push_back(idx);
            maxh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// using set
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> ss;
        for(int i=0;i<mat.size();i++){
            int cnt = accumulate(mat[i].begin(),mat[i].end(),0);
            ss.insert({cnt,i});
        }
        
        // vector<int> ans;
        // auto end = ss.begin();
        // advance(end,k);
        // for(auto it=ss.begin();it!=end;it++){
        //     ans.push_back(it->second);
        // }
        // return ans;

        vector<int> ans;
        for(auto it=ss.begin();k>0;it++,k--){
            ans.push_back(it->second);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int c = mat[0].size();
        // append the index at the end
        for(int i=0; i<mat.size(); i++){
            mat[i].push_back(i);
        }
        
        sort(mat.begin(),mat.end());
        vector<int> ans(k);
        for(int i=0; i<k; i++){
            ans[i]=mat[i][c];            
        }
        return ans;
    }
};