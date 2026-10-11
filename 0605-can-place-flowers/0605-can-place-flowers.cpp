class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size() && n;++i){
            if(flowerbed[i])
                continue;
            bool okay=true;
            if(i && flowerbed[i-1])
                okay=false;
            if(i<flowerbed.size()-1 && flowerbed[i+1])
                okay=false;
            if(okay){
                --n;
                flowerbed[i]=1;
            }
        }
        return n==0;
    }
};