class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char curr : s){
            if(st.empty()){
                if(curr==')' || curr==']' || curr=='}') return false;

                st.push(curr);
            }
            else if(curr=='(' || curr=='[' ||curr=='{') st.push(curr);

            else if((st.top()=='(' && curr==')') || (st.top()=='[' && curr==']') || (st.top()=='{' && curr=='}')) st.pop();

            else{
                return false;
            }
            
            
        }

        if(st.empty()) return true;

        return false;
    }
};