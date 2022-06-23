class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        for(int i=1;i<n;i++)
            gain[i] = gain[i]+gain[i-1];
        int val = *max_element(gain.begin(),gain.end());
        
        if(val<0) return 0;
        else return val;
    }
};

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int mx = gain[0];
        
        for(int i=1;i<n;i++){
            gain[i] = gain[i]+gain[i-1];
            mx = max(mx,gain[i]);
        }
        
        if(mx<0)
            return 0;
        else
            return mx;
    }
};

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int mx = gain[0];
        
        partial_sum(gain.begin(),gain.end(),gain.begin());
        for(int i=0;i<n;i++){
            mx = max(mx,gain[i]);
        }
        return mx<0?0:mx;
    }
};