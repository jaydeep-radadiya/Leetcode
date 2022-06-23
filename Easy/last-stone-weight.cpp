// similar to connect ropes to minimise cost
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> maxh;
        
        for(int i=0;i<n;i++){
            maxh.push(stones[i]);
        }
        
        while(maxh.size()>=2){
            int first = maxh.top();
            maxh.pop();
            int second = maxh.top();
            maxh.pop();
            if(first!=second){
                maxh.push(first-second);
            }
        }
        
        if(maxh.size()==0)
            return 0;
        else
            return maxh.top();
    }
};