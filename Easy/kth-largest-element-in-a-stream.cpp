// bruteforce  TLE
class KthLargest {
private:
    vector<int> arr;
    int kth;
    
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        arr = nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.begin(),arr.end());
        return arr[arr.size()-kth];
    }
};

// accepted
class KthLargest {
private:
    multiset<int> ss;
    int kth;
    
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int ele : nums){
            ss.insert(ele);
        }
    }
    
    int add(int val) {
        ss.insert(val);
        int i = 1;
        for(auto it=ss.rbegin();it!=ss.rend();it++){
            if(i==kth) return *it;
            i++;
        }
        return -1;
    }
};