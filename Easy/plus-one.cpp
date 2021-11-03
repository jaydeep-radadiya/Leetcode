// first method
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};

// second method
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        
        int c = 1;
        for(int i=digits.size()-1;i>=0;i--){
            int n = digits[i]+c;
            c = n/10;
            ans.push_back(n%10);
        }
        
        if(c!=0)
            ans.push_back(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};