// Detect Cycles with a HashSet
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> ss;
        while(n!=1 and ss.find(n)==ss.end()){
            ss.insert(n);
            n = help(n);
        }
        return n==1;
    }
    
    int help(int n){
        int ans = 0;
        while(n>0){
            int rem = n%10;
            ans += (rem*rem);
            n = n/10;
        }
        return ans;
    }
};

// Floyd's Cycle-Finding Algorithm
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = help(slow);
            fast = help(help(fast));
        } while(slow!=fast);
        return slow==1;
    }
    
    int help(int n){
        int ans = 0;
        while(n>0){
            int rem = n%10;
            ans += (rem*rem);
            n = n/10;
        }
        return ans;
    }
};