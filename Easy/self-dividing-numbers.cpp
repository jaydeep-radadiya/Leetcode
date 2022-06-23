// brute force
// tc : O((r-l)*logn)
class Solution {
public:
    bool issdn(int n){
        int val = n;
        
        while(n>0){
            int rem = n%10;
            if(rem==0 or val%rem!=0){
                return false;
            }
            n = n/10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for(int i=left;i<=right;i++){
            if(issdn(i)){
                ans.push_back(i);
            } 
        }
        return ans;
    }
};