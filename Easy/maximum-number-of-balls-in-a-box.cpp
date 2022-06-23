class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n>0){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> ump;
        for(int i=lowLimit;i<=highLimit;i++){
            int digit_sum = digitSum(i);
            ump[digit_sum]++;
        }
        
        int mx = 0;
        for(auto &t : ump){
            mx = max(mx,t.second);
        }
        return mx;
    }
};

// we also make array instead of map
// in that case array size is 46
// max upper limit is 99999 -> 45