class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==')' or s[i]==']' or s[i]=='}'){
                if(not st.empty()){ // stack is not empty
                    char temp = st.top();
                    if((temp=='(' and s[i]==')') or (temp=='[' and s[i]==']') or (temp=='{' and s[i]=='}')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{ // stack is empty
                    return false;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

// java solution
public boolean isValid(String s) {
    Stack<Character> stack = new Stack<Character>();
    for (char c : s.toCharArray()) {
        if (c == '(')
            stack.push(')');
        else if (c == '{')
            stack.push('}');
        else if (c == '[')
            stack.push(']');
        else if (stack.isEmpty() || stack.pop() != c)
            return false;
    }
    return stack.isEmpty();
}