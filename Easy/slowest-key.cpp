// tc : O(n) sc : O(1)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int mx = releaseTimes[0];
        char ans = keysPressed[0];
        
        for(int i=1;i<keysPressed.size();i++){
            int diff = releaseTimes[i]-releaseTimes[i-1];
            if(diff>mx){
                mx = diff;
                ans = keysPressed[i];
            }
            else if(diff==mx){
                ans = max(ans,keysPressed[i]);
            }
        }
        return ans;
    }
};