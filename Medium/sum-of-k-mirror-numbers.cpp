// brute force tle
class Solution {
private:
    string to_base(long long n,int &k){
        string ans = "";
        while(n>0){
            ans += (char)((n%k)+'0'); // this line is interesting
            n = n/k;
        }
        return ans;
    }
    
private:
    bool isNumPalin(long long n){
        long long nc = n; // copy of n
        long long ans = 0;
        while(n>0){
            ans = ans*10+n%10;
            n = n/10;
        }
        return nc==ans;
    }
    
private:
    bool isStrPalin(string str){
        int left = 0;
        int right = str.size()-1;
        while(left<right){
            if(str[left]!=str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        for(int i=1;n>0;i++){
            if(isNumPalin(i)){
                string str = to_base(i,k);
                if(isStrPalin(str)){
                    sum += i;
                    n--;
                }
            }
        }
        return sum;
    }
};

// algo to generate palindrome numbers
class Solution {
private:
    string to_base(long long n,int &k){
        string ans = "";
        while(n>0){
            ans += (char)((n%k)+'0'); // this line is interesting
            n = n/k;
        }
        return ans;
    }

// no need to this bcoz of generate palindrome numbers algo
private:
    bool isNumPalin(long long n){
        long long nc = n; // copy of n
        long long ans = 0;
        while(n>0){
            ans = ans*10+n%10;
            n = n/10;
        }
        return nc==ans;
    }
    
private:
    bool isStrPalin(string str){
        int left = 0;
        int right = str.size()-1;
        while(left<right){
            if(str[left]!=str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

private:
    long long generateNumber(long long num,bool odd){
        long long dupnum = num;
        if(odd){
            dupnum = dupnum/10;
        }
        while(dupnum>0){
            num = num*10+dupnum%10;
            dupnum = dupnum/10;
        }
        return num;
    }
    
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        
        for(int i=1;n>0;i=i*10){
            // generate odd length palindrome
            for(int j=i;n>0 && j<i*10;j++){
                long long num = generateNumber(j,true);
                string str = to_base(num,k);
                if(isStrPalin(str)){
                    sum += num;
                    n--;
                }
            }
            
            // generate even length palindrome
            for(int j=i;n>0 && j<i*10;j++){
                long long num = generateNumber(j,false);
                string str = to_base(num,k);
                if(isStrPalin(str)){
                    sum += num;
                    n--;
                }
            }
        }
        return sum;
    }
};