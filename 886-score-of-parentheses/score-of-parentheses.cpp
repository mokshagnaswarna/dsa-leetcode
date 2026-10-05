/*class Solution {
public:
    int scoreOfParentheses(string s) {
       int n=s.length();
       stack<int>st;
       int count=0;
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(st.empty()){
                ans.push_back(count);
                count=0;
            }
            st.push('(');
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                st.pop();
                count++;
            }
            else{
                continue;
            }
        }
       } 
       return count;
    }
};*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char c : s) {
            if(c == '(') {
                st.push(0);
            }
            else {
                int x = st.top();
                st.pop();

                int score = max(2 * x, 1);

                st.top() += score;
            }
        }

        return st.top();
    }
};