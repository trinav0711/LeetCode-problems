class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size()+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=books.size();++i) {
            int tot=0, maxh=0;
            for(int j=i;j;--j) {
                tot+=books[j-1][0];
                if(tot>shelfWidth)
                    break;
                maxh=max(maxh, books[j-1][1]);
                dp[i]=min(dp[i], dp[j-1]+maxh);
            }
        }
        return dp.back();
    }
};