class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;
        while(n>0){
            arr.push_back(n%10);
            n=n/10;
        }
        sort(arr.begin(),arr.end(),greater<int>());
        return arr[0]*arr[1];
    }
};