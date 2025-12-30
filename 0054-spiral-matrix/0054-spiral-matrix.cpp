class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0, j=0;
        int n=0, ctr=0;
        vector<vector<bool>> visit;
        for(int i=0;i<matrix.size();i++)
            visit.push_back({});
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                n++;
                visit[i].push_back(false);
            }
        }
        vector<int> travel;
        char dir='r';
        while(ctr<n){
            if(!visit[i][j]){
                travel.push_back(matrix[i][j]);
                visit[i][j]=true;
                ctr++;
            }
            if(dir=='r'){
                if(j<matrix[i].size()-1 && !visit[i][j+1])
                    j++;
                else
                    dir='d';
            }
            else if(dir=='d'){
                if(i<matrix.size()-1 && !visit[i+1][j])
                    i++;
                else
                    dir='l';
            }
            else if(dir=='l'){
                if(j>0 && !visit[i][j-1])
                    j--;
                else
                    dir='u';
            }
            else if(dir=='u'){
                if(i>0 && !visit[i-1][j])
                    i--;
                else
                    dir='r';
            }
            else
                break;
        }
        return travel;
    }
};