class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return false;
        for(int i=2;i<n;i++){
            if(arr[i-2]&1 and arr[i-1]&1 and arr[i]&1){
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int odd = 0;
        for(int i=0;i<n && odd<3;i++){
            if(arr[i]%2==1)
                odd++;
            else
                odd = 0;
        }
        return odd==3;
    }
};