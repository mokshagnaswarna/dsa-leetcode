/*class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        for(int len=k;len<n;len++){
            string result="";
            for(int start=0;start<n-len;start++){
                string temp=s.substr(start,len);
                int ones=0;
                for(char &c:temp){
                    if(c=='1'){
                        ones++;
                    }
                }
                if(ones==k){

                }

            }
        }
    }
};
*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";

        for (int len = 1; len <= n; len++) {

            for (int start = 0; start + len <= n; start++) {

                string temp = s.substr(start, len);

                int ones = 0;

                for (char c : temp) {
                    if (c == '1') {
                        ones++;
                    }
                }

                if (ones == k) {

                    if (ans == "" || temp < ans) {
                        ans = temp;
                    }
                }
            }

            // Since we're checking lengths from small to large,
            // once we find an answer, this is the shortest length.
            if (ans != "") {
                return ans;
            }
        }

        return "";
    }
};