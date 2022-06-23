// for both approach tc : O(n)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long cnt = n;
        
        long long temp = 0;
        for(int i=0;i<n-1;i++){
            if(prices[i]-prices[i+1]==1){
                temp++;
            }
            else{
                cnt += (temp*(temp+1))/2;
                temp = 0;
            }
        }
        cnt += (temp*(temp+1))/2;
        return cnt;
    }
};

// striver solution
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long cnt = 0;
        int i = 0;
        
        while(i<n){
            long long len = 1;
            while(i+1<n && prices[i]-prices[i+1]==1){
                len++;
                i++;
            }
            cnt += len*(len+1)/2;
            i++;
        }
        return cnt;
    }
};