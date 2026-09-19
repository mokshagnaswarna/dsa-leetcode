class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        int xi,yi;
        if(x1>xc){
            xi=x1;
        }
        else if(x2<xc){
            xi=x2;
        }
        else{
            xi=xc;
        }
        if(y1>yc){
            yi=y1;
        }
        else if(y2<yc){
            yi=y2;
        }
        else{
            yi=yc;
        }
        int d=sqrt((xi-xc)*(xi-xc)+(yi-yc)*(yi-yc));
        if(d<=radius){
            return true;
        }
        return false;
    }
};