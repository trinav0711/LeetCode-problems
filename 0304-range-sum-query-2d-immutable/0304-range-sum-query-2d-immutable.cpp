class NumMatrix {
private:
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<=matrix.size();++i) {
            vector<int>tmp(matrix[0].size()+1, 0);
            v.push_back(tmp);
        }
        for(int i=1;i<=matrix.size();++i) {
            for(int j=1;j<=matrix[0].size();++j) {
                v[i][j]=matrix[i-1][j-1]+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return v[row2+1][col2+1]-v[row1][col2+1]-v[row2+1][col1]+v[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */