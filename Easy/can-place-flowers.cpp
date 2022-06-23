// with extra space
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size();
        vector<int> arr(n+2,0);
        for(int i=0;i<n;i++){
            arr[i+1] = flowerbed[i];
        }
        
        for(int i=1;i<=n;i++){
            if(arr[i]==0 && arr[i-1]==0 && arr[i+1]==0){
                arr[i] = 1;
                k--;
            }
        }
        if(k<=0) return true;
        else return false;
    }
};

// with out extra space
class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            int prev = (i==0)?0:arr[i-1];
            int next = (i==n-1)?0:arr[i+1];
            if(arr[i]==0 && prev==0 && next==0){
                arr[i] = 1;
                k--;
            }
        }
        
        if(k<=0) return true;
        else return false;
    }
};

// striver solution
class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int k) {
        int n = arr.size();
        if(k==0) return true;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0 && (i==0 || arr[i-1]==0) && (i==n-1 || arr[i+1]==0)){
                arr[i] = 1;
                k--;
            }
            if(k==0){
                return true;
            }
        }
        return false;
    }
};