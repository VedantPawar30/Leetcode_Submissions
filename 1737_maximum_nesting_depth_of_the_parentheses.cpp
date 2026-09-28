class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi=0;

        for(char c : s){
            if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                st.pop();
            }

            maxi = max(maxi,(int)st.size());
        }

        return maxi;
    }
};