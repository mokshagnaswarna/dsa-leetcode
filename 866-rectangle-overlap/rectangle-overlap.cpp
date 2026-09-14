class Solution {
public:
    bool isRectangleOverlap(vector<int>& p, vector<int>& q) {
        
        /*if((q[0]>p[0] && q[0]<p[2]) && (q[1]>p[1] && q[1]<p[3])){
            return true;
        }
        if((q[2]>p[0] && q[2]<p[2]) && (q[3]>p[1] && q[1]<p[3])){
            return true;
        }
        return false;*/
         if (q[2]<=p[0] || q[0] >= p[2]||q[3]<=p[1] ||q[1] >= p[3]){
            return false;
        }
        return true;
    }
};