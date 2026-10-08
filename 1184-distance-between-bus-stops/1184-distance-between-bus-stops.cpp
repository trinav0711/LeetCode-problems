class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start==destination) return 0;
        int n=distance.size(), sum=0;
        for(int i=start;i!=destination;i=(i+1)%n) {
            sum+=distance[i];
        }
        int ans=sum;
        sum=0;
        for(int i=start-1;;--i) {
            if(i<0) i=n-1;
            sum+=distance[i];
            if(i==destination) break;
        }
        ans=min(sum, ans);
        return ans;
    }
};