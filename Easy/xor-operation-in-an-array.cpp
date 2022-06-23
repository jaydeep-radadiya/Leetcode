class Solution {
public:
    int xorOperation(int n, int start) {
        int val = 0;
        for(int i=0;i<n;i++){
            val = val^(start+2*i);
        }
        return val;
    }
};