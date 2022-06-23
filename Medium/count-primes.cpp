class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
        prime[0] = prime[1] = false;
        
        for(long long i=2;i<=n;i++){
            if(prime[i]==true){
                for(long long j=i*i;j<=n;j+=i){
                    prime[j] = false;
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(prime[i]==true){
                cnt++;
            }   
        }
        return cnt;
    }
};