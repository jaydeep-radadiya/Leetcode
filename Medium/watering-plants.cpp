class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cnt = 0;
        int cap = capacity;
        for(int i=-1;i<n-1;i++){
            if(plants[i+1]>cap){
                cnt += 2*(i+1)+1;
                cap = capacity;
            }
            else{
                cnt++;
            }
            cap -= plants[i+1];
        }
        return cnt;
    }
};

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cap = capacity;
        int steps = 0;
        
        for(int i=0;i<n;i++){
            if(plants[i]>cap){
                cap = capacity; // refill
                steps += (2*i+1);
            }
            else{
                steps++;
            }
            cap -= plants[i];
        }
        return steps;
    }
};