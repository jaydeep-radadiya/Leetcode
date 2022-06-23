class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> ump;
        
        for(int i=0;i<n;i++){
            ump[arr[i]]++;
        }
        
        vector<int> frequency;
        for(auto it : ump){
            frequency.push_back(it.second);
        }
        
        sort(frequency.begin(),frequency.end());
        n = frequency.size();
        for(int i=1;i<n;i++){
            if(frequency[i]==frequency[i-1]){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++)
            ump[arr[i]]++;
        unordered_set<int> ss;
        for(auto &t : ump) ss.insert(t.second);
        return ss.size()==ump.size();
    }
};

// little bit optimisation
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++)
            ump[arr[i]]++;
        
        unordered_set<int> ss;
        for(auto &t : ump){
            if(ss.insert(t.second).second==false){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        vector<int> vec(2001);
        for(int ele : arr)
            vec[ele+1000]++;
        
        sort(vec.begin(),vec.end());
        for(int i=1;i<2001;i++){
            if(vec[i] && vec[i]==vec[i-1]){
                return false;
            }
        }
        return true;
    }
};