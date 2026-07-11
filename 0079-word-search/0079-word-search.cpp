class Solution {
private:
    bool recur(vector<vector<char>>& grid, string& word, int i, int j) {
        if(word.empty()) return true;
        char c=grid[i][j];
        if(c!=word.back()) return false;
        word.pop_back();
        if(word.empty()) return true;
        grid[i][j]=' ';
        if(j<grid[i].size()-1 && grid[i][j+1]!=' ' && recur(grid, word, i, j+1))
            return true;
        if(j && grid[i][j-1]!=' ' && recur(grid, word, i, j-1))
            return true;
        if(i && grid[i-1][j]!=' ' && recur(grid, word, i-1, j))
            return true;
        if(i<grid.size()-1 && grid[i+1][j]!=' ' && recur(grid, word, i+1, j))
            return true;
        word.push_back(c);
        grid[i][j]=c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        reverse(word.begin(), word.end());
        for(int i=0;i<board.size();++i) {
            for(int j=0;j<board[i].size();++j) {
                if(recur(board, word, i, j))
                    return true;
            }
        }
        return false;
    }
};