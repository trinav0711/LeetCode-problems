class Solution {
private:
    int ans=INT_MAX;
    int bs(int start, int end, vector<int>& p, int h) {
        if(start>=end)
            return start;
        int less=false;
        int mid=(start+end)/2;
        cout<<"mid="<<mid<<endl;
        {
            int sum=0;
            for(int x: p) {
                sum+=(x/mid);
                if(x%mid)
                    ++sum;
            }
            if(sum<=h) {
                ans=min(ans, mid);
                cout<<"it is less\n";
                less=true;
            }
        }
        if(less)
            return bs(start, mid, p, h);
        return bs(mid+1, end, p, h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return bs(1, *max_element(piles.begin(), piles.end()), piles, h);
    }
};