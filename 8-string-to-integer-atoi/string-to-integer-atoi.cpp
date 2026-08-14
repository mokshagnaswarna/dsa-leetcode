class Solution {
public:
    int myAtoi(string s) {
        int l=s.length();
        int ans=0;
        int sign=1;
        int i=0;
        while(i<l && s[i]==' '){
            i++;
        }
        if(i<l && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<l && s[i]=='+')i++;
        while(i<l && s[i]>='0' &&s[i]<='9'){
            int digit=s[i]-'0';
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7)) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            ans=ans*10+digit;
            i++;
        }
            
            
        
        return ans*sign;
    }
};