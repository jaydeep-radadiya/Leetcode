class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        
        int c = 0;
        while(n1>=0 || n2>=0){
            int sum = c;
            if(n1>=0){
                sum += (num1[n1]-'0');
                n1--;
            }
            if(n2>=0){
                sum += (num2[n2]-'0');
                n2--;
            }
            ans.push_back(sum%10+'0');
            c = sum/10;
        }
        if(c>0){
            ans.push_back(c+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};