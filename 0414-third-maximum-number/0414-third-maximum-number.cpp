class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int maxx=INT_MIN, smaxx=INT_MIN, ans=INT_MIN;
        int ctr=0;
        bool s=false;
        for(int x:nums) {
            if(maxx==INT_MIN) { maxx=x; ++ctr; cout<<"max="<<maxx<<endl;}
            else if(x<maxx && smaxx==INT_MIN &&!s) {smaxx=x; s=true; ++ctr; cout<<"smaxx="<<smaxx<<endl;}
            else if(x<smaxx && ans==INT_MIN) {ans=x; ++ctr;}
        }
        return ctr<3?maxx:ans;
    }
};