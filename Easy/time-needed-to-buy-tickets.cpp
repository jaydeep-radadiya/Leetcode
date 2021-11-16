// Brute Force Solution
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sec = 0;
        int i = 0;
        
        while(true){
            if(tickets[i]>0){
                tickets[i]--;
                sec++;
            }
            if(tickets[i]==0 and i==k){
                return sec;
            }

            // maintain index
            if(i==tickets.size()-1){
                i = 0;
            }
            else{
                i++;
            }
        }
        return sec;
    }
};

// One Pass Solution
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sec = 0;
        for(int i=0;i<tickets.size();i++){
            if(i<=k)
                sec += min(tickets[i],tickets[k]);
            else
                sec += min(tickets[i],tickets[k]-1);
        }
        return sec;
    }
};