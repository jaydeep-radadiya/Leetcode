class Solution {
public:
    int numberOfMatches(int n) {
        if(n==1) return 0;
        if(n%2==0) return (n/2)+numberOfMatches(n/2);
        else return (n/2)+numberOfMatches(n/2+1);
    }
};

// it takes one match to eliminate one player
class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};

// tc : O(logn)
class Solution {
public:
    int numberOfMatches(int n) {
        int match = 0;
        
        while(n!=1){
            if(n%2==0){
                match += n/2;
                n = n/2;
            }
            else{
                match += (n-1)/2;
                n = 1+(n-1)/2;
            }
        }
        return match;
    }
};