class Solution {
public:
    int addDigits(int num) {
        if(num/10==0) return num;
        
        int sum = 0;
        while(num>0){
            sum += num%10;
            num = num/10;
            if(num==0 && sum/10==0){
                return sum;
            }
            if(num==0){ // sum is >= 10
                num = sum;
                sum = 0;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int addDigits(int n) {
        while(true){
            int sum = 0;
            while(n>0){
                sum += n%10;
                n = n/10;
            }
            if(n==0 and sum/10==0)
                return sum;
            else if(n==0 and sum/10>=1)
                n = sum;
        }
        return  -1;
    }
};

class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        if(num%9==0) return 9;
        return num%9;
    }
};