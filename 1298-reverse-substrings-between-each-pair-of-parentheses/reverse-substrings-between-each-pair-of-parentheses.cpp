class Solution {
public:
    string reverseParentheses(string s) {
        int l=s.length();
        int left=-1;
        int right=-1;
        while(/*right<l*/s.find('(') != string::npos){//does the string still contains  '('
            for(int i=0;i<l;i++){
                if(s[i]=='('){
                    left=i;
                }
                
            }
            for(int i=left+1;i<l;i++){
                if(s[i]==')'){
                    right=i;
                    break;
                }
                
            }
            reverse(s.begin()+left+1,s.begin()+right);
            
            s.erase(right,1);
            s.erase(left,1);
            l=s.length();
            right=0;

        }
        return s;
    }
};