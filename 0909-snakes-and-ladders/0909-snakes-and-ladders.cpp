class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, pair<int,int>> m; int n=board.size();
        {
            int ctr=1, i=n-1; bool left=true;
            while(i>=0) {
                if(left) {
                    for(int j=0;j<n;++j)
                        m[ctr++]=make_pair(i, j);
                }
                else {
                    for(int j=n-1;j>=0;--j)
                        m[ctr++]=make_pair(i, j);
                }
                left=!left;
                --i;
            }
        }
        unordered_set<int> visit;
        queue<int> q;
        q.push(1);
        int ans=0;
        if(m.find(56)!=m.end()) cout<<"m[56]="<<m[56].first<<" "<<m[56].second<<endl;
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                int curr=q.front();
                if(curr==n*n) return ans;
                visit.insert(curr);
                for(int i=curr+1;i<=min(curr+6, n*n);++i) {
                    int dst=board[m[i].first][m[i].second];
                    if(dst==-1) dst=i;
                    if(dst==n*n) return ans+1;
                    if(visit.find(dst)==visit.end()) {
                        visit.insert(dst);
                        q.push(dst);
                    }
                }
                q.pop();
            }
            ++ans;
        }
        return -1;
    }
};