class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int ctr=0;
                if(i){
                    if(board[i-1][j]>0)
                        ctr++;
                    if(j>0 && board[i-1][j-1]>0)
                        ctr++;
                    if(j<board[i].size()-1 && board[i-1][j+1]>0)
                        ctr++;
                }
                if(j>0 && board[i][j-1]>0)
                    ctr++;
                if(j<board[i].size()-1 && board[i][j+1]>0)
                    ctr++;
                if(i<board.size()-1){
                    if(board[i+1][j]>0)
                        ctr++;
                    if(j>0 && board[i+1][j-1]>0)
                        ctr++;
                    if(j<board[i].size()-1 && board[i+1][j+1]>0)
                        ctr++;
                }
                if(board[i][j] && (ctr<2 || ctr>3))
                    board[i][j]++;
                else if(!board[i][j] && ctr==3)
                    board[i][j]--;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]<0)
                    board[i][j]=1;
                else if(board[i][j]>1)
                    board[i][j]=0;
            }
        }
    }
};