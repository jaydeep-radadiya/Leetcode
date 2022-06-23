class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        
        long long earth = mass;
        for(int i=0;i<n;i++){
            if(asteroids[i]>earth){
                return false;
            }
            earth += asteroids[i];
        }
        return true;
    }
};