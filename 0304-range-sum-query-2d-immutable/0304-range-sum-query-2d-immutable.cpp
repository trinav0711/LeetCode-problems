class NumMatrix {
private:
    vector<vector<int>> row;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(const auto& v:matrix) {
            vector<int> tmp{0};
            for(const auto x:v)
                tmp.push_back(tmp.back()+x);
            row.push_back(tmp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        while(row1<=row2) {
            sum+=(row[row1][col2+1]-row[row1][col1]);
            ++row1;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */