/*class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats){
        int count=0;
        unordered_map<int,unordered_set<int>>mp;
        for(auto &x:reservedSeats){
            int row=x[0];
            int col=x[1];
            mp[row].insert(col);
        }
        for(int i=1;i<=n;i++){
            bool a=!mp[i].count(2) && !mp[i].count(3) && (!mp[i].count(4) && !mp[i].count(5));
            bool b=(!mp[i].count(4) && !mp[i].count(5)) && (!mp[i].count(6) && !mp[i].count(7));
            bool c=(!mp[i].count(6) && !mp[i].count(7)) && (!mp[i].count(8) && !mp[i].count(9));
            if(a&&c){
                count+=2;
            }
            else if(a||b||c){
                count++;
            }
        }
        return count;
        
    }
}; MEMORY LIMIT EXCEED
*/
/*class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats){
        unordered_map<int,int>mp;
        int count=0;
        for(auto &x:reservedSeats){
            int row=x[0];
            int col=x[1];
            if(col>=2 && col<=9){
                mp[row]=mp[row]|1<<(col-2);
            }
        }
        for(int i=1;i<=n;i++){
            int mask = 0;

            auto it = mp.find(i);

            if(it != mp.end()) {
                mask = it->second;
            }
            bool a =(mask &15)==0;    
            bool b =(mask &60)==0;    
            bool c = (mask &240)==0;
            if(a&&c){
                count+=2;
            }
            else if(a||b||c){
                count++;
            }

        }
        return count;

    }
};TIME LIMIT EXCEED
*/



class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats){
        unordered_map<int,int>mp;
        int count=2*n;
        for(auto &x:reservedSeats){
            int row=x[0];
            int col=x[1];
            if(col>=2 && col<=9){
                mp[row]=mp[row]|1<<(col-2);
            }
        }
        for(auto &x:mp){
            int row=x.first;
            int mask=x.second;

            
            bool a =(mask &15)==0;    
            bool b =(mask &60)==0;    
            bool c = (mask &240)==0;
            if(a&&c){
                count+=0;
            }
            else if(a||b||c){
                count--;
            }
            else{
                count-=2;
            }

        }
        return count;

    }
};