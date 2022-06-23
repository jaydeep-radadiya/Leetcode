// brute force tle
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double mxavg = INT_MIN;
        
        for(int i=0;i<=n-k;i++){
            double avg = 0;
            for(int j=i;j<i+k;j++){
                avg += nums[j];
            }
            mxavg = max(mxavg,avg/k);
        }
        return mxavg;
    }
};

// accepted sliding window technique
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double mxavg = INT_MIN;
        double sum = 0;
        int i = 0;
        int j = 0;
        
        while(j<n){
            sum += nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                mxavg = max(mxavg,sum/k);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return mxavg;
    }
};