class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid=true;
        int C=9;
        set<char> s;
        for(int i=0;i<C;i++){
            s.clear();
            for(int j=0;j<C;j++){
                if(board[i][j]=='.')
                    continue;
                if(s.count(board[i][j])){
                    valid=false;
                    cout<<"j="<<j<<"\n";
                    break;
                }
                else
                    s.insert(board[i][j]);
            }
            if(!valid)
                break;
        }
        if(!valid)
            return false;
        for(int j=0;j<C;j++){
            s.clear();
            for(int i=0;i<C;i++){
                if(board[i][j]=='.')
                    continue;
                if(s.count(board[i][j])){
                    valid=false;
                    break;
                }
                else
                    s.insert(board[i][j]);
            }
            if(!valid)
                break;
        }
        if(!valid)
            return false;
        for(int i=0;i<C;i+=3){
            for(int j=0;j<C;j+=3){
                s.clear();
                for(int i1=0;i1<3;i1++){
                    for(int j1=0;j1<3;j1++){
                        if(board[i+i1][j+j1]=='.')
                            continue;
                        if(s.count(board[i+i1][j+j1])){
                            valid=false;
                            break;
                        }
                        else
                            s.insert(board[i+i1][j+j1]);
                    }
                    if(!valid)
                        break;
                }
                if(!valid)
                    break;
            }
            if(!valid)
                break;
        }
        return valid;
    }
};