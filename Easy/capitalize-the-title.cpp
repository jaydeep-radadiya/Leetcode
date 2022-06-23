class Solution {
public:
    string capitalizeTitle(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        
        istringstream var(s);
        string temp, ans = "";
        while(getline(var,temp,' ')){
            if(temp.size()>2){
                temp[0] = temp[0]-32;   
            }
            ans.append(temp);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};