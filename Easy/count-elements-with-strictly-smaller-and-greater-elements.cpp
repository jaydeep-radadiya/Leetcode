class Solution {
private:
    bool findMin(vector<int> &arr,int val){
        for(int ele : arr){
            if(ele<val) return true;
        }
        return false;
    }
    
    bool findMax(vector<int> &arr,int val){
        for(int ele : arr){
            if(ele>val) return true;
        }
        return false;
    }
    
public:
    int countElements(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(findMin(arr,arr[i]) && findMax(arr,arr[i])){
                cnt++;
            }
        }
        return cnt;
    }
};

// small solution
class Solution {
public:
    int countElements(vector<int>& arr) {
        int n = arr.size();
        int mn = arr[0];
        int mx = arr[0];
        for(int ele : arr){
            if(ele>mx) mx = ele;
            else if(ele<mn) mn = ele;
        }
        
        int cnt = 0;
        for(int ele : arr){
            if(ele>mn && ele<mx) cnt++;
        }
        return cnt;
    }
};