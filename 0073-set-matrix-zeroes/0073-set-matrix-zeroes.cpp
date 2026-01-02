class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col_done, row_done;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(!matrix[i][j]){
                    row_done.insert(i);
                    col_done.insert(j);
                }
            }
        }
        for(int row:row_done){
            for(int j=0;j<matrix[0].size();j++)
                matrix[row][j]=0;
        }
        row_done.clear();
        for(int col:col_done){
            for(int i=0;i<matrix.size();i++)
                matrix[i][col]=0;
        }
        col_done.clear();
    }
};