// first solution
class comp {
public:
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        if(p1.first<p2.first){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++)
            ump[nums[i]]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> minh;
        for(auto it : ump){
            minh.push({it.second,it.first});
        }

        while(minh.size()>0){
            int freq = minh.top().first;
            int val = minh.top().second;
            minh.pop();
            while(freq--){
                ans.push_back(val);
            }
        }
        return ans;
    }
};

// second solution
class Solution {
public:
    static bool comp(vector<int> v1,vector<int> v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }
        if(v1[0]<v2[0]){
            return true;
        }
        return false;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        
        vector<vector<int>> arr;
        for(auto it : ump){
            arr.push_back({it.second,it.first});
        }
        
        sort(arr.begin(),arr.end(),comp);
        for(int i=0;i<arr.size();i++){
            int freq = arr[i][0];
            int val = arr[i][1];
            while(freq--){
                ans.push_back(val);
            }
        }
        return ans;
    }
};

// third solution
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        
        sort(nums.begin(),nums.end(),[&](int a,int b){
           return ump[a]==ump[b]?a>b:ump[a]<ump[b]; 
        });
        return nums;
    }
};