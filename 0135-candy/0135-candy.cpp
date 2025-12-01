class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()<2) return 1;
        vector<int> c(ratings.size(), 1);
        if(ratings[0]>ratings[1]) c[0]++;
        int i,sum;
        for(i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1])
                c[i]=max(c[i], c[i-1]+1);
        }
        i--;
        if(ratings[i]>ratings[i-1])
            c[i]=c[i-1]+1;
        for(i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                c[i]=max(c[i], c[i+1]+1);
        }
        sum=0;
        for(int candle:c) sum+=candle;
        return sum;
    }
};