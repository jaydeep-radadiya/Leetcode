// similar to connect ropes to minimise cost
class Solution {
public:
    int minimumCost(vector<int>& arr) {
        int n = arr.size();
		priority_queue<int> maxh(arr.begin(),arr.end());
        
        int price = 0;
        while(maxh.size()>=2){
            int p1 = maxh.top();
            maxh.pop();
            int p2 = maxh.top();
            maxh.pop();
            if((not maxh.empty()) && maxh.top()<=min(p1,p2)){
                maxh.pop();
            }
            price += (p1+p2);
        }
        if(not maxh.empty()) price += maxh.top();
        return price;
    }
};