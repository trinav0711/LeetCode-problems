class Solution {
private:
    unordered_set<int> row, col, diagdiff, diagsum;
    vector<vector<string>> ans;
    void bt(vector<string>& board, int n, int lastrow) {
        if(row.size()==n && col.size()==n) {
            ans.push_back(board);
            return;
        }
        for(int i=lastrow+1;i<n;++i) {
            if(row.find(i)!=row.end()) continue;
            for(int j=0;j<n;++j) {
                if(col.find(j)!=col.end() || row.find(i)!=row.end()) continue;
                if(diagdiff.find(i-j)!=diagdiff.end()) continue;
                if(diagsum.find(i+j)!=diagsum.end()) continue;
                if(board[i][j]=='.') {
                    board[i][j]='Q';
                    row.insert(i); col.insert(j);
                    diagsum.insert(i+j); diagdiff.insert(i-j);
                    bt(board, n, i);
                    board[i][j]='.';
                    row.erase(i); col.erase(j);
                    diagsum.erase(i+j); diagdiff.erase(i-j);
                }
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string tmp="";
        for(int i=0;i<n;++i) tmp.push_back('.');
        vector<string> board(n, tmp);
        bt(board, n, -1);
        return ans;
    }
};