class Solution {
public:
    bool solve(int row,int col,vector<string>&board,int n){
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q'){ //row
                return false;
            }
        }
        for(int i=0;i<n;i++){ //col
            if(board[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){//right diagnal
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){  //left diagnal
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void func(int row,vector<vector<string>>&ans,vector<string>&board,int n){
        if(row==n){
            ans.push_back({board});
            return;
        }
        for(int j=0;j<n;j++){
            
            if(solve(row,j,board,n)){
                board[row][j]='Q';
                func(row+1,ans,board,n);
                board[row][j]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        func(0,ans,board,n);
        return ans;
    }
};