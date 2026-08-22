class Solution {
public:
    void func(int ind, string &s, vector<string>& ans,
              string &digits, unordered_map<int,string>& mp) {

        if(ind == digits.size()) {
            ans.push_back(s);
            return;
        }

        string letters = mp[digits[ind] - '0'];

        for(int i = 0; i < letters.size(); i++) {

            s.push_back(letters[i]);

            func(ind + 1, s, ans, digits, mp);

            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) {
            return {};
        }

        unordered_map<int,string> mp;

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        string s;
        vector<string> ans;

        func(0, s, ans, digits, mp);

        return ans;
    }
};