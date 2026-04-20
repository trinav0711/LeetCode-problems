class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(), m=maze[0].size();
        queue<pair<int,int>> q;
        int ctr=0;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                auto& [i,j] = q.front();
                if((!i || i==n-1 || !j || j==m-1) && ctr) {
                    return ctr;
                }
                if(i && maze[i-1][j]!='+') {
                    q.push({i-1, j});
                    maze[i-1][j]='+';
                }
                if(i<n-1 && maze[i+1][j]!='+') {
                    maze[i+1][j]='+';
                    q.push({i+1,j});
                }
                if(j && maze[i][j-1]!='+') {
                    maze[i][j-1]='+';
                    q.push({i,j-1});
                }
                if(j<m-1 && maze[i][j+1]!='+') {
                    maze[i][j+1]='+';
                    q.push({i,j+1});
                }
                q.pop();
            }
            ++ctr;
        }
        return -1;
    }
};