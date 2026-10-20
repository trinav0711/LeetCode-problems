class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> arr{0,0};
        for(int x:bills) {
            if(x==5) {
                ++arr[0];
            }
            else if(x==10) {
                if(!arr[0]) return false;
                --arr[0];
                ++arr[1];
            }
            else {
                x-=5;
                if(arr[1]){
                    --arr[1]; x-=10;
                }
                if(arr[0]<x/5) return false;
                arr[0]=arr[0]-x/5;
            }
        }
        return true;
    }
};