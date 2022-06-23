class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n1 = a.size()-1;
        int n2 = b.size()-1;
        
        int c = 0;
        while(n1>=0 || n2>=0){
            int sum = c;
            if(n1>=0){
                sum += (a[n1]-'0');
                n1--;
            }
            if(n2>=0){
                sum += (b[n2]-'0');
                n2--;
            }
            ans.push_back((sum%2)+'0');
            c = sum/2;
        }
        if(c>0){
            ans.push_back(c+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};