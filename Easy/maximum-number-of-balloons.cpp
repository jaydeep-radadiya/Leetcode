class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> ump;
        int n = text.size();
        for(int i=0;i<n;i++)
            ump[text[i]]++;
        
        ump['l'] = ump['l']/2;
        ump['o'] = ump['o']/2;
        
        int ans = INT_MAX;
        string balloon = "balloon";
        for(char ch : balloon){
            ans = min(ans,ump[ch]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b, a, l, o, n;
        b = a = l = o = n = 0;
        
        for(char ch : text){
            if(ch=='b') b++;
            else if(ch=='a') a++;
            else if(ch=='l') l++;
            else if(ch=='o') o++;
            else if(ch=='n') n++;
        }
        return min({b,a,l/2,o/2,n});
    }
};