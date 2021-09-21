class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        int n = sentence.size();
        for(int i=0;i<n;i++){
            s.insert(sentence[i]);
        }

        if(s.size()==26)
            return true;
        else
            return false;
    }
};