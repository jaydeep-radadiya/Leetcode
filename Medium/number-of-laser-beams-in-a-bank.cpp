class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            int one = count(bank[i].begin(),bank[i].end(),'1');
            if(one!=0){
                arr.push_back(one);   
            }
        }
        
        int total = 0;
        for(int i=1;i<arr.size();i++){
            total += arr[i]*arr[i-1];
        }
        return total;
    }
};