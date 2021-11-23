class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        if(n==1) return false;
        
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++)
            ump[deck[i]]++;
        
        int gcd = ump[deck[0]];
        for(auto temp : ump){
            gcd = __gcd(gcd,temp.second);
        }

        if(gcd>=2)
            return true;
        else
            return false;
    }
};

// more readable
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int res = 0;
        int n = deck.size();
        unordered_map<int,int> ump;
        for(int i : deck) ump[i]++;
        for(auto i : ump) res = __gcd(res,i.second);
        return res>=2;
    }
};