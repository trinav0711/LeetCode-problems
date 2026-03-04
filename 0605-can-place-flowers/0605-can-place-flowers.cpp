class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;n && i<flowerbed.size();i++) {
            if(flowerbed[i])
                continue;
            if(i && flowerbed[i-1])
                continue;
            if(i<flowerbed.size()-1 && flowerbed[i+1])
                continue;
            flowerbed[i]=1;
            n--;
        }
        return n==0;
    }
};