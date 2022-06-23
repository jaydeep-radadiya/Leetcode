// first
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> arr;
        
        int c = 0;
        for(int i=n-1;i>=0 || k>0;i--){
            int sum = c;
            if(i>=0)
                sum += num[i];
            if(k>0)
                sum += k%10;
            arr.push_back(sum%10);
            c = sum/10;
            k = k/10;
        }
        if(c!=0){
            arr.push_back(c);
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};

// second
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        for(int i=n-1;i>=0 && k>0;i--){
            num[i] += k;
            k = num[i]/10;
            num[i] = num[i]%10;
        }
        while(k>0){
            num.insert(num.begin(),k%10);
            k = k/10;
        }
        return num;
    }
};