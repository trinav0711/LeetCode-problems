class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
            }
        }
        for(int j=0;j<matrix.size()/2;j++){
            for(int i=0;i<matrix.size();i++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[i][matrix.size()-1-j];
                matrix[i][matrix.size()-1-j]=tmp;
            }
        }
    }
};