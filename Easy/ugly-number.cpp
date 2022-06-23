class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        vector<int> pfactors;
        while(n%2==0){
            n /= 2;
            if(pfactors.size()==0 || pfactors.back()!=2){
                pfactors.push_back(2);
            }
        }
        
        for(int i=3;i<=sqrt(n);i+=2){
            while(n%i==0){
                if(pfactors.size()==0 || pfactors.back()!=i){
                    pfactors.push_back(i);   
                }
                n = n/i;
            }
        }
        if(n!=1) pfactors.push_back(n);
        
        for(int i=0;i<pfactors.size();i++){
            if(pfactors[i]==2 or pfactors[i]==3 or pfactors[i]==5)
                continue;
            else
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        for(int i=2;i<6;i++){
            while(n%i==0){
                n = n/i;
            }
        }
        return n==1;
    }
};