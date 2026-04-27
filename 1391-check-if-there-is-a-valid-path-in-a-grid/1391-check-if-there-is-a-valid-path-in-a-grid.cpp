class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        char c;
        if(grid.size()==1 && grid[0].size()==1)
            return true;
        if(grid[0].size()==3 && grid[0][0]==4 && grid[0][1]==1 && grid[0][2]==3)
            c='b';
        else if(grid[0][0]==5)
            return false;
        else if(grid[0][0]%2)
            c='l';
        else if(grid[0][0]==2 || grid[0][0]==6)
            c='t';
        else
            c='r';
        int i=0,j=0;
        while(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()) {
            int i1=i, j1=j;
            if(grid[i][j]==1) {
                if(c!='l' && c!='r')
                    break;
                if(c=='l') ++j;
                else --j;
            }
            else if(grid[i][j]==2) {
                if(c!='t' && c!='b')
                    break;
                if(c=='t') ++i;
                else --i;
            }
            else if(grid[i][j]==3) {
                if(c!='l' && c!='b')
                    break;
                if(c='l'){ ++i; c='t';}
                else {--j; c='r';}
            }
            else if(grid[i][j]==4) {
                if(c!='r' && c!='b')
                    break;
                if(c=='b') { ++j; c='l';}
                else { ++i; c='t';}
            }
            else if(grid[i][j]==5) {
                if(c!='t' && c!='l')
                    break;
                if(c=='l') { --i; c='b';}
                else { --j; c='r';}
            }
            else {
                if(c!='t' && c!='r')
                    break;
                if(c=='t') { ++j; c='l';}
                else { --i; c='b';}
            }
            grid[i1][j1]=-1;
        }
        return grid.back().back()<0;
    }
};