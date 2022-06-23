class Solution {
private:
    bool check(vector<int> &freq1,int n){
        vector<int> freq2(10);
        while(n>0){
            freq2[n%10]++;
            n = n/10;
        }
        for(int i=0;i<=9;i++){
            if(freq2[i] && freq2[i]>freq1[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> freq1(10);
        for(auto &t : digits)
            freq1[t]++;
        
        // for even numbers
        for(int i=100;i<=998;i+=2){
            if(check(freq1,i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> freq(10);
        for(int &t : digits)
            freq[t]++;
        
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9 && freq[i];j++){
                for(int k=0;k<=8 && freq[j]>(i==j);k+=2){
                    if(freq[k]>(j==k)+(i==k)){
                        ans.push_back(100*i+10*j+k);   
                    }
                }
            }
        }
        return ans;
    }
};